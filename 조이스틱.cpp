#include <string>
#include <vector>
#include<map>

using namespace std;

int solution(string name) {
    int answer = 0;
    int a = 'A';
    int x = 0;
    int move = name.length() - 1;
    int Target = 0;
    int Left = 0;
    int Right = 0;
    int none=0;
    map<char, int>value;
    for (int i = 0; i < 26; i++) {
        value.insert(make_pair(a, x));
        if (a < 'N') {
            a++;
            x++;
        }
        else {
            a++;
            x--;
        }
    }
    for (int i = 0; i < name.size(); i++) {
        answer = answer + value[name[i]];
    }
    for (int i = 0; i < name.size(); i++) {
        if (name[i] == 'A') {
            Target = i;
            while (Target < name.length() && name[Target] == 'A')
                Target += 1;
            if (i == 0) {
                Left = 0;
            }
            else if (i != 0) {
                Left = i - 1;
            }
            Right = name.length() - Target;
            if (Left < Right) {
                if (Left + Right + Left < move)move = Left + Right + Left;
            }
            else if (Left > Right) {
                if (Left + Right + Right < move)move = Left + Right + Right;
            }
            else{
                if (Left + Right + Right < move)move = Left + Right + Right;
            }
        }
        else {
            none++;
        }
    }
    if (none == name.size()) {
        answer = answer + name.size() - 1;
    }
    else {
        answer = answer + move;
    }

    return answer;
}