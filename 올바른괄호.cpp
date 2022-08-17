#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int check=0;
    if(s[0]==')'||s[s.size()-1]=='('){
        answer=false;
        return answer;
    }
    if(s.size()%2==1){
        answer=false;
        return answer;
    }
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            check++;
        }
        else if(s[i]==')'&&check!=0){
            check--;
        }
        else if(s[i]==')'&&check==0){
            answer=false;
            return false;
        }
    }
    if(check==0){
        answer=true;
        return answer;
    }
    else{
        answer=false;
        return answer;
    }
}