#include <iostream>
#include <vector>
using namespace std;

void precomp(string& P, vector<int>& B){
    int m = P.size();
    B[0] = -1;
    int i=0, j=-1;
    while(i<m){
            while(j>=0 and P[i]!=P[j]) j = B[j];
            ++i,++j;
            B[i] = j;
    }
}

int sol(string& T, string& P, vector<int>& B){
    int n = T.size(), m = P.size();
    int i = max(0, int(T.size()-B.size()-1)), j = 0; //no te sentit mirar suffixos mes llargs que patro en si
    int maxf = 0;
    while(i<n){
            while(j>=0 and T[i]!=P[j]) j = B[j];
            ++i,++j;
            if(i==n) maxf = j;
            if(j==m) j = B[j];
    }
    return maxf;
}

int main(){
    string P,T;
    while(cin>>P>>T){
        vector<int> B(P.size()+1);
        precomp(P,B);
        cout << sol(T,P,B) << endl;
    }
}