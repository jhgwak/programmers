#include <string>
#include<vector>
#include<algorithm>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    vector<pair<pair<int,int>,pair<int,int>>>visit;
    pair<int,int>loc={0,0};
    pair<int,int>original=loc;
    int check=0;
    for(int i=0;i<dirs.size();i++){
        if(dirs[i]=='U'){
            loc.second++;
        }
        else if(dirs[i]=='D'){
            loc.second--;
        }
        else if(dirs[i]=='R'){
            loc.first++;
        }
        else if(dirs[i]=='L'){
            loc.first--;
        }
        if(loc.first<=5&&loc.first>=-5&&loc.second<=5&&loc.second>=-5){
            for(int j=0;j<visit.size();j++){
                if(visit[j].first.first==original.first&&visit[j].first.second==original.second&&visit[j].second.first==loc.first&&visit[j].second.second==loc.second){
                    check=1;
                    original.first=loc.first;
                    original.second=loc.second;
                    break;
                }
            }
            if(check!=1){
                visit.push_back({{original.first,original.second},{loc.first,loc.second}});
                visit.push_back({{loc.first,loc.second},{original.first,original.second}});

                original.first=loc.first;
                original.second=loc.second;
                answer++;
            }
            else if(check==1)check=0;

        }
        else{
            loc.first=original.first;
            loc.second=original.second;
        }
    }
    return answer;
}