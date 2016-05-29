#include <bits/stdc++.h>
using namespace std;

/*
    El problema es redueix a algo molt similar als codis de Huffman.
    Es a dir, es maximitza el producte triant els dos nodes mes grans
    cada vegada.
*/

typedef long long int ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin >> n and n!=0) {
        priority_queue<double, vector<double>, greater<double> > Q;
        while(n--) {
            double num;
            cin >> num;
            Q.push(num);
        }
        double ans = 1.0;
        while(Q.size()>1) {
            double v1 = Q.top(); Q.pop();
            double v2 = Q.top(); Q.pop();
            ans *= v1*v2;
            Q.push(v1*v2);
        }
        if(Q.size()==1) ans *= Q.top();
        while(ans>=1e7) ans /= 10.0; 
        cout << (ll)ans << endl;
    }
}