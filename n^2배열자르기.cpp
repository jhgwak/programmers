#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    int X1=left/n;
    int Y1=left%n;
    int X2=right/n;
    int Y2=right%n;
    int value=0;
    while(1){
        if(X1==X2&&Y1==Y2){
            if(X1<Y1){
                value=X1+1+(Y1-X1);
                answer.push_back(value);
            }
            else{
                value=X1+1;
                answer.push_back(value);
            }
            break;
        }
        if(Y1<n){
            if(X1<Y1){
                value=X1+1+(Y1-X1);
                answer.push_back(value);
            }
            else{
                value=X1+1;
                answer.push_back(value);
            }
            Y1++;
        }
        else{
            Y1=0;
            X1++;
            if(X1<Y1){
                value=X1+1+(Y1-X1);
                answer.push_back(value);
            }
            else{
                value=X1+1;
                answer.push_back(value);
            }
            Y1++;
        }
    }
    return answer;
}