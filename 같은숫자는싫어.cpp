#include <vector>
#include <iostream>
#include<queue>
using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    queue<int>q;
    q.push(arr[0]);
    answer.push_back(arr[0]);
    for(int i=1;i<arr.size();i++){
        if(q.front()==arr[i]){
            continue;
        }
        else{
            q.pop();
            q.push(arr[i]);
            answer.push_back(arr[i]);
        }
    }
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.

    return answer;
}