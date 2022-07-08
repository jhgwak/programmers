#include <string>
#include <vector>
#include<queue>
#include<cmath>
using namespace std;
queue<int>q;
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    const  int total=100;
    int Psize=progresses.size();
    int Ssize=speeds.size();

    for(int i=0;i<Psize;i++){
        double a=0;
        a=ceil((double)(total-progresses[i]) / speeds[i]);
        q.push(a);
    }
    int Qsize=q.size();
    int count=1;
    int val=q.front();
    q.pop();
    while(q.size()!=0){
        if(val<q.front()){
            answer.push_back(count);
            count=1;
            val=q.front();
            q.pop();
        }
        else{
            count++;
            q.pop();
        }
    }
    answer.push_back(count);
    return answer;
}