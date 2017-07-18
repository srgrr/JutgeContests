#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int fiblen = 92;
const int maxn = 1009;
ll fib[fiblen];
ll l;
int m;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  fib[0] = fib[1] = 1ll;
  for(int i=2; i<fiblen; ++i) {
    fib[i] = fib[i-1] + fib[i-2];
  }
  while(cin >> l >> m) {
    ll rem = l;
    int cur_fib = fiblen-1;
    for(int i=0; i<m && rem > 0; ++i) {
      while(fib[cur_fib] > rem) --cur_fib;
      rem -= fib[cur_fib];
    }
    cout << rem << endl;
  }
}
