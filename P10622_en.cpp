#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <cstdlib>
#include <set>
#include <cmath>
#include <map>
#include <algorithm>
#include <limits>
#include <stack>
using namespace std;
#define legal(i,j) i>=0 and i<n and j>=0 and j<n
#define epsilon 1e-9
#define epsok(a,b) abs(a-b)<epsilon
#define x first
#define y second
typedef pair<double,double> point;

/*
    La resposta era un triangle.
*/

double tryhard(point* v){
    double v1[2] = {
        v[1].first-v[0].first,
        v[1].second-v[0].second
    };
    double v2[2] = {
        v[2].first-v[0].first,
        v[2].second-v[0].second
    };
    double cp = ( v1[0]*v2[1] - v1[1]*v2[0] );
    return abs(cp / sqrt( (v[0].first-v[1].first)*(v[0].first-v[1].first) + (v[0].second-v[1].second)*(v[0].second-v[1].second) ));
}

int main(){
    #ifdef _LOCAL
    freopen("input.txt","r",stdin);
    #endif // _LOCAL
    cout.setf(ios::fixed);
    cout.precision(4);
    point v[3];
    while(cin >> v[0].first >>  v[0].second >> v[1].first >> v[1].second >> v[2].first >> v[2].second){
            point t1[] = { v[0],v[1],v[2] };
            point t2[] = { v[0],v[2],v[1] };
            point t3[] = { v[1],v[2],v[0] };
            double mind = numeric_limits<double>::max();
            mind = min(mind,tryhard(t1));
            mind = min(mind,tryhard(t2));
            mind = min(mind,tryhard(t3));
            cout << mind << endl;
    }
}