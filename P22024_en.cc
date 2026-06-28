#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF (1e6 + 9)
#define ODD(u) (u)
#define EVEN(u) (n + u)

vector< int > dis(vector< vector< int > >& g, vector< int > sources) {
    int n = g.size();
    queue< int > q;
    vector< int > ret(n, INF);
    vector< bool > vis(n, false);

    for (int x: sources) {
        q.push(x);
        ret[x] = 0;
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (int adj: g[u]) {
            q.push(adj);
            ret[adj] = min(ret[adj], ret[u] + 1);
        }
    }

    return ret;
}

void solve(int n, int m, int sn, int su, int t) {
    vector< vector< int > > g(2 * n, vector< int >());
    while (m--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[EVEN(u)].push_back(ODD(v));
        g[ODD(u)].push_back(EVEN(v));
        g[EVEN(v)].push_back(ODD(u));
        g[ODD(v)].push_back(EVEN(u));
    }
    vector< int > dn_even = dis(g, {EVEN(sn)});
    vector< int > dn_odd = dis(g, {ODD(sn)});
    for (int &x: dn_odd) ++x;
    vector< int > du = dis(g, {EVEN(su)});

    bool can = dn_even[EVEN(t)] < du[EVEN(t)];
    can |= dn_even[ODD(t)] < du[ODD(t)];
    can |= dn_odd[EVEN(t)] < du[EVEN(t)];
    can |= dn_odd[ODD(t)] < du[ODD(t)];

    cout << (can ? "yes" : "no") << endl;
}

int main() {
    int n, m, sn, su, t;
    while (cin >> n >> m >> sn >> su >> t) {
        --sn, --su, --t;
        solve(n, m, sn, su, t);
    }
}
