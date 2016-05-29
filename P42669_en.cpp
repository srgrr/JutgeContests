#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	while(cin>>n and n!=0) {
		vii v(n);
		for(int i=0; i<n; ++i) { 
			cin >> v[i].first >> v[i].second;
			if(v[i].first > v[i].second) swap(v[i].first, v[i].second);
		}
		sort(v.begin(), v.end());
		multiset<int> S;
		int ans = 0;
		for(int i=0; i<n; ++i) {
			S.insert(v[i].second);
			if(v[i].first>=*S.begin()) S.erase(*S.begin());
			ans = max(ans, (int)S.size());
		}
		cout << ans << endl;
	}
}