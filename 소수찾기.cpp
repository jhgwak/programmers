#include <string>
#include <vector>
#include<algorithm>
#include<utility>
#include<map>
#include<cmath>
using namespace std;
vector<int> Rvalue;
void permutation(vector<int> arr,int depth,int n,int r){
    if(depth==r){
        int cnt=1;
        int value=0;
        int res=0;
        for(int i=0;i<r;i++){
            if(r==1){
                value=1;
            }
            else{
                value=pow(10,r-cnt);
            }
            res=res+arr[i]*value;
            cnt++;
        }
        Rvalue.push_back(res);
        return;
    }
    for(int i=depth;i<n;i++){
        swap(arr[depth],arr[i]);
        permutation(arr,depth+1,n,r);
        swap(arr[depth],arr[i]);
    }
}

int solution(string number) {
    int answer = 0;
    vector<int>v;
    map<char,int>table;
    char x='0';
    for(int i=0;i<10;i++){
        table.insert(make_pair(x,i));
        x++;
    }
    for(int i=0;i<number.size();i++){
        v.push_back(table[number[i]]);
    }
    for(int i=1;i<=number.size();i++){
        permutation(v,0,number.size(),i);
    }
    sort(Rvalue.begin(),Rvalue.end());
    Rvalue.erase(unique(Rvalue.begin(),Rvalue.end()),Rvalue.end());
    for(int i=0;i<Rvalue.size();i++){
        int a=2;
        int b=Rvalue[i]-1;
        if(Rvalue[i]==1||Rvalue[i]==0){
            continue;
        }
        while(1){
            if(a<=b){
                if(Rvalue[i]%a==0){
                    break;
                }else a++;
            }
            else{
                answer++;
                break;
            }
        }
    }
    return answer;
}