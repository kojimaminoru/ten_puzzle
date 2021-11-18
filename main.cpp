#include <iostream>
#include <vector>
#include <string.h>
#include <stack>
using namespace std;
#define rep(i, b) for(int i = 0; i < int(b); i++)
#define NUMS 4
#define TARGET 10

bool isOpe(char c){
    if(c == '+' || c == '-' || c == '*' || c == '/') return 1;
    else return 0;
}

double ReversePolishNotation(string s){
    double ans = 0.0;
    stack<double> list;
    while(s != ""){
        if(isOpe(s[0])){
            // korekara kaku
        }
        else {
            list.push(s[0]);
            s = s.substr(1);
        }
    }
    while(list.size() != 0){
        cout << list.top() << " ";
        list.pop();
    }
    return ans;
}

int main(int argc, const char * argv[]) {
    int a, b;
    vector<int> num(NUMS);
    string cul = "+++", s = "12+23**";
    rep(i, NUMS) cin >> num[i];
    
    ReversePolishNotation(s);
    
    cout << a << b << endl;
    return 0;
}
