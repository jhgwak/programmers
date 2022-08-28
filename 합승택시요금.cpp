#include <string>
#include <vector>
#include<algorithm>
#include<queue>
using namespace std;
int INF=100000*200;
vector<int>dist(201,INF);

void dijkstra(int start, vector<pair<int,int>>map[]){
    dist[start]=0;
    priority_queue<pair<int,int>>pq;
    pq.push(make_pair(start,0));
    while(!pq.empty()){
        int current=pq.top().first;
        int distance=-pq.top().second;
        pq.pop();
        if(dist[current]<distance)continue;
        for(int i=0;i<map[current].size();i++){
            int next=map[current][i].first;
            int nextDistance=distance+map[current][i].second;
            if(nextDistance<dist[next]){
                dist[next]=nextDistance;
                pq.push(make_pair(next,-nextDistance));
            }
        }
    }
}
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    vector<pair<int,int>>mid;
    vector<pair<int,int>>map[n+1];
    for(int i=0;i<fares.size();i++){
        map[fares[i][0]].push_back(make_pair(fares[i][1],fares[i][2]));
        map[fares[i][1]].push_back(make_pair(fares[i][0],fares[i][2]));
    }
    dijkstra(s,map);
    mid.push_back(make_pair(0,dist[a]+dist[b]));//합승 안함
    for(int i=1;i<n+1;i++){
        if(i==s||dist[i]==INF)continue;
        else{
            mid.push_back(make_pair(i,dist[i]));
        }

    }
    //for(int i=1;i<n+1;i++){
    //  dist[i]=INF;
    //}
    for(int i=1;i<mid.size();i++){
        answer=mid[i].second;
        dijkstra(mid[i].first,map);
        answer=answer+dist[b]+dist[a];
        if(mid[0].second>answer){
            mid[0].second=answer;
        }
        for(int i=1;i<n+1;i++){
            dist[i]=INF;
        }
    }
    answer=mid[0].second;
    return answer;
}