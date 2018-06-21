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

/*
  En realitat la sucessio de batalles i els seus resultats
  el que feien era crear un ordre entre els diferents cavallers.

  Per exemple: 1 1 3 significa que 1 > 2 i 3 > 1

  Observem dues coses:

  1) Si creem un graf on les arestes (u, v) representen que u > v, aquest
  sera dirigit i aciclic.
  2) Hi haura exactament un vertex amb grau d'entrada zero, que sera el del cavaller mes fort.

  Donat un vertex v que pot arribar fins k vertexs veiem que el cavaller
  d'aquest node ha de tenir com a minim forca k + 1 per tal de derrotar tots  els cavallers.

  Tambe veiem que cap cavaller pot ser igual o mes fort que la forca maxima del cavaller del node v.

  Si fem un recorregut en profunditat comencant pel node del cavaller mes fort i actualitzem els intervals seguint aquestes regles construim la resposta en temps lineal.

*/

int dfs(vvi& g, vi& low, vi& up, int root, int upper) {
  up[root] = upper;
  for(int adj : g[root]) {
    low[root] += dfs(g, low, up, adj, upper - 1);
  }
  return 1 + low[root];
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  while(cin >> n) {
    vvi g(n);
    vi v(n), indg(n);
    for(int i = 0; i < n; ++i) {
      cin >> v[i], --v[i];
      if(i > 0 && v[i] != v[i - 1]) {
        g[v[i]].push_back(v[i - 1]);
        ++indg[v[i - 1]];
      }
      if(v[i] != i) {
        g[v[i]].push_back(i);
        ++indg[i];
      }
    }
    vi low(n, 0), up(n, n);
    int root = 0;
    for(int i = 0; i < n; ++i) {
      if(indg[i] == 0) {
        root = i;
      }
    }
    dfs(g, low, up, root, n);
    for(int i = 0; i < n; ++i) {
      ++low[i];
      cout << i + 1 << ": ";
      if(low[i] == up[i]) cout << low[i] << endl;
      else cout << "[" << low[i] << ", " << up[i] << "]" << endl;
    }
    cout << string(10, '-') << endl;
  }
}
