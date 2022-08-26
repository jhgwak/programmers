#include <string>
#include <vector>
#include<map>
using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    vector<vector<char>> name = {{'R', 'T'},
                                 {'C', 'F'},
                                 {'J', 'M'},
                                 {'A', 'N'}};
    map<char, int> m = {{'R', 0},
                        {'T', 0},
                        {'C', 0},
                        {'F', 0},
                        {'J', 0},
                        {'M', 0},
                        {'A', 0},
                        {'N', 0}};
    for (int i = 0; i < survey.size(); i++) {
        if (choices[i] == 4) {
            continue;
        } else if (choices[i] > 4) {
            m[survey[i][1]] = m[survey[i][1]] + choices[i] - 4;
        } else if (choices[i] < 4) {
            m[survey[i][0]] = m[survey[i][0]] + 4 - choices[i];
        }
    }
    for (int i = 0; i < name.size(); i++) {
        if (m[name[i][0]] == m[name[i][1]]) {
            if (name[i][0] > name[i][1]) {
                answer = answer + name[i][1];
            } else {
                answer = answer + name[i][0];
            }
        } else if (m[name[i][0]] > m[name[i][1]]) {
            answer = answer + name[i][0];
        } else if (m[name[i][0]] < m[name[i][1]]) {
            answer = answer + name[i][1];
        }
    }
    return answer;

}