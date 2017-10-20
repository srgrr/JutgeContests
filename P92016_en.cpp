#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;

ll mod2(ll x) {
  x %= 2ll;
  if(x<0) x += 2ll;
  return x;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  while(scanf("%d", &n) == 1) {
    ll sums[2] = {0ll, 0ll};
    for(int i=0; i<n; ++i) {
      ll x;
      scanf("%lld", &x);
      ll bucket = mod2(x);
      sums[1 - bucket] = max(sums[1 - bucket], x + sums[bucket]);
    }
    printf("%lld\n", max(sums[0], sums[1]));
  }
}
