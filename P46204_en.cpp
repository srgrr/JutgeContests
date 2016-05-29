#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 7;
struct point {
	float x, y;
	int ind;
};
point v[MAXN];
int n;

point anchor;
inline double angle(const point& q) {
	point t = {q.x - anchor.x, q.y - anchor.y, -1};
	return atan2(t.y, t.x);
}

inline bool byang(const point& a, const point& b) {
	return angle(a) < angle(b);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin >> n) {
		anchor = {1e10, 1e10, -1};
		for(int i=0; i<n; ++i) {
			cin >> v[i].x >> v[i].y;
			v[i].ind = i;
			if(anchor.y > v[i].y)
				anchor = v[i];
		}
		sort(v, v+n, byang);
		for(int i=0; i<n; ++i) {
			if(i>0) cout << ' ';
			cout << v[i].ind+1;
		}
		cout << '\n';
	}
}