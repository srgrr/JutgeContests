#include <iostream>
#include <vector>
#include <list>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

/*
    Programacio dinamica molt semblant a la dels arbres AVL per exemple.

    La funcio es f(objectes, bosses, caixes) i un valor d'aquest funcio depen
    dels valors despres d'haver ficat un objecte (a una bossa o una caixa).

*/

ll DP[26][26][26];

ll run(int objs, int bags, int boxes){
    if(DP[objs][bags][boxes]==-1){
        DP[objs][bags][boxes] = 0;
        if(objs>0){
            if(bags>0)
                DP[objs][bags][boxes] += bags*run(objs-1,bags,boxes)+run(objs-1,bags-1,boxes);
            if(boxes>0)
                DP[objs][bags][boxes] += run(objs-1,bags,boxes-1);
        }
    }
    return DP[objs][bags][boxes];
}

int main(){

    for(int i=0; i<26; ++i)
        for(int j=0; j<26; ++j)
            for(int k=0; k<26; ++k)
                DP[i][j][k] = -1;
    DP[0][0][0] = 1;
    int objs,bags,boxes;
    while(cin >> objs >> bags >> boxes){
        cout << run(objs,bags,boxes) << endl;
    }
}