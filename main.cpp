#include <iostream>
#include <vector>
#include<queue>
using namespace std;
vector<int>dist(51,10000000000);
void dijkstra(vector<vector<int>>MAP,int start,int K){
    priority_queue<pair<int,int>>q;
    q.push({0,start});
    dist[start]=0;
    while(!q.empty()){
        int loc=q.top().second;
        int cost=-q.top().first;
        q.pop();
        for(int i=1;i<MAP[loc].size();i++){
            if(MAP[loc][i]!=0&&MAP[loc][i]+cost<=K&&dist[i]>MAP[loc][i]+cost){
                dist[i]=MAP[loc][i]+cost;
                q.push({-dist[i],i});
            }
        }
    }
}
int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    vector<vector<int>> MAP(N + 1, vector<int>(N + 1));
    for (int i = 0; i < road.size(); i++) {
        if(MAP[road[i][0]][road[i][1]]==0){
            MAP[road[i][0]][road[i][1]] = road[i][2];
            MAP[road[i][1]][road[i][0]] = road[i][2];
        }
        else{
            if(MAP[road[i][0]][road[i][1]]<road[i][2]){
                continue;
            }
            else{
                MAP[road[i][0]][road[i][1]] = road[i][2];
                MAP[road[i][1]][road[i][0]] = road[i][2];
            }
        }
    }
    dijkstra(MAP, 1, K);
    for(int i=1;i<N+1;i++){
        if(dist[i]<=K){
            answer++;
        }
    }
    return answer;
}