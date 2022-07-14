#include <string>
#include <vector>
#include<algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int zerocount=0;
    vector<int>cage;

    sort(citations.begin(), citations.end(),greater<int>());
    for (int i = 0; i < citations.size(); i++) {
        if (citations[i] >= i + 1) {
            cage.push_back(i + 1);
        }
        else if (citations[i] == 0) {
            zerocount++;
        }
    }
    if(zerocount==citations.size()){
        answer=0;
        return answer;
    }
    sort(cage.begin(), cage.end(),greater<int>());
    answer=cage[0];
    return answer;
}