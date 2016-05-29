#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
    Aqui simulava les insercions de valors obeint la regla de nomes es notificaven
    valors mes grans, poc mes a dir.
*/

int reserva[100003];

int inserta(int x, int e,int d){
    if(e<=d){
        int m = (e+d)/2;
        int vm = reserva[m];
        if(x>vm) return max(m, inserta(x,m+1,d) );
        else return inserta(x,e,m-1);
    }
    return -1;
}

int main(){
    int n;
    while(cin >> n){
        if(n==0){
                cout << 0 << endl;
                continue;
        }
        int e,d;
        e = d = 100001;
        int r;
        cin >> r;
        reserva[e] = r;
        for(int i=1; i<n; ++i){
            int r;
            cin >> r;
            int p = inserta(r,e,d);
            if(p==-1) reserva[e-1] = r, --e;
            else reserva[p] = r;
        }
        /*for(int i=e; i<=d; ++i)
            cout << reserva[i] << ' ';
        cout << endl;*/
        cout << (d-e)+1 << endl;
    }
}