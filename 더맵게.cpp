#include <string>
#include <vector>
#include<queue>

using namespace std;

int solution(vector<int> scoville, int k) {
    priority_queue<int, vector<int>, greater<int>>pq;
    int SC = scoville.size();
    for (int i = 0; i < SC; i++) {
        pq.push(scoville[i]);
    }
    int answer = 0;

    while (pq.size()!=0) {//일단은 무한 루프
        int val = pq.top();
        pq.pop();
        if (val + (2*pq.top()) < k) {
            pq.push(val + (2 * pq.top()));
            pq.pop();
            answer++;
            if (pq.size() == 1) {
                if (pq.top() < k) {
                    return-1;
                }
                else if (pq.top() >= k) {
                    answer++;
                    return answer;

                }
            }
        }
        else if (val + (2 * pq.top() >= k)) {
            pq.push(val + (2 * pq.top()));
            pq.pop();
            if (pq.top() >= k) {
                answer++;
                return answer;

            }
            else {
                answer++;
                continue;
            }
        }

    }

}