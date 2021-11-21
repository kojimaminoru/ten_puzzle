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

int main(int argc, const char * argv[]) {
    int a, b;
    vector<double> num(NUMS);
    double ans = 0.0;
    string cul = "+++", s = "8115/-/";
    //rep(i, NUMS) cin >> num[i];
    
    ans = ReversePolishNotation(s);
    cout << ans << endl;
    return 0;
}
