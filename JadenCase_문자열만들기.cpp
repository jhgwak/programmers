#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int check=1;

    for(int i=0;i<s.size();i++){
        if(check==1&&(s[i]<=122&&s[i]>=97)){
            check=0;
            s[i]= toupper(s[i]);
            answer=answer+s[i];
        }
        else if(check==0&&(s[i]<=90&&s[i]>=65)){
            s[i]= tolower(s[i]);
            answer=answer+s[i];
        }
        else{
            answer=answer+s[i];
            check=0;
        }
        if(s[i]==' '){
            check=1;
        }
    }

    return answer;
}