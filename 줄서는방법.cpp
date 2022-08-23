#include <string>
#include <vector>
#include<algorithm>

using namespace std;
vector<bool> visit(20);
vector<int>result;
vector<int> arr;
int m;
int order=1;
int check=0;
void dfs(int n,int k){
    if(result.size()==m){
        if(order==k){
            check=1;
            return;
        }
        order++;
    }
    for(int i=0;i<arr.size();i++){
        if(!visit[i]){
            visit[i]=true;
            result.push_back(arr[i]);
            dfs(n,k);
            if(check==1)return;
            result.pop_back();
            visit[i]=false;
        }
    }
}
vector<int> solution(int n, long long k) {
    vector<int> answer;
    m=n;
    for(int i=1;i<=n;i++){
        arr.push_back(i);
    }
    dfs(n,k);
    for(int i=0;i<result.size();i++){
        answer.push_back(result[i]);
    }
    return answer;
}