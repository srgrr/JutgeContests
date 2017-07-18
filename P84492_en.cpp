#include <bits/stdc++.h>
using namespace std;
const int maxn = 1009;
const int inf = 1e9;
string g;
int n, r, p, s, dp[maxn][3];

int char2val(char x) {
  if(x == 'R') return 0;
  if(x == 'P') return 1;
  return 2;
}

int table[3][3] = {
  //      R   P   S
  /*R*/  {1,  0,  2},
  /*P*/  {2,  1,  0},
  /*S*/  {0,  2,  1}
};

int compute_score(int me, int him) {
  return table[me][him];
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  while(cin >> g >> r >> p >> s) {
    n = int(g.size());
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    for(int kind=0; kind<3; ++kind) {
      for(int i=1; i<=n; ++i) {
        dp[i][kind] = compute_score(kind, char2val(g[i-1])) + dp[i-1][kind];
      }
    }
    int ans = 0;
    for(int rr=r; rr<=n; ++rr) {
      for(int pp=rr+p; pp<=n; ++pp) {
        int ss = n - pp;
        if(ss >= s) {
          int rcost = dp[rr][0];
          int pcost = dp[pp][1] - dp[rr][1];
          int scost = dp[n][2] - dp[pp][2];
          ans = max(ans, rcost + pcost + scost);
        }
      }
    }
    cout << ans << endl;
  }

}
