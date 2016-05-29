#include <iostream>
#include <cmath>
using namespace std;
typedef long long int ll;
const ll mod = 1e8+7;

int main() {
    ll n;
    ll pow2mod[100003];
    pow2mod[0] = 1;
    for(ll i=1; i<100003; ++i)
        pow2mod[i] = (2*pow2mod[i-1])%mod;
    while(cin >> n){
        ll h = 0;
        for(ll i=0; i<n; ++i) {
            double r; cin >> r;
            if(fabs(r-0.5)<1e-9) ++h;
        }
        ll ans = 0;
        ans = (pow2mod[h]-1)%mod;
        ans = (ans+((pow2mod[h]-1)*(pow2mod[n-h]-1))%mod)%mod;
        cout << ans%mod << endl;
        
    }
}