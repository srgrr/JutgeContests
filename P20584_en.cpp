#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;
typedef long long int ll;

/*
    Un cop precalculats els nombres de catalan, es pot escriure el numero com
    si s'estigues fent un canvi de base, d'acord l'ordre donat a l'enunciat.
*/

ll DP[34][34];
ll C[34];

ll catalanNumbers(int op,int cl){
    if(DP[op][cl]==-1){
        ll ret = 0;
        if(op>0)
            ret += catalanNumbers(op-1,cl+1);
        if(cl>0)
            ret += catalanNumbers(op,cl-1);
        DP[op][cl] = ret;
    }
	return DP[op][cl];

}

void fillC(){
    for(int i=0; i<34; ++i)
        for(int j=0; j<34; ++j) DP[i][j] = -1;
    DP[0][0] = 1;
    for(int i=0; i<34; ++i) C[i] = catalanNumbers(i,0);
}

void unrank(ll rank, ll pairs){
    if(pairs>0){
        //cout << "Estic calculant el rang " << rank << " per a " << pairs << " parelles." << endl;
        ll sum = 0;
        int i=0;
        int k=pairs-1;
        while(i<pairs){
            k = pairs-i-1;
            if( sum + C[i]*C[pairs-i-1] > rank) break;
            sum+= C[i]*C[pairs-i-1];
            ++i;
        }
        rank -= sum;
        cout << '(';
        unrank(rank/C[k],i);
        cout << ')';
        unrank(rank%C[k],k);
    }
}

int main(){
    fillC();
    ll rank, pairs;
    while(cin >> rank >> pairs){
        unrank(rank-1,pairs);
        cout << endl;
    }
}