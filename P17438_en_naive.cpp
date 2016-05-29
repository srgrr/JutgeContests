#include <vector>
#include <iostream>
#include <list>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using namespace std;

/*
    Quan vaig ficar aquest problema sabia sobre programacio
    dinamica, pero no sobre teoria de jocs.
    Per tant, vaig expressar el problema com una succesio d'estats
    definits pel nombre de pedres a cada pila i "simular el joc".
    Tampoc vaig caure que la variable "tr" (de torn) no es necessaria
    (es pot negar el resultat i prou).
*/

int status[2][3][4][5][6][7][2]; // ultima dim = turno , 0 = jugador A, 1 = jugador B
bool ok[2][3][4][5][6][7][2];
int req(int s1,int s2,int s3,int s4,int s5,int s6,int tr){
    if( not ok[s1][s2][s3][s4][s5][s6][tr]){
	ok[s1][s2][s3][s4][s5][s6][tr] = true; 
        //cout << tr << ' ';
        int cont = (tr+1)%2;
        int f    =  tr == 0 ? 1 : -1; //si somos el jugador 0 buscamos maximo, si somos 1 buscamos minimo
	int res = -f;

            for(int i = 0 ; i < s1 ; ++i)
                if( req(i,s2,s3,s4,s5,s6,cont) == f ) res = f;
            for(int i = 0 ; i < s2 ; ++i)
                if( req(s1,i,s3,s4,s5,s6,cont) == f ) res = f;
            for(int i = 0 ; i < s3 ; ++i)
                if( req(s1,s2,i,s4,s5,s6,cont) == f ) res = f;
            for(int i = 0 ; i < s4 ; ++i)
                if( req(s1,s2,s3,i,s5,s6,cont) == f ) res = f;
            for(int i = 0 ; i < s5 ; ++i)
                if( req(s1,s2,s3,s4,i,s6,cont) == f ) res = f;
            for(int i = 0 ; i < s6 ; ++i)
                if( req(s1,s2,s3,s4,s5,i,cont) == f ) res = f;
	
	status[s1][s2][s3][s4][s5][s6][tr] = res;

    }
    return status[s1][s2][s3][s4][s5][s6][tr];
}

int main (){
    for(int i = 0 ; i < 2 ; ++i)
        for(int j = 0 ; j < 3 ; ++j)
            for(int k = 0 ; k < 4 ; ++k)
                for(int l = 0 ; l < 5 ; ++l)
                    for(int m = 0 ; m < 6 ; ++m)
                        for(int n = 0 ; n < 7 ; ++n)
                            for(int o = 0 ; o < 2 ; ++o)
				ok[i][j][k][l][m][n][o] = false,
                                status[i][j][k][l][m][n][o] = 
					(i+j+k+l+m+n)==0 ? o==0 ? 1 : -1 : -2;

	int j=1;
	int n;
	cin >> n;
	string p1,p2;
 	while(n-- and cin >> p1 >> p2){
		cout << "Joc #" << j++ << ": ";
		int s1,s2,s3,s4,s5,s6;
		cin >> s1 >> s2 >> s3 >> s4 >> s5 >> s6;
		cout << ( req(s1,s2,s3,s4,s5,s6,0)==1 ? p1 : p2 ) << endl;
	}

}