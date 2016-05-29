#include <iostream>
#include <queue>
#define inf 1000000000
#define peso first
#define adj  second
using namespace std;
typedef pair<int,int> Arc; // first = peso , second = adj

/*
    Fent un Dijkstra multifont es podia resoldre.
    (Es a dir, la cua te diversos nodes d'inici).
*/

void Dijkstra( vector< vector<Arc> >& G, vector< int > & acumulados, vector<int>& bomberos, vector<int>& parques){
    priority_queue< Arc , vector< Arc > , greater < Arc > > Q;
    for(int i = 0; i < parques.size() ; ++i){
        Q.push( Arc(0,parques[i]));
    }
    while( not Q.empty() ){
        int v = Q.top().adj;
        //cout << v << endl;
        Q.pop();
            for(int i = 0 ; i < G[v].size() ; ++i){
                int ady = G[v][i].adj;
                int pes = G[v][i].peso;

                if( acumulados[ady] > acumulados[v]+pes ){
                    bomberos[ady] = bomberos[v];
                    acumulados[ady] = acumulados[v]+pes;
                    Q.push( Arc(acumulados[ady],ady) );
                }else if( acumulados[ady] == acumulados[v] + pes and bomberos[v] < bomberos[ady]) bomberos[ady] = bomberos[v];

            }
    }
}

int main(){
    int casos;
    cin >> casos;
    for(int c = 1 ; c <= casos ; ++c){
        int n,m;
        cin >> n >> m;
        vector< vector<Arc> > G(n, vector<Arc>() );
        vector< int > acumulados(n, inf);
        vector< int > bomberos(n,inf);
        for(int i = 0 ; i < m ; ++i){
            int u,v,w;
            cin >> u >> v >> w;
            G[u].push_back( Arc(w,v) );
            G[v].push_back( Arc(w,u) );
        }

        int k;
        cin >> k;
        vector< int > parques(k,inf);
        for(int i = 0 ; i < k ; ++i){
            int ciudad;
            cin >> ciudad;
            acumulados[ciudad] = 0;
            bomberos[ciudad] = ciudad;
            parques[i] = ciudad;
        }
        Dijkstra(G,acumulados,bomberos,parques);
        cout << "Case #" << c << endl;
        int q;
        cin >> q;
        for(int i = 0 ; i < q ; ++i ){
            int d;
            cin >> d;
            cout << "To get to " << d << ", distance " << acumulados[d] << ", from city " << bomberos[d] << '.' << endl;
        }
        if(c < casos) cout << endl;
    }
}