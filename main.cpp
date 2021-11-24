#include <iostream>
#include <vector>
#include <string.h>
#include <stack>
#include <math.h>
using namespace std;
#define rep(i, b) for(int i = 0; i < int(b); i++)
#define NUMS 4
#define TARGET 10
#define delta 1e-14

bool isOpe(char c){
    if(c == '+' || c == '-' || c == '*' || c == '/') return 1;
    else return 0;
}

double ReversePolishNotation(string s){
    double ans = 0.0, a = 0, b = 0;
    stack<double> list;
    while(s != ""){
        if(isOpe(s[0])){
            if(s[0] == '+'){
                a = list.top();
                list.pop();
                b = list.top();
                list.pop();
                list.push(b + a);
            }
            else if(s[0] == '-'){
                a = list.top();
                list.pop();
                b = list.top();
                list.pop();
                list.push(b - a);
            }
            else if(s[0] == '*'){
                a = list.top();
                list.pop();
                b = list.top();
                list.pop();
                list.push(b * a);
            }
            else if(s[0] == '/'){
                a = list.top();
                list.pop();
                b = list.top();
                list.pop();
                if(fabs(a) < delta){
                    cout << "division by zero" << endl;
                    s = "no";
                    break;
                }
                list.push(b / a);
            }
            s = s.substr(1);
        }
        else {
            list.push(s[0] - '0');
            s = s.substr(1);
        }
    }
    if(s == "no" || list.size() != 1){
        ans = -100000;
    }
    else ans = list.top();
    return ans;
}

void insert_paren(string &s, int l, int r){
    s.insert(l, "(");
    s.insert(r+2, ")");
}

int space(string s){
    rep(i, s.size()) if(s[s.size()-1-i] == ' ') return s.size()-1-i;
    return -1;
}

string Tenset(string s){
    stack<string> list;
    string a = "", b = "", tmp = "";
    while(s != ""){
        tmp = "(";
        if(isOpe(s[0])){
            a = list.top();
            list.pop();
            tmp += list.top();
            list.pop();
            tmp += s[0];
            tmp += a;
            tmp += ")";
            list.push(tmp);
            s = s.substr(1);
        }
        else {
            list.push(s.substr(0,1));
            s = s.substr(1);
        }
    }
    return list.top();
}

string Allset(int a0, int a1, int a2, int a3){
    vector<double> set(4);
    set[0] = a0, set[1] = a1, set[2] = a2, set[3] = a3;
    string s = "";
    
    return s;
}

int main(int argc, const char * argv[]) {
    int a, b;
    vector<double> num(NUMS);
    double ans = 0.0;
    string cul = "+++", s = "6234/-+", c = "aaabbbccc";
    //rep(i, NUMS) cin >> num[i];
    
    
    
    ans = ReversePolishNotation(s);
    cout << ans << endl;
    cout << Tenset(s) << endl;
    return 0;
}
