#include <iostream>
#include <vector>
using namespace std;

/*
	La idea era, havent fixat dos vertexs u i v
	comptar quants x havia tal que hi hagues un cami u-x-v
	Calculant k choose 2 (k = nombre d'xs valides) tenim
	el nombre de maneres en que es poden triar aquests xs
	per a fer un quadrat.
	Donat que comptarem 4 vegades cada quadrat, dividim el resultat per quatre i ja
	estem.
*/

int main(){
	int n,m;
	while(cin >> n >> m){
		vector< vector<int> > G(n,vector<int>() );
		while(m--){
			int u,v;
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		int total = 0;
		for(int i=0; i<n; ++i){
			vector<int> maneres(n,0);
			for(int j=0; j<G[i].size(); ++j){
				int adj = G[i][j];
				for(int k=0; k<G[adj].size(); ++k){
					int adjadj = G[adj][k];
					++maneres[adjadj];
				}
			}
			for(int j=0; j<n; ++j){
			total += i==j ? 0 : (maneres[j]*(maneres[j]-1)) / 2;
			}
		}
		cout << total/4 << endl;
	}
}