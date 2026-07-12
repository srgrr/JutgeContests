#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;
using ll = long long;
const ll LIM = 1000000000;
ll t;
vector< ll > v(6);
vector< unordered_set< ll > >dp((1 << 6), unordered_set< ll >());

/*
    No se que collons feia la solucio de referencia pero m'ha costat bastant ficar-lo.
    Es una DP de bitmasks prou estandar, per exemple 0b101101
    Es pot construir a partir de 101000 | 000101, mirant tots els possibles resultats que
    es poden aconseguir amb les mascares independents i combinant-los seguint les normes
    (no under/overflow + no divisio per zero)
*/

void solve() {
    for (auto &s: dp) s.clear();
    for (int i = 0; i < 6; ++i) {
        dp[1 << i].insert(v[i]);
    }
        for (int i = 1; i < (1 << 6); ++i) {
            for (int j = 1; j < (1 << 6); ++j) {
                if ((i & j) != j) continue;
                int current = j;
                int other = (i ^ j);
                if (current > other) continue;
                    for (ll vl: dp[current]) {
                        for (ll vr: dp[other]) {
                            if (vl + vr >= 0 && vl + vr <= LIM) dp[i].insert(vl + vr);
                            if (vl - vr >= 0 && vl - vr <= LIM) dp[i].insert(vl - vr);
                            if (vr - vl >= 0 && vr - vl <= LIM) dp[i].insert(vr - vl);
                            if (vl * vr >= 0 && vl * vr <= LIM) dp[i].insert(vl * vr);
                            if (vr != 0 && vl % vr == 0 && vl/vr >= 0 && vl/vr <= LIM) dp[i].insert(vl/vr);
                            if (vl != 0 && vr % vl == 0 && vr/vl >= 0 && vr/vl <= LIM) dp[i].insert(vr/vl);
                        }
                    }
            }
        }
    pair<ll, ll> ans = {abs(t - *(dp[1].begin())), -*(dp[1].begin())};

    for (int i = 1; i < (1 << 6); ++i) {
        for (ll x: dp[i]) {
            ans = min(ans, {abs(t - x), -x});
        }
    }

    cout << -ans.second << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    while (cin >> t) {
        for (ll &x: v) cin >> x;
        solve();
    }
}
