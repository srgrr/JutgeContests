#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cout.setf(ios::fixed);
  cout.precision(3);
  double l1, l2, p1, p2;
  while(cin >> l1 >> l2 >> p1 >> p2) {
    double p3 = 1.0 - p1 - p2;
    double ac_prob = p2*l1 + p3*l2;
    double ac_exp  = 10.0*(p2/(p2 + p3)) + 15.0*(p3/(p2 + p3));
    double ms_prob = 1.0 - ac_prob;
    double ms_exp  = 5.0*p1 + 10.0*p2 + 15.0*p3;
    cout << ms_exp*pow(1.0 - ms_prob, -1.0) << endl;
  }
}
