#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int rek=k;
    vector<int>order(dungeons.size());
    vector<int>value;
    int answer = -1;
    for(int i=0;i<order.size();i++){
        order[i]=i;
    }
    do{
        for(auto it=order.begin();it!=order.end();++it){
            if(dungeons[*it][0]>k){
                break;
            }
            else{
                answer++;
                k=k-dungeons[*it][1];
            }
        }
        value.push_back(answer);
        answer=0;
        k=rek;
        //cout<<endl;
    }
    while(next_permutation(order.begin(),order.end()));
    answer=*max_element(value.begin(), value.end());
    return answer;
}