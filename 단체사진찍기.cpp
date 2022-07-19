#include <string>
#include <vector>
#include<algorithm>

using namespace std;


int dist(vector<char> &v, char c) {
    for (int i = 0; i < v.size(); i++) {
        if (c == v[i]) return i;
    }
    return -1;
}

int solution(int n, vector<string> data) {
    int answer = 0;
    vector<char>Ndata = { 'A','C','F','J','M','N','R','T' };
    do {
        bool flag = true;
        for (int i = 0; i < n; i++) {
            int a = dist(Ndata, data[i][0]);
            int b = dist(Ndata, data[i][2]);
            int num = (data[i][4] - '0') + 1;

            if (data[i][3] == '=') {
                if (abs(a - b) == num) {
                    flag = true;
                }
                else flag = false;
            }
            else if (data[i][3] == '<') {
                if (abs(a - b) < num) {
                    flag = true;
                }
                else flag = false;
            }
            else {
                if (abs(a - b) > num) {
                    flag = true;
                }
                else flag = false;
            }
            if (!flag) break;
        }
        if (flag) {
            answer++;
        }
    } while (next_permutation(Ndata.begin(), Ndata.end()));
    return answer;
}