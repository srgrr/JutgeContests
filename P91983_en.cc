#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int INF = 1e5 + 9;

/*
    Es un arbre, a no ser que sigui un xurro has de revisitar arestes,
    la pregunta es quantes i com ho podem minimitzar.

    Si comences en una fulla de l'arbre i tornes alla, faras 2 * (n - 1) passes, ja que tornar de cada subarbre implica revisitar l'aresta per la qual hem vingut.

    L'enunciat ens deixa clar que podem acabar en un vertex diferent al qual hem comencat.
    Aixo vol dir que hi ha un cami el qual no hem de revisitar, si ho visualitzem:

    A -> B -> C
    \_D  \_E  \_F

    Revisitar A-D, B-E i C-F es inevitable, pero ningu ens impedeix visitar
    A -> B -> C un unic cop.
*/

vector< int > bfs(vector< vector< int > >& g, int r) {
    int n = g.size();
    vector< int > dis(n, INF);
    dis[r] = 0;
    queue< int > q;
    q.push(r);
    vector< int > ret(2, 0);
    while (!q.empty()) {
        int u = q.front();
        if (dis[u] > ret[0]) {
            ret = {dis[u], u};
        }
        q.pop();
        for (int v: g[u]) {
            int dv = dis[v];
            if (dis[v] == INF) {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    return ret;
}

int main() {
    int n;
    while (cin >> n) {
        vector< vector< int > > g(n, vector< int > ());
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        auto d = bfs(g, bfs(g, 0)[1])[0];
        cout << 2 * (n - 1) - d << endl;
    }
}
