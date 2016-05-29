#include <sstream>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <list>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <stack>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <bitset>
#define pb push_back
#define mp make_pair
#define X first
#define Y second
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef unsigned int nat;
typedef long double ld;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef pair<int,int> pii;

/*
    Si no recordo malament, aixo es diu o algorisme de Tarjan o Kosaraju
    (no recordo quin dels dos era aquest)
*/

void dfs(vvi& G, vector<bool>& ok, int v, stack<int>& ord){
    if(not ok[v]){
        ok[v] = true;
        for(int i=0; i<G[v].size(); ++i)
            dfs(G,ok,G[v][i],ord);
        ord.push(v);
    }
}

void ssc(vvi& GT, vector<bool>& ok, int v){
    if(not ok[v]){
        ok[v] = true;
        for(int i=0; i<GT[v].size(); ++i)
            ssc(GT,ok,GT[v][i]);
    }
}

int main(){
    #ifdef _LOCAL
    freopen("input.txt","r",stdin);
    #endif // _LOCAL
    int T;
    cin >> T;
    for(int c=1; c<=T; ++c){
        int n,m;
        cin >> n >> m;
        vvi G(n,vi());
        vvi GT(n,vi());
        while(m--){
            int u,v;
            cin >> u >> v;
            G[u].push_back(v);
            GT[v].push_back(u);
        }
        vector<bool> visG(n,false);
        vector<bool> visGT(n,false);
        stack<int> ord;
        for(int i=0; i<n; ++i)
            dfs(G,visG,i,ord);

        int ret=0;

        while(not ord.empty()){
            int v = ord.top();
            ord.pop();
            if(not visGT[v]){
                ++ret;
                ssc(GT,visGT,v);
            }
        }

        cout << "Graph #" << c << " has " << ret << " strongly connected component(s)." << endl;

    }
}