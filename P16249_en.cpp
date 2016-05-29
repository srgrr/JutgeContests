#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <unordered_map>
#include <queue>
using namespace std;

/*
    Ordenacio topologica tipica.
*/

int main(){
    #ifdef _LOCAL
    freopen("input.txt","r",stdin);
    #endif
    int n;
    while(cin >> n){
        vector<string> noms(n);
        unordered_map<string,int> indexos;
        for(int i=0; i<n; ++i){
            cin >> noms[i];
            indexos[ noms[i] ] = i;
        }
        vector< vector<int> > G(n, vector<int>());
        vector<int> indg(n,0);
        vector<bool> ok(n,false);
        int m;
        cin >> m;
        while(m--){
            string u,v;
            cin >> u >> v;
            int iu = indexos[u], iv = indexos[v];
            G[iu].push_back(iv);
            ++indg[iv];
        }

        priority_queue< string, vector<string>, greater<string> > Q;
        queue<string> ordering;
        for(int i=0; i<n; ++i) if(indg[i]==0) Q.push( noms[i] );
        while(not Q.empty()){
            int u = indexos[Q.top()];
            Q.pop();
            if(not ok[u]){
            ordering.push(noms[u]);
            ok[u] = true;
            for(int v : G[u])
                if(--indg[v]==0) Q.push(noms[v]);
            }
        }

        if(ordering.size() < n) cout << "NO VALID ORDERING";
        else{
            while(not ordering.empty()){
                cout << ordering.front();
                ordering.pop();
            }
        }
        cout << endl;

    }