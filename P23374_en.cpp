#include <iostream>
using namespace std;


int main(){
    int n;
    while(cin>>n)
        cout << ( n&(n-1) ? "Petr" : "Tourist" ) << endl;
}