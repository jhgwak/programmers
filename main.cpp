#include <vector>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;
vector<int>dist(51,1000000);
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

int main() {
    int N=5;
    vector<vector<int>>road={{1,2,1},{2,3,3},{5,2,2},{1,4,2},{5,3,1},{5,4,2}};
    int K=3;
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
    cout<<answer;
}
