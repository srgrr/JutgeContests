#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int hasta =  1000;

ll npow(ll x) {
    ll ret = 1LL;
    while(ret <= x) ret = (ret << 1LL);
    return ret;
}

int main() {
    ll x;
    while(cin >> x)
        cout << npow(x)-1LL << endl;
}