#include <iostream>
#include <unordered_map>
using namespace std;
/*
Francament, no recordo de que anava aquest problema
ni per que el codi te la comanda indent passada.

Tenia aixo a la capcalera comentat:

f(i) = xi + a
xi + a = i
a = i - xi;
*/

int
main ()
{
  int n;
  int seq = 1;
  while (cin >> n)
    {
      unordered_map < int, int >precalc;
      cout << "Sequence #" << seq++ << endl;
      for (int i = 0; i < n; ++i)
	{
	  int q;
	  cin >> q;
	  if( precalc[(i+1)-q] == 0 ) precalc[(i+1)-q] = i+1;
	}
      int m;
      cin >> m;
      for (int i = 0; i < m; ++i)
	{
	  int a;
	  cin >> a;
	  if (precalc[a] == 0)
	    {
	      cout << "no fixed point for " << a << endl;
	    }
	  else
	    {
	      cout << "fixed point for " << a << ": " << precalc[a] << endl;
	    }
	}
      cout << endl;
      precalc = unordered_map < int, int >();
    }
}