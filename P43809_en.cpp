#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

const int inf = 1e9;
int rep(vector<int>& S, int v){
        if(S[v]!=v)
            S[v] = rep(S,S[v]);
        return S[v];
}

void unir(vector<int>& S, int u, int v){
    S[rep(S,v)] = S[rep(S,u)];  
}

int main(){
    int T; cin >> T;
    while(T--){
        int n,m,r; cin >> n >> m >> r;
        vector< vector<int> > G(n, vector<int>());
        while(m--){
            int u,v; cin >> u >> v;
            --u,--v;
            G[u].push_back(v), G[v].push_back(u);
        }
        vector<int> D(n,inf);
        queue<int> Q;
        vector<bool> vis(n,false);
        while(r--){
                int t; cin >> t;
                --t;
                D[t] = 0;
                Q.push(t);
        }
        while(not Q.empty()){
                int v = Q.front(); Q.pop();
                if(not vis[v]){
                        vis[v] = true;
                        for(int i=0; i<G[v].size(); ++i){
                            int adj = G[v][i];
                            D[adj] = min(D[adj], D[v]+1), Q.push(adj);
                        }
                }
        }
        if(D[n-1]==inf) cout << "no thugs" << endl;
        else{
            priority_queue<iii> E;
            vector<int> S(n);
            for(int i=0; i<n; ++i) S[i] = i;
            for(int i=0; i<G.size(); ++i){
                    for(int j=0; j<G[i].size(); ++j){
                            int u = i, v = G[i][j];
                            if(u<v) E.push( iii(min(D[u],D[v]),ii(u,v)) );
                    }
            }
            int ans = inf;
            while(rep(S,0)!=rep(S,n-1)){
                    iii edge = E.top();
                    E.pop();
                    int u = edge.second.first, v = edge.second.second;
                    if( rep(S,u)!=rep(S,v) ){
                            unir(S,min(u,v),max(u,v));
                            ans = min(ans, edge.first);
                    }
            }
            cout << ans << endl;
        }
    }
}