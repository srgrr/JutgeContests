#include <iostream>
#include <sstream>
using namespace std;

/*
    Parser molt literal.
    Cada crida recursiva avalua exclusivament una instruccio,
    calculant i retornant el resultat d'aquesta.
    Les instruccions dintre d'instruccions s'avaluen amb una crida recursiva.
*/

double parse(istringstream& in){
    char inst;
    if(in >> inst){
        if(inst=='R'){
            char p;
            in >> p;
            double read;
            in >> read;
            in >> p;
            return read;
        }
        else if(inst=='S'){
            char p;
            in >> p;
            double total = 0.0;
            char separador = '.';
            while(separador!=')'){
                total += parse(in);
                in >> separador;
            }
            return total;
        }
        else if(inst=='P'){
            char p;
            in >> p;
            double total = 0.0;
            char separador = '.';
            while(separador!=')'){
                total += 1.0/parse(in);
                in >> separador;
            }
            return 1.0/total;
        }
    }
    return 0.0;
}

int main(){
    cout.setf(ios::fixed);
    cout.precision(3);
    string line;
    while(getline(cin,line)){
        istringstream ss(line);
        cout << parse(ss) << endl;
    }
}