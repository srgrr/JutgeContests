#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_set<int> S;
    int b0 = 1;
    int b1 = 1;
    while(b1<=1000000) {
        int t = b1;
        b1 = b1+b0;
        b0 = t;
        S.insert(b1);
    }
    
    int n;
    while(cin >> n)
        cout << (S.find(n)!=S.end() ? "Tourist" : "Petr") << endl;
}