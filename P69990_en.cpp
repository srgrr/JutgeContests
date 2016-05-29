#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const double EPS = 1e-9;
const int inf = 1e9;

int dist(int a, int b){
    return min(abs(b-a), min(abs((360-b)+a),(360-a)+b));
}

int dist_horari(int a, int b){
    int d = max(a,b) - min(a,b);
    if(a<b) return 360-d;
    return d;
}


int dist_antihorari(int a, int b){
    return 360-dist_horari(a,b);
}

int main(){
        cout.setf(ios::fixed);
        cout.precision(4);
        int i,g;
        while(cin >> i >> g){
            int aiv,n; cin >> aiv >> n;
            if(n==1){
                int alp; cin >> alp;
                if(aiv==alp) cout << 0.0 << endl;
                else if(i>=g) cout << "never" << endl;
                else{
                    int d = dist(alp,aiv);
                    cout << fabs(double(d)/double(i-g)) << endl;
                }
                continue;
            }
            else{
                bool cagada = false;
                int prop_horari = inf;
                int prop_antihorari = inf;
                while(n--){
                    int alp; cin >> alp;
                    if(alp==aiv) cagada=true;
                    prop_horari = min(prop_horari, dist_horari(aiv,alp));
                    prop_antihorari = min(prop_antihorari, dist_antihorari(aiv,alp));
                }
                if(cagada){
                    cout << 0.00 << endl;
                    continue;
                }
                if(i>=g){
                    cout << double(prop_horari+prop_antihorari)/2.0/double(g) << endl;
                }
                else{
                    cout << double(min( double(min(prop_horari,prop_antihorari)/double(g-i)), double(prop_horari+prop_antihorari)/2.0/double(g) )) << endl;
                }
            }
        }
}