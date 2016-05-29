#include <sstream>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#define inf 1000000000
#define legal(m,i,j) i>=0 and i < m.size() and j>=0 and j < m[0].size()
#define vx v.first
#define vy v.second
using namespace std;
typedef pair<int,int> ii;

/*
	Aquest problema va dels tipics jocs amb numeros.
	Per tal d'obtenir la formula, es suficient amb construirla
	seguint les instruccions (aqui diria que la vaig simplificar).
*/

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int main(){
    int n;
    while(cin >> n){
        cout << (n-165)/100 << endl;
    }
}