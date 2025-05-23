#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int maxn = 241;

int dp[maxn][2 * maxn + 2], va[maxn], vb[maxn];
string a, b;

int calc(int i, int tb) {
  if (i == a.size()) {
    if (tb == 240) {
      return 0;
    }
    return -999999;
  }
  int rem = abs(240 - tb);
  if (a.size() - i < rem) {
    return -999999;
  }
  int& cur = dp[i][tb];
  if (cur == -1) {
    if (va[i] == 1) {
      cur = max(cur, 1 + calc(i + 1, tb + 1));
    }
    if (vb[i] == 1) {
      cur = max(cur, 1 + calc(i + 1, tb - 1));
    }
    cur = max(cur, calc(i + 1, tb));
  }
  return cur;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  while (cin >> a >> b) {
    for (int i = 0; i < a.size(); ++i) {
      va[i] = a[i] == '1';
      vb[i] = b[i] == '1';
    }
    memset(dp, 0xff, maxn * (2 * maxn + 2) * sizeof(int));
    cout << calc(0, 240) / 2 << endl;
  }
}
