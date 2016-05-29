   
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

/*
    La idea es definir una funcio f(n) = nombres d'arbres amb n nodes
    i calcular els valors fent servir programacio dinamica.
*/

vector<int> primes;
ll DP[502];

ll fastpow(ll b, ll e) {
    if(e==0) return 1LL;
    if(e==1) return b;
    ll rec = fastpow(b*b, e/2);
    if(e%2) return b*rec;
    return rec;
}

ll solve(int n) {
    if(DP[n]==-1) {
        DP[n] = 0;
        for(int i=0; i<primes.size(); ++i) {
            if((n-1)%primes[i]==0) {
                ll ways = solve(primes[i]);
                ll ktrees = (n-1)/primes[i];
                ktrees = (ktrees+1)/2;
                DP[n] += fastpow(ways,ktrees);
            }
        }
    }
    return DP[n];
}

int main() {
    memset(DP, -1, 502*sizeof(ll));
    DP[0] = DP[1] = DP[2] = 1;
    vector<bool> sv(600,true);
    sv[0] = sv[1] = false;
    for(int i=2; i<600; ++i)
        if(sv[i]) {
            primes.push_back(i);
            for(int j=i+i; j<600; j+=i) sv[j] = false;
        }
        
    int n;
    while(cin >> n)
        cout << solve(n) << endl;
}