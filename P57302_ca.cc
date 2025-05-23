#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
  int n, m;
  while (cin >> n >> m) {
    vector< vector< int > > g(n, vector< int >());
    for (int i = 0; i < m; ++i) {
      int u, v; cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    vector< bool > vis(n, false);
    vector< int > col(n, -1);
    queue< int > q;
    bool bi = true;
    for (int r = 0; r < n && bi; ++r) {
      if (vis[r]) continue;
      col[r] = 0;
      q.push(r);
      while (!q.empty() && bi) {
        int u = q.front();
        q.pop();
        if (!vis[u]) {
          vis[u] = true;
          for (int adj: g[u]) {
            if (col[u] == col[adj]) bi = false;
            else {
              col[adj] = 1 - col[u];
              q.push(adj);
            }
          }
        }
      }
    }
    cout << (bi ? "SI" : "NO") << endl;
  }
}
