#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;

vi prefix_table(string& s) {
  int n = int(s.size());
  vi ret(n+1);
  ret[0] = -1;
  int i = 0, j = -1;
  while(i<n) {
    while(j>=0 && s[i] != s[j]) j = ret[j];
    ++i, ++j;
    ret[i] = j;
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  string s;
  while(cin >> s) {
    string srev = s;
    reverse(srev.begin(), srev.end());
    vi pref = prefix_table(srev);
    int i = 0, j = 0;
    while(i < int(s.size())) {
      while(j >= 0 && s[i] != srev[j]) j = pref[j];
      ++i, ++j;
    }
    cout << j << endl;
  }
}
