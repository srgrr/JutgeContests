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
int inf = 1e9;

/*
  Aqui, amb provar totes les combinacions n'hi havia prou
*/

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  string s;
  while(cin >> s) {
    int low = inf, up = 0;
    int v = atoi(s.c_str());
    int n = int(s.size());
    for(int i = 0; i < n; ++i) {
      for(int j = i + 1; j < n; ++j) {
        swap(s[i], s[j]);
        int u = atoi(s.c_str());
        low = min(low, abs(u - v));
        up = max(up, abs(u - v));
        swap(s[i], s[j]);
      }
    }
    cout << low << " " << up << endl;
  }
}
