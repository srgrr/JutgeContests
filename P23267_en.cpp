#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<bool> vb;
const int maxn = 1003;
const int inf = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n,m;
	while(cin >> n >> m) {
		vvpii g(n, vpii());
		for(int i=0; i<m; ++i) {
			int u,v,k; cin >> u >> v >> k;
			g[u-1].push_back(make_pair(v-1, k));
		}
		bool can = true;
		vector<int> d(n, inf); d[0] = 0;
		for(int k=1; k<n; ++k)
			for(int i=0; i<n; ++i) {
				int v = i;
				for(int j=0; j<g[v].size(); ++j)
					d[ g[v][j].first ] = min( d[ g[v][j].first ], g[v][j].second + d[v] );
			}

		for(int i=0; i<n; ++i) {
			int v = i;
			for(int j = 0; j<g[v].size(); ++j)
				if(d[g[v][j].first] > d[v] + g[v][j].second) can = false;
		}

		cout << (can ? "yes" : "no") << endl;
	}
}