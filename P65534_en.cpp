#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAXN = 100;
const int MAXV = MAXN*MAXN + 9;
ll n, w, dp[MAXN][MAXV], vv[MAXN], wv[MAXN];
bool taken[MAXN][MAXV];

ll calc(int pos, int val) {
	if(val == 0) return 0;
	if(val <= 0 or pos >= n) return 1e18;
	ll& ref = dp[pos][val];
	if(ref != -1ll) return ref;
	ref = calc(pos+1, val);
	taken[pos][val] = false;
	int minusv = val - vv[pos];
	if(minusv >= 0) {
		ll recval = wv[pos] + calc(pos+1, minusv);
		if(recval < ref) {
			taken[pos][val] = true;
			ref = recval;
		}
	}
	return ref;
}

vector<int> get_solution(int maxi) {
	vector<int> ret;
	int curv = maxi;
	int sumv = 0;
	for(int i=0; i<n; ++i) {
		if(taken[i][curv]) {
			ret.push_back(i);
			sumv += vv[i];
			curv -= vv[i];
		}
	}
	ret.push_back(sumv);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> w >> n) {
		int sumv = 0;
		for(int i=0; i<n; ++i) {
			cin >> wv[i] >> vv[i];
			sumv += vv[i];
		}
		for(int i=0; i<n; ++i) {
			for(int j=0; j<=sumv; ++j)  {
				dp[i][j] = -1ll;
				taken[i][j] = false;
			}
		}
		int maxi = 0;
		for(int i=0; i<=sumv; ++i) {
			if(calc(0, i) <= w) maxi = i;
		}
		auto sol = get_solution(maxi);
		cout << sol[sol.size()-1] << endl;
		cout << sol.size()-1 << endl;
		for(int i=0; i<(int)sol.size()-1; ++i) {
			if(i>0) cout << ' ';
			cout << sol[i] + 1;
		}
		cout << endl;
	}
}