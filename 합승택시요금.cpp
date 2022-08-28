#include <string>
#include <vector>
#include<algorithm>
#include<queue>
using namespace std;
int INF=100000*200;
vector<vector<int>>dist(3,vector<int>(201,INF));

void dijkstra(int start,int idx ,vector<pair<int,int>>map[]){
    dist[idx][start]=0;
    priority_queue<pair<int,int>>pq;
    pq.push(make_pair(start,0));
    while(!pq.empty()){
        int current=pq.top().first;
        int distance=-pq.top().second;
        pq.pop();
        if(dist[idx][current]<distance)continue;
        for(int i=0;i<map[current].size();i++){
            int next=map[current][i].first;
            int nextDistance=distance+map[current][i].second;
            if(nextDistance<dist[idx][next]){
                dist[idx][next]=nextDistance;
                pq.push(make_pair(next,-nextDistance));
            }
        }
    }
}
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    vector<pair<int,int>>mid;
    vector<pair<int,int>>map[n+1];
    for(int i=0;i<fares.size();i++){
        map[fares[i][0]].push_back(make_pair(fares[i][1],fares[i][2]));
        map[fares[i][1]].push_back(make_pair(fares[i][0],fares[i][2]));
    }
    dijkstra(s,0,map);
    dijkstra(a,1,map);
    dijkstra(b,2,map);
    for(int i=1;i<=n;i++){
        if(dist[0][i]==INF||dist[1][i]==INF||dist[2][i]==INF)continue;
        answer=min(answer,dist[0][i]+dist[1][i]+dist[2][i]);
    }
    return answer;
}