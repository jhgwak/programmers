#include <string>
#include <vector>
#include<queue>
#include <algorithm>
using namespace std;
vector<bool> check(20000);
int bfs(int start,vector<vector<int>>graph){
    queue<int> q;
    int count=1;
    int answer=0;
    int x=0;
    check[start]=true;
    for (int i = 0; i < graph[start].size(); i++) {
        q.push(graph[start][i]);
        check[graph[start][i]] = true;
    }
    x=q.size();
    while(!q.empty()){
        int tmp=q.front();
        q.pop();
        x--;
        for (int i = 0; i < graph[tmp].size(); i++) {
            if (check[graph[tmp][i]] == false) {
                q.push(graph[tmp][i]);
                check[graph[tmp][i]] = true;
            }
        }
        if (x == 0) {
            if(q.size()==0){
                continue;
            }
            else{
                answer=q.size();
                x=q.size();
            }
        }
    }
    return answer;
}
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>>a(n+1);
    sort(edge.begin(), edge.end());
    for (int i = 0; i < edge.size(); i ++ ) {
        a[edge[i][0]].push_back(edge[i][1]);
        a[edge[i][1]].push_back(edge[i][0]);
    }
    for (int i = 1; i < a.size(); i++) {
        sort(a[i].begin(), a[i].end());
    }
    answer=bfs(1,a);
    return answer;
}