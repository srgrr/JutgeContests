#include <iostream>
#include <vector>
using namespace std;
using ll = long long int;
const int MAXN = 1e7 + 9;

/*
    Si tens a + b = c, amb a, c primers i b compost es com dir que
    b = c - a
    Si no comptem el 2, aixo es sistematicament cert, ja que la diferencia entre dos primers sempre
    sera parell
    Llavors, amb tots els primers de 2 a N podem dir que existiran
    (P(n) choose 2) - parelles_invalides

    Les parelles invalides les podem comptar apart, serien
    P - 2 dona un numero primer
    P - 2 es primer en si
    Que seria comptar dos cops si P - 2 es primer

    Per exemple, 5 i 7 son consecutius
    7 - 2 = 5
    7 - 5 = 2

    Aixo es pot calcular prou rapid fent criba i acumulant les parelles invalides
    que anem veient quan sabem que un nombre de primer
*/

ll nc2(ll x) {
    return x * (x - 1ll) / 2ll;
}

int main() {
    vector< bool > is_prime(MAXN, true);
    vector< int > prime_count(MAXN, 0);
    vector< int > invalid_p2s(MAXN, 0);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < MAXN; ++i) {
        prime_count[i] += prime_count[i - 1];
        invalid_p2s[i] += invalid_p2s[i - 1];
        if (!is_prime[i]) continue;
        if (is_prime[i - 2]) ++invalid_p2s[i];
        ++prime_count[i];
        for (int j = i + i; j < MAXN; j += i) {
            is_prime[j] = false;
        }
    }
    int n;
    while (cin >> n) {
        ll ans = max(0ll, nc2(prime_count[n]) - 2ll * ll(invalid_p2s[n]) - 1);
        cout << ans << endl;
    }
}
