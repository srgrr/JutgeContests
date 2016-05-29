#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

/*
    Era bastant tedios parsejar l'input i donar l'output sense errors.
    Apart d'aixo, es bastant literal.
*/

void cartprod(int lista, list<int>&sol, vector< vector<int> >&L, bool last){
    if( lista == L.size() ){
        list<int>::iterator it = sol.begin();
        while(it != sol.end()){
            cout << *it;
            ++it;
            if(it != sol.end() )cout << ',';
            else{
                if( not last ) cout << '|';
                else cout << '.';
            }
        }
    }else{
        for(int i=0; i<L[lista].size(); ++i){
            sol.push_back(L[lista][i]);
            cartprod(lista+1,sol,L,last and i==L[lista].size()-1);
            sol.pop_back();
        }
    }
}

int main(){
    char c = 'a';
    bool ok = true;
    while(ok){
        vector< vector<int> > L(1);
        int act = 0;
        int read;
        while( (ok = (scanf("%d%c",&read,&c)!=EOF)   ) ){
            L[act].push_back(read);
            if(c=='|') L.push_back( vector<int>() ), ++act;
            if(c=='.') break;
        }
        if(ok){
        list<int> sol;
        cartprod(0,sol,L,true);
        cout << endl;
        }
        /*for(int i=0; i<L.size();++i){
            for(int j=0; j<L[i].size(); ++j) cout << L[i][j] << ' ';
                    cout << "\\";
        }
        cout << endl;*/
    }
}