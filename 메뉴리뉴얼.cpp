#include <string>
#include <vector>
#include<algorithm>
#include<utility>

using namespace std;
bool st(const pair<string,int>&a,const pair<string,int>&b){
    if(a.first.size()==b.first.size()){
        return a.second>b.second;
    }
    return a.first.size()<b.first.size();
}

vector<string> solution(vector<string> orders, vector<int> course) {
    sort(orders.begin(),orders.end());
    vector<char>n;
    vector<string>box;
    vector<string>answer;
    for(int i=0;i<orders.size();i++){
        vector<int>ind;
        for(int y=0;y<orders[i].size();y++){
            n.push_back(orders[i][y]);
        }
        for(int j=0;j<course.size();j++){
            if(course[j]>orders[i].size()){
                break;
            }
            else{
                for(int k=0;k<course[j];k++){
                    ind.push_back(1);
                }
                for(int w=0;w<orders[i].size()-course[j];w++){
                    ind.push_back(0);
                }
                sort(ind.begin(),ind.end());
                do {
                    string a;
                    for (int x = 0; x < ind.size(); x++) {
                        if (ind[x] == 1) {
                            a=a+n[x];
                        }
                    }
                    box.push_back(a);
                }while(next_permutation(ind.begin(),ind.end()));
                ind.erase(ind.begin(),ind.end());
            }
        }
        n.erase(n.begin(),n.end());
    }
    for(int i=0;i<box.size();i++){
        sort(box[i].begin(),box[i].end());
    }
    sort(box.begin(),box.end());
    int count=1;
    vector<pair<string,int>>cage;
    for(int i=0;i<box.size();i++){
        if(i+1<box.size()){
            if(box[i]==box[i+1]){
                count++;
            }
            else{
                if(count>1){
                    cage.push_back(make_pair(box[i],count));
                    count=1;
                }
            }
        }
        else{
            if(box[i]==box[i-1]){
                cage.push_back(make_pair(box[i],count));
            }
        }
    }
    sort(cage.begin(),cage.end(),st);
    int max=0;
    vector<int>loc;
    for(int i=0;i<cage.size();i++){
        if(i+1>cage.size()){
            if(cage[i-1].first.size()==cage[i].first.size()){
                if(max<=cage[i].second) {
                    max = cage[i].second;
                    loc.push_back(i);
                    for(int j=0;j<loc.size();j++){
                        answer.push_back(cage[loc[j]].first);
                    }
                }
            }
            else{
                answer.push_back(cage[i].first);
            }
        }
        else if(cage[i].first.size()==cage[i+1].first.size()){
            if(max<=cage[i].second) {
                max = cage[i].second;
                loc.push_back(i);
            }
        }
        else{
            if(max<=cage[i].second){
                loc.push_back(i);
            }
            for(int j=0;j<loc.size();j++){
                answer.push_back(cage[loc[j]].first);
            }
            loc.erase(loc.begin(),loc.end());
            max=0;
        }
    }
    for(int i=0;i<answer.size();i++){
        sort(answer[i].begin(),answer[i].end());
    }
    sort(answer.begin(),answer.end());
    return answer;
}