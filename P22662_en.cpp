#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <ctime>
#include <cstdio>
#include <cassert>
using namespace std;
const int maxv = 100004;

/*
    La idea principal era construir un graf de
    nombres no primers entre ells.
    Em va costar ficar-lo sense que dones bomba (d'aqui els printf i scanf).
    Precalcula els nombres primers i un graf on hi ha aresta entre p i q
    si q = p^k : k > 0 i despres va unint els nombres de l'entrada si no son coprimers
    Per a unir rapid es fa servir una estructura anomenada union-find disjoint set
*/

int S[maxv];
int K[maxv];
int rep(int act){
    if(S[act]==act) return act;
    S[act] = rep(S[act]);
    return S[act];
}

void unir(int a, int b){
    S[rep(a)] = S[rep(b)];
}

int main(){
    vector<bool> sv(maxv,true);
    vector< vector<int> > P(maxv);
    sv[0] = sv[1] = false;
    for(int i=2; i<maxv; ++i){
        if(sv[i]){
            P[i].push_back(i);
            for(int j=i+i; j<maxv; j+=i){ 
                sv[j] = false;
                P[j].push_back(i);
            }
        }
    }
    int n;
    int maxit = 0;
    while(scanf("%d",&n)==1){
        for(int i=0; i<maxv; ++i) S[i] = i, K[i] = 0;
        int mesG = 0;
        while(n--){
            int num;
            scanf("%d",&num);
            int mesp = 2000000;
            for(int i : P[num]) mesp = min(mesp, rep(i));
            ++K[mesp];
            for(int i : P[num]){
                int rf = rep(i);
                if(rf!=mesp){
                    K[mesp]+=K[rf];
                    unir(rf,mesp);
                }
            }
            
            mesG = max(mesG, K[mesp]);
        }
        printf("%d\n",mesG);
    }
}