#include <iostream>
#include <algorithm>
using namespace std;

/*
    Trobar la tercera permutacio en ordre lexicografic.

    Si no existis next_permutation l'hauriem d'implementar nosaltres.

    Es una mica pal, pero pots recrear de memoria com es fa provant amb n = 3
    i convertint el que has fet en un programa.

    Nomes cal mirar que es pugui obtenir la seguent permutacio (i doni alguna cosa
    diferent) dues vegades.
*/

int main() {
    string s;
    while (cin >> s) {
        sort(s.begin(), s.end());
        bool ok = true;
        for (int i = 0; i < 2; i++) {
            if (!next_permutation(s.begin(), s.end())) {
                ok = false;
                break;
            }
        }
        cout << (ok ? s : "NO") << endl;
    }
}
