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
    vector<int> poz = {0, 2, 4, 6};
    string tmp = "";
    tmp += s[0];
    s.substr(1);
    while(s != ""){
        if(isOpe(s[0])){
            tmp[space(tmp)] = s[0];
            s = s.substr(1);
        }
        else {
            tmp += " ";
            tmp += s[0];
            s = s.substr(1);
        }
    }
    return tmp;
}

int main(int argc, const char * argv[]) {
    int a, b;
    vector<double> num(NUMS);
    double ans = 0.0;
    string cul = "+++", s = "1234/-/", c = "aaabbbccc";
    //rep(i, NUMS) cin >> num[i];
    
    ans = ReversePolishNotation(s);
    cout << ans << endl;
    cout << Tenset(s) << endl;
    return 0;
}
