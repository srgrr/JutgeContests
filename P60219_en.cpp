#include <vector>
#include <iostream>
#include <queue>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#define EPS 0.000001f
#define inf 1000000000
#define freq second.first
#define duration second.second
using namespace std;
typedef unsigned long long int ull;
typedef pair< double, pair<ull,ull> > sortme;


/*
    Amb mantenir sets i obeir les queries es suficient.
*/


struct cmpw{

    bool operator()(string w1,string w2){
        if( w1.size() == w2.size() ) return w1 < w2;
        if( w1.size() < w2.size() ) return true;
        return false;
    }

};

int main(){
    int game = 1;
    string word;
    set< string > has;
    set< string, cmpw >had;
    while(cin >> word){
        //cout << word << endl;
        if(word == "END" or word == "QUIT"){
            cout << "GAME #" << game++ << endl << "HAS:" << endl;
            set<string>::iterator it = has.begin();
            while(it != has.end() ){
                cout << *it << endl;
                ++it;
            }
            cout << endl;
            cout << "HAD:" << endl;
            set<string>::iterator it2 = had.begin();
            while( it2 != had.end() ){
                cout << *it2 << endl;
                ++it2;
            }
            has = set<string>();
            had = set<string, cmpw >();
            if(word == "END") cout << endl;
            else return 0;
        }else{
            if( has.find(word) != has.end() ){
                has.erase( has.find(word) );
                had.insert(word);
            }else{
                has.insert(word);
                if( had.find(word) != had.end() )
                    had.erase( had.find(word) );
            }
        }
    }
}