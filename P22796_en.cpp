#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    while(cin >> n >> m) {
        vector<string> G(n);
        for(int i=0; i<n; ++i)
            cin >> G[i];
        int i1,j1; cin >> i1 >> j1;
        int i2,j2; cin >> i2 >> j2;
        int a,b; cin >> a >> b;
        int dx[] = {a,a,-a,-a,b,b,-b,-b};
        int dy[] = {b,-b,b,-b,a,-a,a,-a};
        bool puede = i1==i2 and j1==j2;
        queue< pair<int,int> > Q;
        for(int i=0; i<8; ++i) {
            int oi = i1+dx[i];
            int oj = j1+dy[i];
            if(oi==i2 and oj==j2) puede = true;
            if(oi>=0 and oi<n and oj>=0 and oj<m and G[oi][oj]!='X') Q.push({oi,oj});
        }
        if(not puede) {
            while(not Q.empty()) {
                int vx = Q.front().first;
                int vy = Q.front().second;
                Q.pop();
                for(int i=0; i<8; ++i) {
                    int oi = vx+dx[i];
                    int oj = vy+dy[i];
                    if(oi==i2 and oj==j2) puede = true;
                }
            }
        }
        if(puede) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}