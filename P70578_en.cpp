#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

/*
    Aquesta solucio fa servir una estructura de dades anomenada segment tree.
    N'hi ha implementacions molt millor fetes que aquesta. Aqui va ser la primera
    vegada que vaig implementar aixo a la meva vida.
*/

struct node{
    int l,r;
    int sum;
};

void build(vector<node>& segtree,int l, int r, int id){
    if(l<=r){
        segtree[id] = {l,r,0};
        if(l<r){
            int m = (l+r)/2;
            build(segtree,l,m, 2*id);
            build(segtree,m+1,r, (2*id)+1);
            }
    }
}

int setv(vector<node>& segtree, int id, int setval, int setz){
    int l = segtree[id].l;
    int r = segtree[id].r;
    if(setz<l or setz>r) return 0;
    if(l==r){
        segtree[id].sum = setval;
        return segtree[id].sum;
    }
    int m = (l+r)/2;
    if(setz<=m){ 
        segtree[id].sum = segtree[(2*id)+1].sum;
        segtree[id].sum += setv(segtree, (2*id), setval, setz);
    }
    else{ 
        segtree[id].sum = segtree[(2*id)].sum;
        segtree[id].sum += setv(segtree, (2*id)+1, setval, setz);
    }
    return segtree[id].sum;
    
}

int gets(vector<node>& segtree, int ql, int qr, int id){
    int l = segtree[id].l;
    int r = segtree[id].r;
    int m = (l+r)/2;
    if(ql>qr) return 0;
    if(l>qr or ql>r) return 0;
    if(l==ql and r==qr) return segtree[id].sum;
    int ret = 0;
    if(ql<=m) ret += gets(segtree, ql, min(qr,m), 2*id);
    if(qr>m) ret += gets(segtree,max(m+1,ql), qr, (2*id)+1);
    return ret;
}

int main(){
    #ifdef _LOCAL
    freopen("input.txt","r",stdin);
    #endif // _LOCAL
    char inst;
    vector<node> segtree;
    int s;
    int t=0;
    int tt=0;
    while(cin >> inst){
        if(inst=='r'){
            tt=0;
            if(t>0) cout << endl;
            ++t;
            cin >> s;
            segtree = vector<node>((1<<20));
            build(segtree,0,s,1);
        }else if(inst=='s'){
            int p,val;
            cin >> p >> val;
            setv(segtree,1,val,p);
            /*for(int i=0; i<64; ++i) cout << segtree[i].sum << ' ';
            cout << endl;*/
        }else if(inst=='g'){
            if(tt>0) cout << ' ';
            ++tt;
            int p;
            cin >> p;
            cout << gets(segtree,0,p,1);           
        }
    }