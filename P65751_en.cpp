#include <bits/stdc++.h>
using namespace std;
struct point{
    double x,y;
};

/*
    La idea es fer una programacio dinamica que talli en dos
    el poligon actual amb una diagonal cada vegada.

    Cal precalcular les distancies o dona TLE.
*/

int n;
point v[101];
double D[101][101];
double DP[101][101];

inline double sqrtdist(point& a, point& b) {
    return sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) );
}

inline int mod(int a, int b) {
    return ((a%b)+b)%b;
}

inline bool distg(int i, int j) {
    int k = 0;
    while(i!=j) {
        ++k;
        if(k>2) return true;
        i = (i+1)%n;
    }
    return false;
}

double solve(int i, int j) {
    if(DP[i][j]>=1e27) {
        if(not distg(i,j))
            DP[i][j] = 0.0;
        else {
            int k = (i+1)%n;
            bool ite = false;
            while(k!=j) {
                ite = true;
                double addup = 0.0;
                if(k!=(i+1)%n and k!=mod(i-1,n) and k!=i) addup += D[i][k];
                if(k!=(j+1)%n and k!=mod(j-1,n) and k!=j) addup += D[j][k];
                DP[i][j] = min(DP[i][j], addup + solve(i,k)+solve(k,j));
                k = (k+1)%n;
            }
            if(not ite) DP[i][j] = 0.0;
        }
    }
    return DP[i][j];
}

int main() {
    while(scanf("%d",&n)==1) {
        bool isCcw = true;
        for(int i=0; i<n; ++i)
            scanf("%lf %lf", &v[i].x, &v[i].y);
        for(int i=0; i<n; ++i)
            for(int j=i+1; j<n; ++j) D[i][j] = D[j][i] = sqrtdist(v[i], v[j]), DP[i][j] = DP[j][i] = 1e28;
         printf("%.4lf\n", solve(0,n-1));
    }
}