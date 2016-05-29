#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

/*
    Backtracking.
*/

void backtrack(int c1,int c2,int c3,bool adj,list<int>& sol,int ans){
    if( c1 == 0 and c2 == 0 and c3 == 0 and adj ){
        list<int>::iterator it = sol.begin();
        while(it != sol.end() ){
            cout << *it;
            ++it;
        }
        cout << endl;
    }else if(c1>=0 and c2>=0 and c3>=0){
        if(c1 and not adj or (adj and ans != 1)){
            sol.push_back(1);
            backtrack(c1-1,c2,c3,adj or ans == 1,sol,1);
            sol.pop_back();
        }
        if(c2 and not adj or (adj and ans != 2)){
            sol.push_back(2);
            backtrack(c1,c2-1,c3,adj or ans == 2,sol,2);
            sol.pop_back();
        }
        if(c3 and not adj or (adj and ans != 3)){
            sol.push_back(3);
            backtrack(c1,c2,c3-1,adj or ans == 3,sol,3);
            sol.pop_back();
        }

    }
}

int main(){
    int n;
    while(cin >> n){
        list<int> sol;
        backtrack(n,n,n,false,sol,5);
        cout << "**********" << endl;
    }
}