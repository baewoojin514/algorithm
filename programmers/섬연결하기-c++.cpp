//섬 연결하기(programmers)
//MST를 위해 크루스칼 알고리즘을 사용한다.
//MST는 기본적으로 greedy 알고리즘이다.

#include <string>
#include <vector>
#include <algorithm>
//algorithm 헤더는 정렬을 위해서 필요하다.
#define MAX 101

using namespace std;

int parent[MAX];

int find_parent(int X){
    if (parent[X] != X) {
        parent[X] = find_parent(parent[X]);
    }
    return parent[X];
}

void union_find(int a, int b){
    a = find_parent(a);
    b = find_parent(b);
    
    if (a > b) {
        parent[a] = b;
    }
    else{
        parent[b] = a;
    }
    return;
}

int solution(int n, vector<vector<int>> costs) {
    vector<pair<pair<int, int>, int>> edges;
    
    for (int i = 0; i < costs.size(); i++) {
        int a, b, cost;
        a = costs[i][0];
        b = costs[i][1];
        cost = costs[i][2];
        edges.push_back(make_pair(make_pair(cost, a), b));
    }
    for (int i = 1; i < n + 1; i++) {
        parent[i] = i;
    }
    sort(edges.begin(), edges.end());
    int answer = 0;
    for (int i = 0; i < edges.size(); i++) {
        int cost, a, b;
        cost = edges[i].first.first;
        a = edges[i].first.second;
        b = edges[i].second;
        if (find_parent(a) != find_parent(b)) {
            union_find(a, b);
            answer += cost;
        }
    }
    return answer;
}
