#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9 + 7;
typedef vector<ll> vi;
typedef vector<vi> vvi;
string s;
int n, m;

vvi dfa;

int char2int(char x) {
	return (x-'a');
}

bool is_proper_prefix(vi& mock_prefix, int start) {
	for(int i = start; i < (int)mock_prefix.size(); ++i)
		if(mock_prefix[i] != mock_prefix[i-start]) return false;
	return true;
}

void fill_path(vi& mock_prefix, int start) {
	int ind = 0;
	for(int i = start; i<(int)mock_prefix.size(); ++i) ind = dfa[ind][mock_prefix[i]];
	dfa.back()[mock_prefix.back()] = ind;
}

void fill_missing_case(vi& mock_prefix) {
	for(int i = 1; i<(int)mock_prefix.size(); ++i) {
		if(is_proper_prefix(mock_prefix, i)) {
			fill_path(mock_prefix, i);
			break;
		}
	}
}

vvi get_id_matrix(int n) {
	vvi ret(n, vi(n, 0));
	for(int i=0; i<n; ++i) ret[i][i] = 1;
	return ret;
}

vvi matrix_prod(vvi& A, vvi& B) {
	int n = A.size();
	vvi ret(n, vi(n, 0));
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
			for(int k=0; k<n; ++k) ret[i][j] += (A[i][k]%mod*B[k][j]%mod), ret[i][j] %= mod;
	return ret;
}

vvi matrixpow(vvi& M, int e) {
	if(e == 0)
		return get_id_matrix(M.size());
	if(e == 1)
		return M;
	vvi m_squared = matrix_prod(M, M);
	vvi aux = matrixpow(m_squared, e/2);
	if(e%2) return matrix_prod(aux, M);
	return aux;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	while(cin >> s >> n >> m) {
		dfa.clear();
		dfa.push_back(vi(26, -1));
		int S = s.size();
		vi prefix;
		for(int i=0; i<S; ++i) {
			int cur = char2int(s[i]);
			prefix.push_back(cur);
			dfa.back()[cur] = i+1;
			dfa.push_back(vi(26, -1));
			if(i == S-1) {
				for(int j = 0; j<26; ++j) dfa.back()[j] = dfa.size()-1;
					break;
			}
			for(int j = 0; j<26; ++j) {
				if(j==char2int(s[i+1])) continue;
				vi mock_prefix = prefix;
				mock_prefix.push_back(j);
				fill_missing_case(mock_prefix);
			}
		}
		vvi M(dfa.size(), vi(dfa.size(), 0));
		for(int i=0; i<(int)dfa.size(); ++i) {
			for(int j=0; j<m; ++j) {
				dfa[i][j] = max(0ll, dfa[i][j]);
				++M[i][dfa[i][j]];
			}
		}

		vvi MP = matrixpow(M, n);
		cout << MP[0][MP.size()-1] << endl;
	}
}