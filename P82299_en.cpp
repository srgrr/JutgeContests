#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int inf = 1e9;

void fillDist(vector< vector<int> >& G, vector<int>& D, int source){
    vector<bool> vis(G.size(),false);
    queue<int> Q;
    Q.push(source);
    D[source] = 0;
    while(not Q.empty()){
            int v = Q.front(); Q.pop();
            if(not vis[v]){
                vis[v] = true;
                for(int i=0; i<G[v].size(); ++i){
                    int adj = G[v][i];
                    D[adj] = min(D[adj], D[v]+1);
                    Q.push(adj);
                }
            }
    }
}

int main(){
    int T; cin >> T;
    while(T--){
        int n,m,r; cin >> n >> m >> r;
        int iv,bp; cin >> iv >> bp;
        --iv, --bp;
        vector< vector<int> > G(n, vector<int>());
        vector<int> E(r);
        while(m--){
            int u,v; cin >> u >> v;
            --u,--v;
            G[u].push_back(v), G[v].push_back(u);
        }
        for(int i=0; i<r; ++i){ 
            cin >> E[i];
            --E[i];
        }
        vector<int> DI(n,inf);
        vector<int> DB(n,inf);
        fillDist(G,DI,iv);
        fillDist(G,DB,bp);
        bool ok = DI[bp]==inf;
        if(not ok){
            int i=0;
            while(i<E.size() and not ok){
                int sor = E[i];
                ok = DI[sor]<DB[sor];
                ++i;
            }
        }
        if(ok) cout << "safe" << endl;
        else{
            int opt=0;
            for(int i=0; i<n; ++i)
                if(DB[i]>DI[i]) opt = max(opt, DB[i]);
            cout << opt << endl;
        }
    }
}