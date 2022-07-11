#include <string>
#include <vector>
#include<algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    sort(routes.begin(), routes.end());
    int start = 0;
    int end = routes[0][1];
    for (int j = 1; j < routes.size(); j++) {
        if (end >= routes[j][0] && end <= routes[j][1]) {
            start = routes[j][0];
            end = end;
        }
        else if (end >= routes[j][0] && end>= routes[j][1]) {
            start = routes[j][0];
            end = routes[j][1];
        }
        else {
            answer++;
            start = routes[j][0];
            end=routes[j][1];
        }
    }
    return answer;
}