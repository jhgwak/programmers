#include <string>
#include <vector>
#include<algorithm>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer=0;
    int zcount=0;
    int vcheck=0;
    int stop=0;
    vector<int>check(skill.size());
    for(int i=0;i<skill_trees.size();i++) {
        for (int k = 0; k < skill.size(); k++) {
            for (int j = 0; j < skill_trees[i].size(); j++) {
                if(skill[k]==skill_trees[i][j]){
                    check[k]=j+1;
                    break;
                }
            }
        }
        for(int x=0;x<check.size();x++){
            if(check[x]==0){
                zcount=1;
            }
            if(zcount==1&&check[x]!=0){
                stop=1;
                break;
            }
            if(vcheck>check[x]&&check[x]!=0){
                stop=1;
                break;
            }
            else{
                vcheck=check[x];
            }
        }
        if(stop!=1){
            answer++;
        }
        zcount=0;
        stop=0;
        vcheck=0;
        fill(check.begin(),check.end(),0);
    }
    return answer;
}