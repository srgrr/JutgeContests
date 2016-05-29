#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;

/*
  Com que els strings estan fets d'as i bs i no son mes llargs
  que 63 caracters es poden interpretar com nombres en binari.
  Llavors, pel text, es pot iterar i mirar la subcadena [i, i+len-1]
  rapidament (on len es el que mesuren els patrons, que tots mesuren el mateix)
*/

ll fhash(const string & s) {
  ll h = 0;
  for (int i = 0; i < int(s.size()); ++i) {
    h <<= 1;
    h += (s[i] == 'b');
  }
  return h;
}

int main() {
  int T; cin >> T;
  int ncase = 0;
  while (T--) {
    map<ll,int> mp;
    string s;
    cin >> s;
    int n = s.size();
    int m; cin >> m;
    int lp = -1;
    vector<ll> v(m);
    for (int i = 0; i < m; ++i) {
      string p;
      cin >> p;
      if (lp == -1) lp = p.size();
      ll h = fhash(p);
      mp[h] = 0;
      v[i] = h;
    }
    ll h = 0;
    for (int i = 0; i < n; ++i) {
      h <<= 1;
      h += (s[i] == 'b');
      h &= ((1LL<<lp)-1);
      if (i+1 >= lp) {
        map<ll,int>::iterator it = mp.find(h);
        if (it != mp.end()) {
          ++(it->second);
        }
      }
    }
    cout << "Case " << ++ncase << ":" << endl;
    for (int i = 0; i < m; ++i) {
      cout << mp[v[i]] << endl;
    }
    cout << endl;
  }
}