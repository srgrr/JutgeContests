#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <cstdlib>
#include <set>
#include <cmath>
#include <map>
#include <algorithm>
#include <limits>
#include <stack>
using namespace std;
#define legal(i,j) i>=0 and i<n and j>=0 and j<n
#define epsilon 1e-9
#define epsok(a,b) abs(a-b)<epsilon
typedef pair<double,double> point;

/*
    El trilero composa una permutacio de forma repetida.
    Una posicio donada pot moure's a N-1 posicions diferent com a molt,
    fent que el cicle sigui de mida com a molt N-1.

    Coneixent la mida del cicle, podem fer k modul mida i obtenir
    la posicio final.
*/

int ciclo[100000];

int main(){
    int n;
    while(cin >> n){
        vector<int> perm(n+1);
        for(int i=1; i<=n; ++i){
                cin >> perm[i];
        }
        int k,x;
        cin >> k >> x;
        int init = x;
        ciclo[0] = x;
        int longc = 1;
        while(perm[x] != init){
            ciclo[longc++] = perm[x];
            x = perm[x];
        }
        cout << ciclo[k%longc] << endl;
    }
}