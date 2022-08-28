#include <string>
#include <vector>
#include<algorithm>
#include<utility>
#include<queue>

using namespace std;
int dx[]={0,1,0,-1};
int dy[]={-1,0,1,0};
 string answer="";
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요
void bfs(vector<vector<char>>& pan, vector<pair<char, pair<int, int>>>alpa, int m, int n) {
    answer="";
    vector<bool>checkPan(alpa.size());
    vector<vector<bool>> visit(m, vector<bool>(n));
    queue<pair<string, pair<int, int>>>q;
    char val = ' ';
    int count = alpa.size();
    for (int i = 0; i < alpa.size(); i++) {
        if (checkPan[i] == true)continue;
        if (count == 0)break;
        q.push(make_pair("", make_pair(alpa[i].second.first, alpa[i].second.second)));
        int nx = 0;
        int ny = 0;
        while (!q.empty()) {
            int leftcheck = 0;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();
            for (int j = 0; j < 4; j++) {
                int x1 = x + dx[j];
                int y1 = y + dy[j];
                if (x1 >= 0 && x1 < m && y1 >= 0 && y1 < n && pan[x1][y1] == pan[x][y]&&pan[x][y]!='.') {
                    answer = answer + pan[x1][y1];
                    pan[x1][y1] = '.';
                    pan[x][y] = '.';
                    checkPan[i] = true;
                    count--;
                    i = -1;
                    break;
                }
                else if (x1 >= 0 && x1 < m && y1 >= 0 && y1 < n && pan[x1][y1] == '.') {
                    if (pan[x][y] != '.') {
                        nx = x;
                        ny = y;
                        val = pan[x][y];
                        if (x == x1) {//y로 전환
                            if (y > y1) {//뒤로 이동
                                q.push(make_pair("-y", make_pair(x1, y1)));
                            }
                            else {//앞으로 이동
                                q.push(make_pair("+y", make_pair(x1, y1)));
                            }
                        }
                        else if (y == y1) {//x로 전환
                            if (x > x1) {//뒤로이동
                                q.push(make_pair("-x", make_pair(x1, y1)));
                            }
                            else {
                                q.push(make_pair("+x", make_pair(x1, y1)));
                            }
                        }
                        visit[x][y] = true;
                        visit[x1][y1] = true;
                    }

                }
            }
            if (q.size() == 0) {
                break;
            }
            int BP = 0;
            int x2 = q.front().second.first;
            int y2 = q.front().second.second;
            string loc = q.front().first;
            for (int k = 0; k < 4; k++) {
                int x3 = x2 + dx[k];
                int y3 = y2 + dy[k];
                if (x3 >= 0 && x3 < m && y3 >= 0 && y3 < n && pan[x3][y3] == val && visit[x3][y3] == false) {
                    BP = 1;
                    answer = answer + pan[x3][y3];
                    pan[nx][ny] = '.';
                    pan[x3][y3] = '.';
                    count--;
                    checkPan[i] = true;
                    for (int a = 0; a < visit.size(); a++) {
                        for (int b = 0; b < visit[a].size(); b++) {
                            visit[a][b] = false;
                        }
                    }
                    i = -1;
                    break;
                }
            }
            if (BP == 1) {
                while (!q.empty()) {
                    q.pop();
                }
                BP = 0;
                break;
            }
            if (loc == "-x") {
                if (x2 >= 0 && x < m && x2 >= 0 && y2 < n) {
                    if (x2 - 1 >= 0 && pan[x2 - 1][y2] == '.') {
                        q.push(make_pair("-x", make_pair(x2 - 1, y2)));
                    }
                }
                if (x2 >= 0 && x2 < m && y2 >= 0 && y2 < n) {
                    for (int l = y2 - 1; l >= 0; l--) {
                        if (l >= 0) {
                            if (pan[x2][l] == '.') {
                                continue;
                            }
                            else if (pan[x2][l] == val) {
                                answer = answer + pan[x2][l];
                                pan[nx][ny] = '.';
                                pan[x2][l] = '.';
                                BP = 1;
                                count--;
                                checkPan[i] = true;
                                i = -1;
                                break;
                            }
                            else break;
                        }
                    }
                    if (BP == 1) {
                        while (!q.empty()) {
                            q.pop();
                        }
                        for (int a = 0; a < visit.size(); a++) {
                            for (int b = 0; b < visit[a].size(); b++) {
                                visit[a][b] = false;
                            }
                        }
                        BP = 0;
                        break;
                    }
                    for (int l = y2 + 1; l < n; l++) {
                        if (l < n) {
                            if (pan[x2][l] == '.') {
                                continue;
                            }
                            else if (pan[x2][l] == val) {
                                answer = answer + pan[x2][l];
                                pan[nx][ny] = '.';
                                pan[x2][l] = '.';
                                checkPan[i] = true;
                                BP = 1;
                                count--;
                                for (int a = 0; a < visit.size(); a++) {
                                    for (int b = 0; b < visit[a].size(); b++) {
                                        visit[a][b] = false;
                                    }
                                }
                                i = -1;
                                break;
                            }
                            else break;
                        }
                    }
                }
            }

            else if (loc == "+x") {
                if (x2 >= 0 && x < m && x2 >= 0 && y2 < n) {
                    if (x2 + 1 < m && pan[x2 + 1][y2] == '.') {
                        q.push(make_pair("+x", make_pair(x2 + 1, y2)));
                    }
                }
                if (x2 >= 0 && x2 < m && y2 >= 0 && y2 < n) {
                    for (int l = y2 - 1; l >= 0; l--) {
                        if (l >= 0) {
                            if (pan[x2][l] == '.') {
                                continue;
                            }
                            else if (pan[x2][l] == val) {
                                answer = answer + pan[x2][l];
                                pan[nx][ny] = '.';
                                pan[x2][l] = '.';
                                checkPan[i] = true;
                                BP = 1;
                                count--;
                                for (int a = 0; a < visit.size(); a++) {
                                    for (int b = 0; b < visit[a].size(); b++) {
                                        visit[a][b] = false;
                                    }
                                }
                                i = -1;
                                break;
                            }
                            else break;
                        }
                    }
                    if (BP == 1) {
                        while (!q.empty()) {
                            q.pop();
                        }
                        BP = 0;
                        break;
                    }
                    for (int l = y2 + 1; l < n; l++) {
                        if (l < n) {
                            if (pan[x2][l] == '.') {
                                continue;
                            }
                            else if (pan[x2][l] == val) {
                                answer = answer + pan[x2][l];
                                pan[nx][ny] = '.';
                                pan[x2][l] = '.';
                                checkPan[i] = true;
                                BP = 1;
                                count--;
                                for (int a = 0; a < visit.size(); a++) {
                                    for (int b = 0; b < visit[a].size(); b++) {
                                        visit[a][b] = false;
                                    }
                                }
                                i = -1;
                                break;
                            }
                            else break;
                        }

                    }
                }
            }
            else if (loc == "-y") {
                if (x2 >= 0 && x < m && x2 >= 0 && y2 < n) {
                    if (y2 - 1 >= 0 && pan[x2][y2 - 1] == '.') {
                        q.push(make_pair("-y", make_pair(x2, y2 - 1)));
                    }
                }
                if (x2 >= 0 && x2 < m && y2 >= 0 && y2 < n) {
                    for (int l = x2 - 1; l >= 0; l--) {
                        if (l >= 0) {
                            if (pan[l][y2] == '.') {
                                continue;
                            }
                            else if (pan[l][y2] == val) {
                                answer = answer + pan[l][y2];
                                pan[nx][ny] = '.';
                                pan[l][y2] = '.';
                                checkPan[i] = true;
                                BP = 1;
                                count--;
                                for (int a = 0; a < visit.size(); a++) {
                                    for (int b = 0; b < visit[a].size(); b++) {
                                        visit[a][b] = false;
                                    }
                                }
                                i = -1;
                                break;
                            }
                            else break;
                        }
                    }
                    if (BP == 1) {
                        while (!q.empty()) {
                            q.pop();
                        }
                        BP = 0;
                        break;
                    }
                    for (int l = x2 + 1; l < n; l++) {
                        if (l < m) {
                            if (pan[l][y2] == '.') {
                                continue;
                            }
                            else if (pan[l][y2] == val) {
                                answer = answer + pan[l][y2];
                                pan[nx][ny] = '.';
                                pan[l][y2] = '.';
                                checkPan[i] = true;
                                BP = 1;
                                count--;
                                for (int a = 0; a < visit.size(); a++) {
                                    for (int b = 0; b < visit[a].size(); b++) {
                                        visit[a][b] = false;
                                    }
                                }
                                i = -1;
                                break;
                            }
                            else break;
                        }
                    }
                }
            }

            else if (loc == "+y") {
                if (x2 >= 0 && x < m && x2 >= 0 && y2 < n) {
                    if (y2 + 1 < n && pan[x2][y2 + 1] == '.') {
                        q.push(make_pair("+y", make_pair(x2, y2 + 1)));
                    }
                }
                if (x2 >= 0 && x2 < m && y2 >= 0 && y2 < n) {
                    for (int l = x2 - 1; l >= 0; l--) {
                        if (l >= 0) {
                            if (pan[l][y2] == '.') {
                                continue;
                            }
                            else if (pan[l][y2] == val) {
                                answer = answer + pan[l][y2];
                                pan[nx][ny] = '.';
                                pan[l][y2] = '.';
                                checkPan[i] = true;
                                BP = 1;
                                count--;
                                for (int a = 0; a < visit.size(); a++) {
                                    for (int b = 0; b < visit[a].size(); b++) {
                                        visit[a][b] = false;
                                    }
                                }
                                i = -1;
                                break;
                            }
                            else break;
                        }
                    }
                    if (BP == 1) {
                        while (!q.empty()) {
                            q.pop();
                        }
                        BP = 0;
                        break;
                    }
                    for (int l = x2 + 1; l < n; l++) {
                        if (l < m) {
                            if (pan[l][y2] == '.') {
                                continue;
                            }
                            else if (pan[l][y2] == val) {
                                answer = answer + pan[l][y2];
                                pan[nx][ny] = '.';
                                pan[l][y2] = '.';
                                checkPan[i] = true;
                                BP = 1;
                                count--;
                                for (int a = 0; a < visit.size(); a++) {
                                    for (int b = 0; b < visit[a].size(); b++) {
                                        visit[a][b] = false;
                                    }
                                }
                                i = -1;
                                break;
                            }
                            else break;
                        }
                    }
                }
            }
        }
        for (int a = 0; a < visit.size(); a++) {
            for (int b = 0; b < visit[a].size(); b++) {
                visit[a][b] = false;
            }
        }
    }
}
string solution(int m, int n, vector<string> board) {
    vector<vector<char>>pan(m, vector<char>(n));
    vector<pair<char, pair<int, int>>>alpa;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            pan[i][j] = board[i][j];
            if (board[i][j] == '.' || board[i][j] == '*') {
                continue;
            }
            else if (i == 0) {
                int check1 = 0;
                for (int k = 0; k < alpa.size(); k++) {
                    if (alpa[k].first == board[i][j]) {
                        check1 = 1;
                        break;
                    }
                }
                if (check1 != 1) {
                    alpa.push_back(make_pair(board[i][j], make_pair(i, j)));
                }
            }
            else {
                if (board[i][j] == '.' || board[i][j] == '*') {
                    continue;
                }
                else {
                    int check = 0;
                    for (int k = 0; k < alpa.size(); k++) {
                        if (alpa[k].first == board[i][j]) {
                            check = 1;
                            break;
                        }
                    }
                    if (check != 1) {
                        alpa.push_back(make_pair(board[i][j], make_pair(i, j)));
                    }
                }
            }
        }
    }
    sort(alpa.begin(), alpa.end());
    bfs(pan, alpa, m, n);
    if(answer==""||answer.size()!=alpa.size()){
        return "IMPOSSIBLE";
    }
    else{
        return answer;
    }

}