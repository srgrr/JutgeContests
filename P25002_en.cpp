#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1e9 +7;
const int tests = 40;

/*
    Intuitivament vaig pensar que probablement dos polinomis diferents
    no podien coincidir a la perfeccio a massa llocs.
    Per tant, els avaluo aleatoriament uns quants cops. Si dona igual a tot,
    es possible que siguin iguals, si dona diferent, doncs son diferents amb
    tota certesa. L'algorisme funciona amb els jocs de proves.

    Mes tard vaig descobrir que dos polinomis de mateix grau pero diferents
    coefs coincideixen a com a molt k punts (crec que 2n, on n = grau).
*/

ll cmod(ll a, ll b) {
    return ((a%b) + b)%b;
}

ll pow(ll b, ll e) {
    if(e==0) return 1;
    if(e==1) return b;
    ll tmp = cmod(pow(b*b, e/2),mod);
    if(e%2) return cmod((b*tmp), mod);
    return tmp;
}

void eval_poly(string& p, vector< ll >& xs, vector< ll >& ret) {
    istringstream iss(p);
    vector< ll > factor(tests);
    char parse;
    while(iss >> parse) {
        if(parse == '(') continue;
        if(parse == ')') {
            for(int i=0; i<tests; ++i)
                ret[i] = cmod(ret[i]*factor[i],mod);
            factor = vector< ll >(tests, 0);
            continue;
        }
        char sign = parse;
        ll coef; iss >> coef;
        coef = cmod(coef, mod);
        if(sign == '-') coef *= -1;
        char x_char; iss >> x_char;
        char power; iss >> power;
        ll exp; iss >> exp;
        for(int i=0; i<tests; ++i)
            factor[i] = cmod(factor[i] + cmod(coef*pow(xs[i],exp),mod), mod);
    }
}

bool same(string& p, string& q) {
    vector< ll > xs(tests);
    vector< vector< ll > > results(2, vector<ll>(tests, 1));
    for(int i=0; i<tests; ++i)
        xs[i] = rand()%101;
    eval_poly(p, xs, results[0]);
    eval_poly(q, xs, results[1]);
    for(int i=0; i<tests; ++i)
        if(results[0][i] != results[1][i]) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    srand(time(NULL));
    string p,q;
    while(getline(cin, p) and getline(cin, q))
        cout << (same(p,q) ? "yes" : "no") << endl;
}