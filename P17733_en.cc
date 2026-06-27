#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

/*
    Ordenem les hores on ens anem a dormir (s) i ens despertem respectivament (t)
    
    per una hora s_i podem tenir que

    t_0 <= t_1 <= ... < s_i <= t_j <= t_j+1 <= ... <= t_m

    Sabent aixo, manenint prefix sums i dos punters que anem desplacant podem saber
    quantes hores de llevar-se son anteriors a s_i i quantes en son posteriors

    Les hores anteriors contribueixen h - s_i + t_j
    Les hores posteriors contribueixen t_j - s_i

    Mantenint sumes de sufix i prefix es suficient.

    Problema especialment cabro amb els long long. Feia anys que no en feia d'aquests i m'ha costat diversos intents.
*/

void solve(int h, int n, int m) {
    vector< ll > s(n), t(m);
    for (ll &x: s) {
        cin >> x;
    }
    for (ll &x: t) {
        cin >> x;
    }
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    ll pref = 0, suf = 0;
    for (ll x: t) {
        pref += x;
    }
    double ans = 0.0;
    int j = 0;
    for (int x: s) {
        while (j < t.size() && t[j] < x) {
            suf -= t[j];
            pref += t[j];
            ++j;
        }
        double l = j, r = m - j;
        double prefs = 1.0 * pref + l * (h - x);
        double sufs  = 1.0 * suf - r * x;
        ans += 1.0 * (prefs + sufs) / (double(n) * m);
    }
    cout << ans << endl;
}

int main() {
    cout << fixed;
    cout << setprecision(4);
    int h, n, m;
    while (cin >> h >> n >> m) {
        solve(h, n, m);
    }
}
