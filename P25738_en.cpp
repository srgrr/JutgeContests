#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <sstream>
#include <set>
#include <map>
#include <queue>
#define inf 1000000000
using namespace std;
typedef unsigned long long ull;

/*
    Programacio dinamica pel que sembla ser.
    Ni idea de que anava...
*/

int dp(vector<ull>& times,vector<ull>& DP,int act){
    if(DP[act] == 0){
        DP[act] = 1;
        int mf = 0;
        for(int i = act+1 ; i < times.size() ; ++i){
            if(times[act] < times[i] and times[i]-times[act]>=10) mf = max(mf,dp(times,DP,i));
        }
        DP[act] += mf;
    }
    return DP[act];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int m;
        cin >> m;
        vector< ull > v(m);
        for(int i = 0 ; i < m ; ++i) cin >> v[i];
        vector< ull > DP(m,0); //el -1 es un 1 (solo pegamos al tio i)
        int mx = 0;
        for(int i = 0 ; i < m ; ++i)
            mx = max(mx,dp(v,DP,i));
        cout << mx << endl;
    }
}