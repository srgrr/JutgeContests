#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector< ll > vll;
typedef vector< vll > vvll;
typedef pair<int, int> pii;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< bool > vb;
typedef vector< vb > vvb;
const ll inf = 1e14;
const int maxn = 1003;

const int dx[4] = {-1,  1,  0,  0};
const int dy[4] = { 0,  0, -1,  1};
char g[maxn][maxn];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int r, c, h;
  while(cin >> r >> c >> h) {
    pii start(-1, -1), goal(-1, -1);
    for(int i=0; i<r; ++i) {
      for(int j=0; j<c; ++j) {
        cin >> g[i][j];
        if(g[i][j] == 'S') start = {i, j};
        if(g[i][j] == 'T') goal  = {i, j};
      }
    }
    vvll dis(r, vll(c, inf));
    dis[start.first][start.second] = 0;
    priority_queue< pair<ll, pii>,
                    vector< pair<ll, pii> >,
                    greater< pair<int, pii> > > Q;
    Q.push({0, start});
    while(!Q.empty()) {
      pii u = Q.top().second;
      Q.pop();
      if(dis[u.first][u.second] > dis[goal.first][goal.second]) continue;
      for(int k=0; k<4; ++k) {
        int oi = u.first + dx[k];
        int oj = u.second + dy[k];
        if(oi >= 0 && oi < r && oj >= 0 && oj < c) {
          ll edge_cost = g[oi][oj] == '#' ? h+1ll : 1ll;
          if(dis[u.first][u.second] + edge_cost < dis[oi][oj]) {
            dis[oi][oj] = dis[u.first][u.second] + edge_cost;
            Q.push({dis[oi][oj], {oi, oj}});
          }
        }
      }
    }
    cout << dis[goal.first][goal.second] << endl;
  }
}
