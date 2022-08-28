#include <string>
#include <vector>
#include<algorithm>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    int count = 0;
    sort(results.begin(), results.end());
    vector<vector<int>>m(n,vector<int>(n));
    for (int i = 0; i < results.size(); i++) {
        m[results[i][0] - 1][results[i][1] - 1] = 1;
        m[results[i][1] - 1][results[i][0] - 1] = -1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (m[j][i] == 1 && m[i][k] == 1) {
                    m[j][k] = 1;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (m[j][i] == -1 && m[i][k] == -1) {
                    m[j][k] = -1;
                }
            }
        }
    }
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[i].size(); j++) {
            if (m[i][j] == 0) {
                count++;
            }
        }
        if (count == 1) {
            answer++;
            count=0;
        }
        else {
            count = 0;
        }
    }
    return answer;
}