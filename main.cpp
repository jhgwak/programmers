#include <string>
#include <vector>

using namespace std;

void devide(string& u, string& v,string p) {
    int ucnt = 0;
    int vcnt = 0;
    u = "";
    v = "";
    for (int i = 0; i < p.size(); i++) {
        if (p[i] == '(') {
            ucnt++;
        }
        else {
            vcnt++;
        }
        if (ucnt == vcnt) {
            for (int i = 0; i < ucnt + vcnt; i++) {
                u = u + p[i];
            }
            for (int i = ucnt + vcnt; i < p.size(); i++) {
                v = v + p[i];
            }
            break;
        }
    }
}
string check(string& u, string &v, string p) {
    devide(u, v, p);
    if (p.size() == 0) {//최종적 단계임
        return v;
    }
    string k=u;
    if(u[0]=='('){
        return k+check(u,v,v);
    }
    else {//재귀적 로직
        string x = "";//u 의 과정
        for (int i = 0; i < u.size(); i++) {
            if (i == 0 || i == u.size() - 1) {
                continue;
            }
            else {
                if (u[i] == '(') {
                    x = x + ')';
                }
                else {
                    x = x + '(';
                }
            }
        }
        return '(' + check(u, v, v) + ')' + x;
    }
}
string solution(string p) {
    string answer = "";
    string u;
    string v;
    if(p.size()==0){
        return "";
    }
    else{
        answer = check(u, v, p);
    }
    return answer;
}