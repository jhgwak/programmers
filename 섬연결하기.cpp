#include<vector>
#include<algorithm>
#include<utility>

using namespace std;
int check[100];

class Edge {
public:
    int node[2];
    int distance;
    Edge(int a, int b, int distance) {
        this->node[0] = a;
        this->node[1] = b;
        this->distance = distance;
    }
    bool operator<(Edge& edge) {
        return this->distance < edge.distance;
    }
};
int getParent(int node) {
    if (check[node] == node) return node;
    return getParent(check[node]);
}
void unionParent(int node1, int node2) {
    node1 = getParent(node1);
    node2 = getParent(node2);
    if (node1 < node2) check[node2] = node1;
    else check[node1] = node2;
}
bool isCycle(int node1, int node2) {
    node1 = getParent(node1);
    node2 = getParent(node2);
    if (node1 == node2) return true;
    else return false;

}
int solution(int n, vector<vector<int>>costs) {
    int answer = 0;
    vector<Edge>v;
    for (int i = 0; i < costs.size(); i++) {
        v.push_back(Edge(costs[i][0], costs[i][1], costs[i][2]));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        check[i] = i;
    }
    for (int i = 0; i < v.size(); i++) {
        if (!isCycle(v[i].node[0], v[i].node[1])) {
            answer += v[i].distance;
            unionParent(v[i].node[0], v[i].node[1]);
        }
    }
    return answer;
}