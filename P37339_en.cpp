#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
const int maxn = 10000;
int n, m, dfsLow[maxn], dfsNum[maxn], root, cur;
vvi g;
set<ii> ans;
bool vis[maxn];

void dfs(int u, int par = -1) {
    if(vis[u]) return;
    vis[u] = true;
    dfsNum[u] = cur++;
    dfsLow[u] = dfsNum[u];
    int chilCount = 0;
    for(int adj : g[u]) {
        if(not vis[adj]) dfs(adj, u);
        if(dfsLow[adj] > dfsNum[u])
            ans.insert({min(u, adj), max(u, adj)});
        
    }
    
    for(int v : g[u]) {
        if(v != par) {
            dfsLow[u] = min(dfsLow[u], dfsLow[v]);
        }
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> n >> m) {
        ans.clear();
        g.clear();
        g = vvi(n, vi());
        memset(vis, false, sizeof(bool)*n);
        for(int i=0; i<m; ++i) {
            int u,v; cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for(int i=0; i<n; ++i) {
            if(not vis[i]) {
                root = i;
                dfs(i);
            }
        }
        cout << (int)ans.size() << endl;
        bool first = true;
        for(ii edg : ans) {
            if(not first) cout << "  ";
            first = false;
            cout << edg.first << " " << edg.second;
        }
        cout << endl << string(10, '-') << endl;
    }
}