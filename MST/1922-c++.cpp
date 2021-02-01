//네트워크 연결(1922)
//1197과 유사한 문제이다.
//크루스칼 알고리즘을 사용한다.
//node 와 cost 정보를 저장한 vector를 cost 기준으로 정렬한다.
//vector를 for 문으로 탐색하면서 두 node의 부모 노드가 같지 않은 경우 cycle이 형성되지 않기 때문에 cost를 더해준다.
//find_parent 함수와 union_find 함수가 필요하다.

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>

#define MAX 1001

using namespace std;

int parent[MAX];
int total = 0;
int N, M;

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
    cin >> N;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph.push_back({{c, a}, b});
    }
    for (int i = 1; i < N + 1; i++) {
        parent[i] = i;
    }
    sort(graph.begin(), graph.end());
    
    for (int i = 0; i < M; i++) {
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
