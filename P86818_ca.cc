#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n;
  while (cin >> n) {
    vector< int > x(n);
    vector< int > y(n);
    for (int i = 0; i < n; ++i) {
      cin >> x[i] >> y[i];
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    long long ans = 0ll, sx = 0, sy = 0;
    for (int i = 0; i < n; ++i) {
      ans += 1ll * i * x[i] - sx;
      ans += 1ll * i * y[i] - sy;
      sx += x[i], sy += y[i];
    }
    cout << ans << endl;
  }
}
