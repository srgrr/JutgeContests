#include <bits/stdc++.h>
using namespace std;

int main() {
	string s; int k;
	while(cin >> s >> k) {
		int ok = s.size()-k;
		for(int i=0; i<s.size()-k; ++i)
			if(s[i] > s[i+k]) {
				ok = i; break;
			}
		for(int i=0; i<ok; ++i) cout << s[i];
		for(int i=ok+k; i<s.size(); ++i) cout << s[i];
		cout << endl;

	}
}