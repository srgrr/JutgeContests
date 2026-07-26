#include <iostream>
#include <vector>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;

/*
    Problema prou putamerdos
    La teoria es prou facil:
    Al ser les caixes 3x2x1 pots emplenar les cares a "lamines" sempre que
    les dimensions NxM de les cares siguin tal que 6 | NxM i cap de les dues
    dimensions sigui 1.

    Si trobem una cara d'aquestes, podem repetir el proces d'emplenar una cara
    tantes vegades com gran sigui l'altra dimensio

    La part tediosa aqui es trobar quina parella de dimensions serveix per aixo
    i tenir en compte si emplenant totes les cares horizontalment, verticalment
    es suficient o si cal alternar (el cas quan una dimensio es multiple de 6 i
    l'altra es corpimera amb 6)

    Aquest ultim cas es tedios d'implementar pero tambe facil d'entendre:
    3a + 2b pot expressar qualsevol nombre >1, ja que 2b pot expressar qualsevol parell
    i 2(b - 1) + 3 pot expressar el seguent imparell
*/

bool valid(int h, int w, int l) {
    return (w * l) % 6 == 0 && min(w, l) > 1;
}

void fill_face(vvi &v, int w, int l, int &cnt) {
    if (w % 2 == 0 && l % 3 == 0) {
        for (int i = 0; i < w; ++i) {
            for (int j = 0; j < l; ++j) {
                v[i][j] = (i / 2) * (l / 3) + j / 3;
                v[i][j] += cnt;
            }
        }
    }
    else if (w % 3 == 0 && l % 2 == 0) {
        for (int i = 0; i < w; ++i) {
            for (int j = 0; j < l; ++j) {
                v[i][j] = (i / 3) * (l / 2) + j / 2;
                v[i][j] += cnt;
            }
        }
    }
    else if (w % 6 == 0) {
        int j = 0, base = 0;
        while (j < l) {
            int seg = ((l - j) % 3 == 0) ? 3 : 2;
            for (int i = 0; i < w; ++i) {
                for (int k = 0; k < seg; ++k) {
                    v[i][j + k] = cnt + base + (seg == 3 ? i / 2 : i / 3);
                }
            }
            base += (seg == 3) ? w / 2 : w / 3;
            j += seg;
        }
    }
    else if (l % 6 == 0) {
        int i = 0, base = 0;
        while (i < w) {
            int seg = ((w - i) % 3 == 0) ? 3 : 2;
            for (int di = 0; di < seg; ++di) {
                for (int j = 0; j < l; ++j) {
                    v[i + di][j] = cnt + base + (seg == 3 ? j / 2 : j / 3);
                }
            }
            base += (seg == 3) ? l / 2 : l / 3;
            i += seg;
        }
    }
    cnt += (w * l) / 6;
}

vvvi compute(int h, int w, int l) {
    vvvi ret(h, vvi(w, vi(l)));
    int cnt = 1;
    for (int i = 0; i < h; ++i) {
        fill_face(ret[i], w, l, cnt);
    }
    return ret;
}

template <typename F>
void display(int h, int w, int l, F at) {
    cout << "YES" << endl;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            for (int k = 0; k < l; ++k) {
                if (k > 0) cout << " ";
                cout << at(i, j, k);
            }
            cout << endl;
        }
        cout << string(10, '-') << endl;
    }
}

void solve(int h, int w, int l) {
    if (valid(h, w, l)) {
        auto sol = compute(h, w, l); // h x w x l
        display(h, w, l, [&](int i, int j, int k) { return sol[i][j][k]; });
    } else if (valid(w, l, h)) {
        auto sol = compute(w, l, h); // w x l x h
        display(h, w, l, [&](int i, int j, int k) { return sol[j][k][i]; });
    } else if (valid(l, h, w)) {
        auto sol = compute(l, h, w); // l x h x w
        display(h, w, l, [&](int i, int j, int k) { return sol[k][i][j]; });
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    int h, w, l;
    while (cin >> h >> w >> l) {
        solve(h, w, l);
    }
}
