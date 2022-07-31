#include<iostream>
#include<string>
#include<vector>
#include<map>
// 옷의 종류 1개 --> a -->a
// 옷의 종류 2개 --> a,b -->(a,b)+(ab)
// 옷의 종류 3개 --> a,b,c-->(a,b,c)+(ab,ac,bc)+(abc)
//즉 (1+a)*(1+b)*(1+c)-1 
using namespace std;

int main(){
    vector<vector<string>> clothes={
            {"yellow_hat", "headgear"},
            {"blue_sunglasses", "eyewear"},
            {"green_turban", "headgear"}
    };
    for(int i=0;i<clothes.size();i++){
        reverse(clothes[i].begin(),clothes[i].end());
    }
    sort(clothes.begin(),clothes.end());
    vector<int>cal;
    string key="";
    int count=0;
    int result=1;
    for(int i=0;i<clothes.size();i++){
        if(i==0){
            key=clothes[i][0];
            count++;
        }
        else{
            if(key==clothes[i][0]){
                count++;
            }
            else{
                cal.push_back(count);
                key=clothes[i][0];
                count=1;
            }
        }
    }
    cal.push_back(count);

    for(int i=0;i<cal.size();i++){
        result=result*(1+cal[i]);
    }
    cout<<result-1;
}