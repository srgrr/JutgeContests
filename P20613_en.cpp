#include <bits/stdc++.h>
using namespace std;

void escribe(vector< vector<string> >& T,
             vector< int >& ultimo, int nivel, string padre_grande, string padre_pequenyo) {
    if(nivel == T.size() or ultimo[nivel] >= T[nivel].size()) {
        cout << '-' << endl;
        return;
    }
    int aqui = ultimo[nivel];
    if(T[nivel][aqui] > padre_pequenyo or T[nivel][aqui] < padre_grande) {
        cout << '-' << endl;
        return;
    }
    cout << T[nivel][aqui] << endl;
    //cout << T[nivel][aqui] << "(" << padre_grande << "," << padre_pequenyo << ")" << endl;
    ++ultimo[nivel];
    //cout << "(" << T[nivel][v] << "," << nivel << ")" << endl;
    //cout << "   " << hijos[nivel][v].first << ":" << hijos[nivel][v].second << endl;
    escribe(T, ultimo, nivel+1, padre_grande, min(padre_pequenyo, T[nivel][aqui]));
    escribe(T, ultimo, nivel+1, max(padre_grande, T[nivel][aqui]), padre_pequenyo);
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    while(cin >> n) {
        vector< pair<string, int> > nodos(n);
        int nivel_maximo = 0;
        for(int i=0; i<n; ++i) {
            cin >> nodos[i].first >> nodos[i].second;
            --nodos[i].second;
            nivel_maximo = max(nivel_maximo, nodos[i].second);
        }
        ++nivel_maximo;
        vector< vector<string> > T(nivel_maximo, vector<string>());
        vector<int> ultimo(nivel_maximo, 0);
        for(int i=0; i<n; ++i)
            T[nodos[i].second].push_back(nodos[i].first);
        for(int i=0; i<nivel_maximo; ++i)
            sort(T[i].begin(), T[i].end());
        escribe(T, ultimo, 0, "a", "zzzzzzzzzzzz");
        cout << string(10, '-') << endl;
    }
}