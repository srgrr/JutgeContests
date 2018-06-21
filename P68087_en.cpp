/*
 Author:    sergiorg
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;

/*
  Programacio dinamica amb mascara de bits optimitzada
  fins vomitar, poc a dir. El paper que fa es evitar comptar
  un subconjunt maximal mes dun cop:

  000 -> 001 -> 011
  000 -> 010 -> 011

  Aixo faria que comptessim el subset 011 dos cops.

  Gracies a aquest problema he descobert que amb grafs petits pots
  representar les adjacencies com una mascara de bits, i comprovar
  si dos vertexs tenen en comu algun vei en O(1) fent un AND.

  La solucio esperada se suposa que es un backtracking no massa original
  ni massa orientat a rascar temps segons l'organitzador del concurs.
*/

int n, ans = 0, g[21], dp[1 << 21];


inline void calc(int mask) {
  if(dp[mask]) return;
  dp[mask] = 1;
  bool maximal = true;
  for(int toadd = 0; toadd < n; ++toadd) {
    if(!(mask & (1<<toadd))) {
      bool valid = true;
      if(g[toadd] & mask) valid = false;
      if(valid) maximal = false, calc(mask | (1<<toadd));
    }
  }
  if(maximal) {
    //cout << mask << endl;
    ++ans;
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  while(scanf("%d", &n) == 1) {
    memset(dp, 0x00, sizeof(int) * (1 << n));
    memset(g, 0x00, sizeof(g));
    char s[1231];
    for(int i = 0; i < n; ++i) {
      scanf("%s", s);
      for(int j = 0; j < n; ++j) {
        g[i] |= (s[j] == 'D') * (1 << j);
        g[j] |= (s[j] == 'D') * (1 << i);
      }
    }
    ans = 0;
    calc(0);
    printf("%d\n", ans);
  }
}
