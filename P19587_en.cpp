#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2001;
const int mod = 1e8 + 9;
int dp[MAXN][MAXN];

/*
    En primer lloc, el quadrant no importa, per tant
    es pot resoldre el problema pel quadrant +x, +y

    El problema es una programacio dinamica prou normal
    treient que s'ha de contemplar el cas on s'es a un eix
    (OX o OY), on s'ha de multiplicar per dos la resposta
    perque qualsevol cami te un de simetric a l'altre quadrant.
*/

int dist(int x, int y) {
    return x*x + y*y;
}

int dx[] = {1, 1, 1, -1, -1, -1, 0, 0};
int dy[] = {0, 1,-1,  0,  1, -1, 1,-1};

int calc(int x, int y) {
    if(x<0 or y<0) return 0;
    if(x == 0 and y == 0) return 1;
    if(dp[x][y]!=-1) return dp[x][y];
    dp[x][y] = 0;
    int curr = dist(x,y);
    for(int i=0; i<8; ++i) {
        int oi = dx[i], oj = dy[i];
        int nx = x+oi, ny = y+oj;
        if(dist(nx,ny) >= curr) continue;
        //cout << "From (" << x  << "," << y << ") I can go to (" << nx << "," << ny << endl;
        int rec = calc(nx, ny);
        if(x == 0 and nx != x) rec = (rec*2)%mod;
        if(y == 0 and ny != y) rec = (rec*2)%mod;
        dp[x][y] = (dp[x][y] + rec)%mod;
    }
    return dp[x][y];
}

int main() {
    memset(dp, -1, MAXN*MAXN*sizeof(int));
    int x,y;
    while(cin >> x >> y and (x != 0 or y != 0))
        cout << calc(abs(x), abs(y)) << endl;
}