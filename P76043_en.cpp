#include <iostream>
#include <list>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int inf = 1000000000;

/*
    La idea era fer un dijkstra amb un graf
    amb pesos zero o u en funcio de si el vertex de
    desti estava pintat o no.
*/

int main(){
    int n,x,y;
    while(cin >> n >> x >> y){
        vector< vector<int> > G(n, vector<int>());
        vector< bool > pintat(n,false);
        vector< bool > vis(n,false);
        vector< int  > distancies(n,inf);
        int m;
        cin >> m;
        while(m--){
            int u,v;
            cin >> u >> v;
            G[u].push_back(v);
        }
        int p;
        cin >> p;
        while(p--){
            int v;
            cin >> v;
            pintat[v] = true;
        }
        distancies[x] = pintat[x] ? 0 : 1;

        priority_queue< ii, vector<ii>, greater<ii> > Q;
        Q.push( make_pair(distancies[x],x) );
        while(not Q.empty()){
            int v = Q.top().second;
            Q.pop();
            if(not vis[v]){ //suposem que el vertex ja esta pintat aqui
                vis[v] = true;
                for(int i=0; i<G[v].size(); ++i){
                    int adj = G[v][i];
                    int pesadj = pintat[adj] ? 0 : 1;
                    distancies[adj] = min(distancies[adj], distancies[v]+pesadj );
                    Q.push(make_pair(distancies[adj],adj) );
                }
            }
        }

        if(distancies[y]==inf) cout << "impossible" << endl;
        else cout << distancies[y] << endl;

    }
}