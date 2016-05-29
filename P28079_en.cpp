#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cassert>
#include <limits>
#include <cstdio>
using namespace std;

/*
    Es fa servir un kd-tree.
    Cal tenir en compte que si l'entrada fossin punts alineats aquest
    programa petaria.
    Suposo que es pot arreglar mes o menys barrejant l'entrada aleatoriament.
*/

typedef struct{
    double c[2];
} point;

struct node{
    point p;
    node* left;
    node* right;
};

double dist( point& a, point& b ){
    return abs(a.c[0]-b.c[0])+abs(a.c[1]-b.c[1]);
}

void insert(node** kdtree, point& target, int dim){
    if( (*kdtree) == NULL ){
        (*kdtree) = (node*)new node;
        (*kdtree)->p = target;
        (*kdtree)->left = NULL;
        (*kdtree)->right = NULL;
    }else{
        if( target.c[dim] < (*kdtree)->p.c[dim] )
            insert( &(*kdtree)->left, target , (dim+1)%2 );
        else
            insert( &(*kdtree)->right, target , (dim+1)%2 );
    }
}

double answer(node* kdtree, point& query, double bestFound, int dim){
    if(kdtree != NULL){
        bestFound = min(bestFound, dist(kdtree->p, query));
        bool left = query.c[dim] <  kdtree->p.c[dim];
        if( left )
            bestFound = min(bestFound, answer(kdtree->left,query,bestFound, (dim+1)%2));
        else bestFound = min(bestFound, answer(kdtree->right,query,bestFound, (dim+1)%2) );

        if( abs( kdtree->p.c[dim]-query.c[dim] ) < bestFound )
            if( left ) bestFound = min(bestFound, answer(kdtree->right,query,bestFound, (dim+1)%2) );
            else bestFound = min(bestFound, answer(kdtree->left,query,bestFound, (dim+1)%2));

        return bestFound;
    }
    return numeric_limits<double>::infinity();
}

int main(){
    cout.setf(ios::fixed);
    cout.precision(8);
    #ifdef _LOCAL
    freopen("input.txt","r",stdin);
    #endif // _LOCAL
    int n;
    cin >> n;
    node* kdtree = NULL;
    while(n--){
        point p;
        cin >> p.c[0] >> p.c[1];
        insert(&kdtree,p,0);
    }
    int q;
    cin >> q;
    while(q--){
        point queryp;
        cin >> queryp.c[0] >> queryp.c[1];
        cout << answer(kdtree,queryp, numeric_limits<double>::infinity(), 0 ) << endl;
    }
}