//최소 스패닝 트리(1197)
//크루스칼 알고리즘을 사용한다.
//node 와 cost 정보를 저장한 vector를 cost 기준으로 정렬한다.
//vector를 for 문으로 탐색하면서 두 node의 부모 노드가 같지 않은 경우 cycle이 형성되지 않기 때문에 cost를 더해준다.
//find_parent 함수와 union_find 함수가 필요하다.

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>

#define MAX 10001

using namespace std;

int parent[MAX];
int V, E;
int total = 0;

vector<pair<pair<int, int>, int>> graph;

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

int main(void){
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph.push_back({{c, a}, b});
    }
    for (int i = 1; i < V + 1; i++) {
        parent[i] = i;
    }
    sort(graph.begin(), graph.end());
    
    for (int i = 0; i < E; i++) {
        int cost, a, b;
        cost = graph[i].first.first;
        a = graph[i].first.second;
        b = graph[i].second;
        if (find_parent(a) != find_parent(b)) {
            union_find(a, b);
            total += cost;
        }
    }
    cout << total;
    return 0;
}
