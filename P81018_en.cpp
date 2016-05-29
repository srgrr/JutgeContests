#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
const int inf = 1e9 + 7;

int busca(vi& v, int izq, int der, int referencia) {
    if(izq<=der) {
        int m = (izq+der)/2;
        int val = v[m] - referencia;
        if(val >= 2048) return min(m, busca(v, izq, m-1, referencia));
        return busca(v, m+1, der, referencia);
    }
    return inf;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    while(cin >> n) {
        vi v(n+1,0);
        for(int i=1; i<=n; ++i) {
            cin >> v[i];
            if(v[i]&(v[i]-1)) v[i]  = 0;
            v[i] += v[i-1];
        }
        ll ans = 0;
        for(int i=1; i<=n; ++i) {
            int suma_izq = v[i-1];
            int derecha = busca(v, i, n, suma_izq);
            if(derecha != inf)
                ans += ll(n-derecha+1);
        }
        cout << ans << endl;
    }
}