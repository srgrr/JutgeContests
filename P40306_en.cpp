#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
        string s,t;
        
        while(cin >> s >> t) {
            int n = s.size();
            int m = t.size();
            int cur = 0, i = 0;
            bool unique = true;
            while(i<m and cur<n) {
                if(cur > 0 and t[i] == s[cur-1] and s[cur] != s[cur-1]) unique = false;
                if(t[i] == s[cur]) ++cur;
                ++i;
            }
            
            while(i<m) { 
                if(t[i] == s[n-1]) unique = false;
                ++i;
            }
            
            if(cur == n) {
                if(unique) cout << "one" << endl;
                else cout << "multiple" << endl;
            }
            else {
                cout << "zero" << endl;
            }
        }
        
}