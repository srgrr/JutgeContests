#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>
using namespace std;
typedef pair< double, double > point;

/*
    Existeix un algorisme de divide and conquer
    que permet resoldre aixo en nlogn del qual no en
    tinc ni idea de per que funciona ara mateix.
*/

point S[100009];
point T[100009];
double dist(int i, int j){
    return sqrt( (S[i].first-S[j].first)*(S[i].first-S[j].first) + (S[i].second-S[j].second)*(S[i].second-S[j].second) );
}

double distt(int i, int j){
    return sqrt( (T[i].first-T[j].first)*(T[i].first-T[j].first) + (T[i].second-T[j].second)*(T[i].second-T[j].second) );
}

bool cmpy(const point& a, const point& b){
    return a.second < b.second;
}

double run(int l, int r){
    if(r-l <= 0) return numeric_limits<double>::max();
    if(r-l == 1) return dist(l,r);
    int m = (l+r)/2;
    double x = S[m].first;
    double d1 = run(l,m);
    double d2 = run(m,r);
    double md = min(d1,d2);
    double d3 = md;
    int ys=0;
    for(int i=l; i<=r; ++i)
        if( abs(S[i].first-x) < md ) T[ys++] = S[i];
    sort(T,T+ys,cmpy);
    for(int i=0; i<ys; ++i)
        for(int j=i+1; j<ys and T[j].second-T[i].second<md; ++j) d3 = min(d3, distt(i,j));

    return min(d1, min(d2,d3));
}

int main(){
    cout.setf(ios::fixed);
    cout.precision(5);
    #ifdef _LOCAL
    freopen("input.txt","r",stdin);
    #endif
    int k=0;
    while(cin >> S[k].first >> S[k].second) ++k;
    sort(S,S+k);
    cout << run(0,k-1) << endl;
}