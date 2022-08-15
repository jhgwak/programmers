#include <string>
#include <vector>
#include<algorithm>

using namespace std;
bool visit[50000];

int solution(vector<int> people, int limit) {
    int answer = 0;
    int sub = 0;
    sort(people.begin(), people.end());
    if (people.size() == 1) {
        answer = people.size();
        return answer;
    }
    int size = people.size();
    int start = 0;
    int end = size - 1;
    for (int i = 0; i < size; i++) {
        if (end > start) {
            if (people[start] + people[end] <= limit) {
                sub++;
                start++;
                end--;
            }
            else if (people[start] + people[end] > limit) {
                end--;
            }
            else if (start + 1 == end) break;
        }
    }
    answer = size - sub;
    return answer;
}