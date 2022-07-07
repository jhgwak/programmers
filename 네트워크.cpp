#include <cstring>
#include <vector>

using namespace std;
bool visit[200];
int num = 0;
void dfs(int x,vector<vector<int>>computers) {
    visit[x] = true;
    for (int i = 0; i < computers[x].size(); i++) {
        if (!visit[i] && computers[x][i] == 1) {
            dfs(i, computers);
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    memset(visit, false, sizeof(visit));
    int answer=0;
    for (int i = 0; i < n; i++) {
        if (!visit[i]) {
            num++;
            dfs(i, computers);
        }
    }
    answer =num;
    return answer;
}