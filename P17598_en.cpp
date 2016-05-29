#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int n;
vector<int> pesos;

/*
    Donat que com a molt hi ha 8 pesos, podem provar
    totes les permutacions a backtracking.
*/

int sol(int esq, int dre, int pas){
    if(pas==n){
        return (esq>=dre ? 1 : 0);
    }else{
        if(dre>esq) return 0;
        return sol(esq+pesos[pas], dre, pas+1) + sol(esq,dre+pesos[pas], pas+1);
    }
}

int main(){
    #ifdef _LOCAL
    freopen("input.txt","r",stdin);
    #endif
    while(cin >> n){
        pesos = vector<int>(n);
        for(int i=0; i<n; ++i) cin >> pesos[i];
        sort( pesos.begin(), pesos.end() );
        int ttl = 0;
        do{
            ttl += sol(0,0,0);
        }while( next_permutation(pesos.begin(),pesos.end()) );
        cout << ttl << endl;
    }
}