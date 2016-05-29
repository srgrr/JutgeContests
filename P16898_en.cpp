#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector< vector<char> > board;

int dx[8] = {0, 0,1,-1,1,-1, 1,-1};
int dy[8] = {1,-1,0, 0,1,-1,-1, 1};

bool legal(board& b, int i, int j){
    return i>=0 and i<b.size() and j>=0 and j<b[0].size();
}

int mindg(int* p, board& b){
    vector<bool> ok(10,true);
    for(int i=0; i<2; ++i){
            for(int j=0; j<4; ++j){
                int oi = p[(i*2)  ]+dx[j];
                int oj = p[(i*2)+1]+dy[j];
                if(legal(b,oi,oj))
                    if(b[oi][oj]!='X') ok[b[oi][oj]-'0'] = false;  
            }
    }
    for(int i=0; i<10; ++i) if(ok[i]) return i;
    return -1; //no deberia
}

void backtrack(int falten, board& B, vector<board>& v){
    if(falten==0){ 
        /*for(int i=0; i<B.size(); ++i){
            for(int j=0; j<B[0].size(); ++j) cout << B[i][j];
            cout << endl;
        }
        cout << endl;*/
        v.push_back(B);
    }
    else{
        /*for(int i=0; i<B.size(); ++i){
            for(int j=0; j<B[0].size(); ++j) cout << B[i][j];
            cout << endl;
        }
        cout << endl;*/
        bool ok = false;
        for(int i=0; i<B.size() and not ok; ++i){
            for(int j=0; j<B[0].size() and not ok; ++j){
                if(B[i][j]=='X'){
                    int p1[4] = {i,j,i+1,j};
                    int p2[4] = {i,j,i,j+1};
                    if(legal(B,p1[2],p1[3]) and B[p1[2]][p1[3]]=='X'){
                        ok = true;
                        char digit = mindg(p1,B)+'0';
                        B[p1[0]][p1[1]] = B[p1[2]][p1[3]] = digit;
                        backtrack(falten-2,B,v);
                        B[p1[0]][p1[1]] = B[p1[2]][p1[3]] = 'X';
                    }
                    if(legal(B,p2[2],p2[3]) and B[p2[2]][p2[3]]=='X'){
                        ok = true;
                        char digit = mindg(p2,B)+'0';
                        B[p2[0]][p1[1]] = B[p2[2]][p2[3]] = digit;
                        backtrack(falten-2,B,v);
                        B[p2[0]][p1[1]] = B[p2[2]][p2[3]] = 'X';                        
                    }
                }
            }
        }
    }
}

bool crit(const board& a, const board& b){
    for(int i=0; i<a.size(); ++i){
        for(int j=0; j<a[0].size(); ++j){
            if(a[i][j] < b[i][j]) return true;
            if(a[i][j] > b[i][j]) return false;
        }
    }
    return true;
}


int main(){
    int n,m; cin >> n >> m;
    board current(n, vector<char>(m,'X'));
    vector< board > v; 
    backtrack(n*m,current,v);
    sort(v.begin(), v.end(), crit);
    for(int i=0; i<v.size(); ++i){
            for(int j=0; j<n; ++j){
                for(int k=0; k<m; ++k) cout << v[i][j][k];
                cout << endl;
            }
            cout << endl;
    }
}