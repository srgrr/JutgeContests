#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
using namespace std;
const int maxn = 1e5 + 9;
const int maxb = 19;

vector< vector< int > > bits(maxn, vector< int >(maxb, 0));

void precalc() {
  for (int i = 1; i < maxn; ++i) {
    for (int j = 0; j < maxb; ++j) {
      bits[i][j] = (i & (1 << j) ? 1 : 0) + bits[i - 1][j];
    }
  }
}

struct gate {
  vector< double > bits;
  string kind;
  int i1, i2;
  int o = -1;
  int cnt = 0;
};

vector< double > average_bits(int l, int r) {
  double cnt = r - l + 1;
  vector< double > ret(maxb, 0.0);

  for (int i = 0; i < maxb; ++i) {
    int bl = bits[max(0, l - 1)][i];
    int br = bits[r][i];
    ret[i] = 1. * (br - bl) / cnt;
  }

  return ret;
}

vector< double > compute_bits(vector< double >& b1, vector< double >& b2, string kind) {
  vector< double > ret(maxb, 0.0);

  for (int i = 0; i < maxb; ++i) {
    if (kind == "AND") {
      ret[i] = b1[i] * b2[i];
    }
    else if (kind == "OR") {
      ret[i] = 1.0 - (1.0 - b1[i]) * (1.0 - b2[i]);
    }
    else {
      ret[i] = 1.0 - ((1.0 - b1[i]) * (1.0 - b2[i]) + b1[i] * b2[i]);
    }
  }

  return ret;
}

int main() {
  precalc();
  int n;
  while (cin >> n) {
    vector< gate > gates(n);
    for (int i = 0; i < n; ++i) {
      gate& cur = gates[i];
      string kind, input_hint;
      cin >> kind >> input_hint;
      cur.kind = kind;
      if (input_hint == "E") {
        cur.cnt = 3;
        cur.i1 = cur.i2 = -1;
        int l1, r1; cin >> l1 >> r1;
        vector< double > b1 = average_bits(l1, r1);
        int l2, r2; cin >> l2 >> r2;
        vector< double > b2 = average_bits(l2, r2);
        cur.bits = compute_bits(b1, b2, kind);
      }
      else {
        int i1, i2;
        cin >> i1 >> i2;
        gates[i1].o = i;
        gates[i2].o = i;
        cur.i1 = i1;
        cur.i2 = i2;
      }
    }
    vector< double >& bit_ans = gates[0].bits;
    queue< gate > q;
    for (int i = 0; i < n; ++i) {
      gate& cur = gates[i];
      if (cur.cnt == 3) {
        q.push(cur);
      }
    }
    while (!q.empty()) {
      gate cur = q.front();
      q.pop();
      int o = cur.o;
      if (o == -1) {
        bit_ans = cur.bits;
        break;
      }
      ++gates[o].cnt;
      if (gates[o].cnt == 2) {
        gates[o].bits = compute_bits(gates[gates[o].i1].bits, gates[gates[o].i2].bits, gates[o].kind);
        q.push(gates[o]);
      }
    }
    double ans = 0.0;
    for (int i = 0; i < maxb; ++i) {
      ans += (1.0 * bit_ans[i]) * (1 << i);
    }
    cout << fixed << setprecision(4) << ans << endl;
  }
}
