#include <bits/stdc++.h>
using namespace std;

/*
    Poca explicacio en se donar...
    Existeix un teorema que diu que aquest joc es
    guanya o es perd en funcio de la xor dels nombres.
    Crec que al seu dia ho vaig mig entendre, pero al present...
*/

int main() {
    int T; cin >> T;
    for(int k=0; k<T; ++k) {
        string a,b;
        cin >> a >> b;
        int ans = 0;
        for(int i=0; i<6; ++i) {
            int r; cin >> r;
            ans = (ans^r);
        }
        cout << "Joc #" << k+1 << ": " << (ans==0 ? b : a) << endl;
    }
}