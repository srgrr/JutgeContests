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
using ld = long double;

/*
  Aquest problema era una trolejada. Resulta que nomes hi ha dues
  parelles que compleixen aquesta propietat (les de l'enunciat).

  De totes maneres, el que he fet ha sigut provar amb tots els cubs
  entre 1 i 10^18 (no n'hi ha tants) i mirar si x + 1 o x - 1 eren
  quadrats fent el porc amb sqrt (no sabia com comprovarho amb binary search sense donar overflow, potser hardcodejant el upper bound a 10^9 ?)
*/

bool perf_sq(ll x) {
  ll sq = sqrt(ld(x));
  for(ll c = max(0ll, sq - 5ll); c <= min(x, sq + 5ll); ++c) {
    if(c * c == x) return true;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  vll pairs;
  for(ll i = 1ll; i <= 1000000ll; ++i) {
    ll cube = i * i * i;
    if(perf_sq(cube - 1ll)) {
      pairs.push_back(cube - 1ll);
    }
    if(perf_sq(cube + 1ll)) {
      pairs.push_back(cube);
    }
  }
  sort(pairs.begin(), pairs.end());
  ll l, r;
  while(cin >> l >> r) {
    int ixl = lower_bound(pairs.begin(), pairs.end(), l) - pairs.begin();
    int ixr = lower_bound(pairs.begin(), pairs.end(), r) - pairs.begin();
    cout << ixr - ixl << endl;
  }
}
