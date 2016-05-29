#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n,k;

int num_digits(ll n) {
	if(n<10) return 1;
	return 1 + num_digits(n/10);
}

int get_ith_digit(ll n, ll k) {
	if(k==0) return n%10;
	return get_ith_digit(n/10, k-1);
}

bool x_to_y(ll x, ll y) {
	ll val = (k-x)*(k+x)*(k-y)*(k+y);
	int numdg = num_digits(val);
	int pair_dg = get_ith_digit(val, (numdg-1) - numdg/2);
	bool odd = pair_dg%2 == 1;
	if((x<y and odd) or (x>y and not odd)) return true;
	return false;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n >> k) {
		list<int> path;
		path.push_back(1);
		for(int i=2; i<=n; ++i) {
			int beg = *path.begin();
			if(x_to_y(i, beg)) {
				path.push_front(i);
				continue;
			}
			int end = *(--path.end());
			if(x_to_y(end, i)) {
				path.push_back(i);
				continue;
			}
			for(auto it = ++path.begin(); it != path.end(); ++it) {
				auto rep = it;
				int l = *(--rep);
				int r = *(it);
				if(x_to_y(l, i) and x_to_y(i, r)) {
					path.insert(it, i);
					break;
				}
			}
		}
		for(auto it = path.begin(); it != path.end(); ++it) {
			if(it != path.begin()) cout << ' ';
			cout << *it;
		}
		cout << endl;
	}
}