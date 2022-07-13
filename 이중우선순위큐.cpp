#include<iostream>
#include<string>
#include<vector>
#include<deque>

using namespace std;

int main(){
    vector<string>operations={"I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333"};
    deque<int>dq;
    vector<int>answer;
    string number="";
    int total=0;
    for(int i=0;i<operations.size();i++){
        if(operations[i][0]=='I'){
            for(int j=2;j<operations[i].size();j++){
                number=number+operations[i][j];
            }
            total= stoi(number);
            dq.push_back(total);
            number="";
        }
        else if(operations[i][0]=='D'){
            if(dq.size()==0){
                continue;
            }
            else{
                sort(dq.begin(),dq.end());
                if(operations[i][2]=='-'){
                    dq.pop_front();
                }
                else {
                    dq.pop_back();
                }
            }
        }
    }
    if(dq.size()==0){
        answer.push_back(0);
        answer.push_back(0);

    }
    else{
        sort(dq.begin(),dq.end());
        answer.push_back(dq.back());
        answer.push_back(dq.front());
    }

    return answer;

}