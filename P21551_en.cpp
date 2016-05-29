#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int INF = 1000000000;
typedef vector<int> VI;
typedef vector<VI> VVI;

/*
    El codi donat determinava si un graf era bicolorable o no
    (es a dir, si no contenia algun cicle imparell o si).
    Aixo es pot resoldre en temps lineal.
*/

int n, m;
VVI G;
int C[1000];
bool OK2;
bool OK1(VVI& A) {
    OK2 = true;
    queue<int> Q;
    Q.push(0);
    int total = 0;
    vector<bool> color(n,false);
    vector<bool> vis(n,false);
    while(not Q.empty()){
        int v = Q.front();
        Q.pop();
        if(not vis[v]){
            vis[v] = true;
            ++total;
            for(int i=0; i<A[v].size(); ++i){
                int adj = A[v][i];
                if(not vis[adj]){
                color[adj] = not color[v];
                Q.push(adj);
                }
                if(vis[adj] and color[adj]==color[v]) OK2 = false;
            }
        }
    }
    //cout << total << endl;
    return total == n;
}

int main() {
    while (cin >> n >> m) {
        G = VVI(n, VI());
        while (m--) {
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
        }
        if (not OK1(G)) cout << "NC" << endl;
        else if (OK2) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}