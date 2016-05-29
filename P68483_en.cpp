#include <iostream>
#include <vector>
#include <algorithm>
#define modme (100000000+7)
using namespace std;
typedef unsigned long long int ull;

/*
	Problema bastant literal (i insultant per alguns colectius, imagino).
*/

int main(){
    int i = 0;
    string line;
    while(getline(cin,line)){
        if(i%2 != 0) cout << line << endl;
        ++i;
    }
}