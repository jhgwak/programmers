#include <string>
#include <vector>
#include<map>
#include<algorithm>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string>a;
    string value = "";
    map<string, string> m;
    vector<pair<int, string>> re;
    for (int i = 0; i < record.size(); i++) {
        for (int j = 0; j < record[i].size(); j++) {
            if (record[i][j] == ' ') {
                a.push_back(value);
                value = "";
            }
            else {
                value = value + record[i][j];
            }
        }
        a.push_back(value);
        value = "";
    }
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == "Enter") {
            m[a[i + 1]] = a[i + 2];
            re.push_back(make_pair(0, a[i + 1]));
            i = i + 2;
        }
        else if (a[i] == "Leave") {
            re.push_back(make_pair(1, a[i + 1]));
            i = i + 1;
        }
        else if (a[i] == "Change") {
            m[a[i + 1]] = a[i + 2];
            i = i + 2;
        }
    }

    for (int i = 0; i < re.size(); i++) {
        if (re[i].first == 0) {//Enter 일때임
            string val = m.find(re[i].second)->second + "님이 들어왔습니다.";
            answer.push_back(val);
        }
        else if (re[i].first == 1) {//Leave 일때
            string val2 = m.find(re[i].second)->second + "님이 나갔습니다.";
            answer.push_back(val2);
        }
    }
    return answer;
}