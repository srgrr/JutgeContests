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
  Basicament, el codi el que feia era agrupar els valors de B
  segons el seu valor de A i printar la suma maxima que obteniem de sumar
  els maxims de dos grups diferents.

  Calia ferlo bastant d'aquest estil (sense fer servir maps ni res d'aixo)
  per aconseguir ficar el problema, altrament donava bomba.
*/

int mistery(const vector<int>& A, const vector<int>& B) {
  int n = int(A.size());
  vi vf = {-1, -1}, vs = {-1, -1};
  for(int i = 0; i < n; ++i) {
    int a = A[i], b = B[i];
    bool already = false;
    // ya pertenecian a alguna
    if(a == vf[0]) {
      vf[1] = max(vf[1], b);
      already = true;
    }
    else if(a == vs[0]) {
      vs[1] = max(vs[1], b);
      already = true;
    }
    if(vf[1] < vs[1]) swap(vf, vs);
    // no pertenecian
    if(already) continue;
    // ambos vacios
    if(vf[1] == -1 && vs[1] == -1) {
      vf = {a, b};
    }
    // vs vacio
    else if(vs[1] == -1) {
      vs = {a, b};
      if(vf[1] < vs[1]) swap(vf, vs);
    }
    // ninguno vacio
    else if(b > vs[1]) {
      if(b > vf[1]) {
        vs = vf;
        vf = {a, b};
      }
      else {
        vs = {a, b};
      }
    }
  }
  if(vs[1] == -1) return 0; // asklxdasdkasdasdasklasdasdasdjkl
  return max(0, vf[1] + vs[1]);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vi a(n), b(n);
  for(int& x : a) cin >> x;
  for(int& x : b) cin >> x;
  cout << mistery(a, b) << endl;
}
