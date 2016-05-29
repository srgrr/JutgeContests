#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const int MAXN = 1e5 + 9;
const int inf = 1e9 + 7;

/*
	Aquest problema apareix a la llista Divide and Conquer, pero
	francament el que vaig fer no te res a veure.

	La idea principal del meu codi es:	

	- Anomenem U a les parts de porta que estan adalt.
	- D a les que estan abaix.

	- Normalitzem les sequencies de tal forma que passin a tenir valors
	d'1 a N (N = mida de les sequencies) i conservin l'ordre original.

	- Composem les permutacions U i D

	- Calculem la longitut de la sequencia creixent mes gran a la nova permutacio.


	Probablement que la solucio no sigui aquesta perque em vaig menjar uns quants TLEs
	abans d'aconseguir colar-la.

*/


int n, p[MAXN], as[MAXN], bs[MAXN], par[MAXN], lisv[MAXN], tmp[MAXN];
unordered_map<int,int> ranka;

void compress(unordered_map<int,int>& rank) {
	rank.clear();
	sort(tmp, tmp+n);
	int kelem = -1;
	for(int i=0; i<n; ++i) {
		rank[tmp[i]] = ++kelem;
	}
}

int calc() {

	set<int> S;
	set<int>::iterator k;

	for(int i=0; i<n; ++i) {
		if(S.insert(p[i]).second) {
			k = S.find(p[i]);
			++k;
			if(k!=S.end()) {
				S.erase(k);
			}
		}
	}
	return S.size();
}

int main() {
	while(scanf("%d",&n) != EOF) {
		for(int i=0; i<n; ++i) {
			scanf("%d", &as[i]);
			tmp[i] = as[i];
		}
		for(int i=0; i<n; ++i) {
			scanf("%d", &bs[i]);
		}
		compress(ranka);
		for(int i=0; i<n; ++i) {
			p[ranka[as[i]]] = bs[i];
		}
		printf("%d\n", calc());
	}
}