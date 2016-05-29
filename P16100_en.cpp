#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

/*
    Aixo era un problema de canvi de monedes.
    Suposo que hi ha altres maneres, pero la que se'm va ocorrer sembla
    ser una programacio dinamica de la forma (monedes_restants, quantitat_restant, moneda_maxima)
    Em sona que la ultima variable moneda_maxima no cal.
*/

int C[] = {
    2,3,5,7,11,13,17,19,23,29
    };
const int maxC = 29*20;
int DP[21][maxC+60][10];

int run(int c, int q, int maxc){
    if(q<0) return 0;
    if(c==0 and q!=0) return 0;
    if(DP[c][q][maxc]==-1){
        DP[c][q][maxc] = 0;
        for(int i=0; i<=maxc; ++i )
            DP[c][q][maxc] += run(c-1,q-C[i],i);
    }
    return DP[c][q][maxc];
}

int main(){
    #ifdef _LOCAL
    freopen("input.txt","r",stdin);
    #endif // _LOCAL
    memset(DP,-1,21*(maxC+60)*10*sizeof(int) );
    for(int i=0; i<10; ++i) DP[0][0][i] = 1;
    int T;
    cin >> T;
    while(T--){
        int c,v;
        cin >> c >> v;
        if(v>maxC) cout << 0 << endl;
        else{
            cout << run(c,v,9) << endl;
        }
    }
}