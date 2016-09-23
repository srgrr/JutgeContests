#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
struct pt {
  ll x, y;
  pt() {}
  pt(ll xx, ll yy) : x(xx), y(yy) {}
};
pt operator-(const pt& a, const pt&b) {
  return pt(a.x-b.x, a.y-b.y);
}
typedef vector<pt> vp;
typedef vector<int> vi;
 
ll det(const pt& u, const pt& v) {
  return u.x * v.y - u.y * v.x;
}
 
vi aligned(const vp& V, int a, int b) {
  vi r(0);
  for (size_t i = 0; i < V.size(); ++i) {
    if (det(V[b]-V[a], V[i]-V[a]) == 0)
      r.push_back(i);
  }
  return r;
}
 
int main() {
  for (int n; cin >> n;) {
    vp V(n);
    for (pt& p : V) cin >> p.x >> p.y;
    while (1) {
      int x = rand()%n;
      int y = rand()%n;
      while (x == y) y = rand()%n;
      vi a = aligned(V, x, y);
      if ((int)a.size() > (n-1)/5) {
        cout << a.size();
        for (int i : a)
          cout << "  " << V[i].x << " " << V[i].y;
        cout << endl;
        break;
      }
    }
  }
}