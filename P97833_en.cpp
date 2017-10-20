#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
const int maxp = 52;

void fraction_set(unordered_set< ll >& fractions, ll cur, ll factor, ll limit) {
  if(cur > limit) return;
  fractions.insert(cur);
  if(factor < 2) {
    fraction_set(fractions, 2ll*cur, 0,  limit),
    fraction_set(fractions, cur, 2,  limit);
  } 
  else if(factor < 3) {
    fraction_set(fractions, 3ll*cur, 2,  limit),
    fraction_set(fractions, cur, 3,  limit);
  }
  else {
    fraction_set(fractions, 5ll*cur, 3,  limit);
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  ll m;
  while(cin >> m) {
    ll n = m;
    while(n%2ll == 0ll) n /= 2ll;
    while(n%3ll == 0ll) n /= 3ll;
    while(n%5ll == 0ll) n /= 5ll;
    unordered_set< ll > fractions;
    ll limit = m-1ll;
    fraction_set(fractions, n, 0, limit);
    ll ans = fractions.size();
    for(ll x : fractions) {
      if(!fractions.count(m - x)) ++ans;
    }
    cout << ans << endl;
  }
}
