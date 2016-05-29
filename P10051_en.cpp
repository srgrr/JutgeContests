#include <bits/stdc++.h>
using namespace std;

int M[18][18];
int DP[18][(1<<18)+1];
bool ok[18][(1<<18)+1];
int n;

int solve(int v, int mask) {
    if(not ok[v][mask]) {
        ok[v][mask] = true;
        DP[v][mask] = 0;
        for(int i=0; i<n; ++i)
            if( (mask|(1<<i)) != mask)
                DP[v][mask] = max(DP[v][mask],max(M[v][i], M[v][i]+solve(i, mask|(1<<i))));
    }
    return DP[v][mask];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> n) {
        for(int i=0; i<n; ++i) {
            for(int j=0; j<(1<<n)+1; ++j) ok[i][j] = false;
        }
        for(int i=0; i<n; ++i)
            for(int j=0; j<n; ++j)
                cin >> M[i][j];
        int x;
        cin >> x;
        cout << solve(x, (1<<x)) << "\n";
    }
}