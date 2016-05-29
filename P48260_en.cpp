#include <bits/stdc++.h>
using namespace std;


int main() {
    string tipos; int n;
    while(cin >> tipos >> n) {
        n /= 2;
        vector< vector<string> > todas(n+1, vector<string>());
        todas[0].push_back("");
        string abren, cierran = "";
        for(int i=0; i<tipos.size(); i+=2)
            abren += tipos[i],
            cierran += tipos[i+1];
        for(int i=1; i<=n; ++i) { //ra cada longitud
            for(int j=0; j<abren.size(); ++j) { // para cada tipo de parentesis
                for(int k=0; k<i; ++k) { // para cada distribucion posible de longitudes
                    int izq = k, der = i-k-1;
                    for(int l=0; l<todas[izq].size(); ++l) //para toda posible palabra a la izquierda
                        for(int m=0; m<todas[der].size(); ++m) //para toda  posible palabra a la derecha
                            todas[i].push_back(abren[j] + todas[izq][l] + cierran[j] + todas[der][m]);
                }
            }
        }
        for(int i=0; i<todas[n].size(); ++i) cout << todas[n][i] << endl;
    }
}