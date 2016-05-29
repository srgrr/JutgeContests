#include <iostream>
#include <cmath>
#define EPS 1e-9
using namespace std;

/*
	Aquest problema consistia a igualar dues funcions
	i obtenir el punt d'interseccio.

	De les funcions sabiem que una era mes petita que l'altra
	al principi, per tant es pot fer una cerca binaria.

	Els valors d'avaluar la funcio podien ser molt grans, aixi que
	ho vaig fer tot amb logaritmes (ja que treballes amb valors mes petits
	i la igualtat es mante).
*/

bool appr( double a, double b ){
	return abs(a-b) < EPS;
}

int main(){
	double m,f,r;
	while( cin >> m >> f >> r ){
		r = 1.0 + (r/100.0) ;
		double start = 0.0, end = 1e7,half;
		double d;
		while( start <= end ){
			d = (start+end)/2.0f;

			double oak_h = log(m + d*f);
			double bank_h = log( m ) + d*log(r);

			if( appr(oak_h,bank_h) ) break;			

			if( bank_h > oak_h ) end = d - EPS;
			else start = d + EPS;
		}
		if( d < 1 ) d = 1.0f;
		cout << unsigned( ceil(d) ) << endl;
	}
}