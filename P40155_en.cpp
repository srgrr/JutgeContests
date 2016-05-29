#include <bits/stdc++.h>
using namespace std;

/*
    Implementacio bastant straight-forward
    de l'algorisme shunting yard.
    Es preprocessa la cadena i s'obte una expressio
    en notacio prefix (per exemple, 2+2 seria + 2 2),
    la qual es molt facil d'avaluar fent servir piles.
*/

int exp(string& iss) {
    stack<char> pending;
    queue<char> rpn;
    char t;
    for(int i=0; i<iss.size(); ++i) {
        t = iss[i];
        if(t >= '0' and t <= '9') rpn.push(t);
        else if(t == '(') {
            pending.push('(');
        }
        else if(t == ')') {
            while(pending.top() != '(') {
                rpn.push(pending.top());
                pending.pop();
            }
            pending.pop();
        }
        else {

            if(t == '+' or t == '-') {
                while(not pending.empty() and pending.top() != '(' and pending.top() != ')') {
                    rpn.push(pending.top());
                    pending.pop();
                }
            }else {
                while(not pending.empty() and (pending.top() == '*' or pending.top() == '/')) {
                    rpn.push(pending.top());
                    pending.pop();
                }
            }
            pending.push(t);
        }
    }
    while(not pending.empty()) {
        rpn.push(pending.top());
        pending.pop();
    }
    stack<int> nums;
    while(not rpn.empty()) {
        char x = rpn.front(); rpn.pop();
        //cout << x << ' ';
        if(x >= '0' and x <= '9') nums.push(int(x-'0'));
        else {
            int op2 = nums.top(); nums.pop();
            int op1 = nums.top(); nums.pop();
            if(x == '+') nums.push(op1+op2);
            if(x == '-') nums.push(op1-op2);
            if(x == '/') nums.push(op1/op2);
            if(x == '*') nums.push(op1*op2);
        }
    }
    //cout << endl;
    return nums.top();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string line;
    while(cin >> line) {
        cout << exp(line) << endl;
    }
}
