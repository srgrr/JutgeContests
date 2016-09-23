#include <bits/stdc++.h>
using namespace std;
struct edge {
    int how, adj;
};

int n, root;
vector< vector<edge > > g;

int dfs(int u, int par) {
    int ret = 1;
    for(int i=0; i<g[u].size(); ++i) {
        edge& adj = g[u][i];
        if(adj.adj != par) {
            int rec = dfs(adj.adj, u);
            adj.how = rec;
            ret += rec;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
        while(cin >> n) {
            n *= 8;
            g = vector< vector< edge > >(n, vector<edge>());
            root = rand()%n;
            for(int i=1; i<n; ++i) {
                int u,v; cin >> u >> v;
                g[u].push_back({0, v});
                g[v].push_back({0, u});
            }
            dfs(root, -1);
            int tot = 0;
            for(int i=0; i<n; ++i) {
                if(g[i].size() == 1) continue;
                for(edge adj : g[i]) {
                    if(adj.how > 0 and adj.how%8 == 0 and (n - adj.how)%8 == 0) ++tot;
                    //if(i<adj.adj) cout << adj.how << " " << (n-adj.how) << endl;
                }
            }
            if(tot == n/8 - 1) cout << "yes" << endl;
            else cout << "no" << endl;
        }
}