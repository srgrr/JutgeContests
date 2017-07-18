#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector< ll > vll;
const int maxn = 1e5 + 9;
int v[maxn], suitable[maxn];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n, p;
  while(scanf("%d %d", &n, &p) == 2) {
    ll need = 0ll;
    for(int i=0; i<n; ++i) {
      scanf("%d", v+i);
      need += ll(v[i]);
    }
    need /= ll(n);
    queue< int > transfers;
    int suit_index = 0;
    for(int i=0; i<n; ++i) {
      transfers.push(i);
      if(v[i] > need) {
        suitable[suit_index++] = i;
      }
    }
    ll ans = 0ll;
    suit_index = 0;
    for(int i=0; i<n; ++i) {
      while(v[i] < need) {
        int best = suitable[suit_index];
        int avail = v[best] - need;
        int must  = need - v[i];
        int got   = min(avail, must);
        v[i] += got;
        v[best] -= got;
        int costisimo = 0;
        int l = i, r = best;
        if(l>r) swap(l, r);
        int absdist = r-l;
        while(!transfers.empty() && transfers.front() < l) transfers.pop();
        while(!transfers.empty() && transfers.front() >= l && transfers.front() < r) {
          ++costisimo;
          transfers.pop();
        }
        ans += ll(absdist)*ll(got) + ll(costisimo)*ll(p);
        if(v[best] == need) ++suit_index;
      }
    }
    cout << ans << "\n";
  }
}
