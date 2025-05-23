#include <iostream>
#include <vector>
using namespace std;

int main() {
  cout.setf(ios::fixed);
  cout.precision(4);
  vector< double > ans(26, 0.0);
  for (int i = 1; i <= 9; ++i) {
    for (int j = i + 1; j <= 9; ++j) {
      for (int k = j + 1; k <= 9; ++k) {
        for (int l = 1; l <= i + j + k; ++l) {
          ans[l] += 1. / 84.;
        }
      }
    }
  }
  int s;
  while (cin >> s) {
    cout << ans[s] << endl;
  }
}
