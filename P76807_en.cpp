#include <iostream>
#include <vector>
using namespace std;

/*
	Es tracta d'un backtraking prou normal.
	Si no es te cap solucio valida, es poda la branca i es torna enrera.
*/

bool tester(vector< vector<char> >& s,int x,int y,char k){
	for(int i=0;i<9;++i)
		if( s[x][i] == k ) return false;
	for(int i=0;i<9;++i)
		if( s[i][y] == k ) return false;
	for(int i=(x-(x%3) );i<(x-(x%3)+3) ; ++i)
		for(int j=( y-(y%3) );j<( y-(y%3)+3 ) ; ++j)
			if( s[i][j] == k ) return false;
	return true;

}

void troba_sol(vector< vector<char> >& s,int act,bool& stop){
	if(stop) return;	
	int x = act/9;
	int y = act%9;
	if( act == 81 ){
		stop=true;
		for(int i=0;i<9;++i){
			cout << s[i][0];
			for(int j=1;j<9;++j)
				cout << ' ' << s[i][j];
			cout << endl;
		}
	}else if( s[x][y] == '.' and not stop){
		for(int i=1;i<=9;++i)
			if( tester(s,x,y,i+'0') ){ 
				s[x][y]=i+'0';
				troba_sol(s,act+1,stop);
				s[x][y]='.';
			}
	}else if(not stop) troba_sol(s,act+1,stop);
}

int main(){
	int n;
	cin >> n;
	cout << n << endl;
	for(int i=0;i<n;++i){
		bool bolinga=false;
		vector< vector<char> > s(9, vector<char>(9) );
		for(int j=0;j<9;++j)
			for(int k=0;k<9;++k)
				cin >> s[j][k];
		cout << endl;
		troba_sol(s,0,bolinga);
	}
}