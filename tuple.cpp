#include <string>
#include <vector>
#include<algorithm>
#include<sstream>
#include<iostream>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<string>result;
    string box;
    stringstream ss(s);
    while(getline(ss,box,'}')) result.push_back(box);
    result.erase(result.end()-1,result.end());
    for(int i=0;i<result.size();i++){
        result[i].erase(result[i].begin(),result[i].begin()+2);
    }
    for(int i=0;i<result.size()-1;i++){
        for(int j=i+1;j<result.size();j++){
            if(result[i].size()>result[j].size()){
                swap(result[i],result[j]);
            }
        }
    }
    box="";
    int col=0;
    vector<vector<int>> cage(result.size());
    for(int i=0;i<result.size();i++){
        stringstream sss(result[i]);
        while(getline(sss,box,',')){
            cage[col].push_back(stoi(box));
        }
        col++;
    }
    int checknumber=0;
    for(int i=0;i<cage.size();i++){
        for(int j=0;j<cage[i].size();j++){
            if(answer.size()==0){
                answer.push_back(cage[i][j]);
            }
            else{
                for(int k=0;k<answer.size();k++){
                    if(answer[k]==cage[i][j]){
                        checknumber=1;
                        break;
                    }
                }
                if(checknumber!=1){
                    answer.push_back(cage[i][j]);
                }
                else{
                    checknumber=0;
                }
            }
        }
    }
    return answer;
}

int main(){
    string s="{{2},{2,1},{2,1,3},{2,1,3,4}}";
    vector<int> a=solution(s);
    for(int i=0;i<a.size();i++){
        cout<<a[i];
    }
}