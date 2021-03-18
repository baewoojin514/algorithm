//세부(13905)
//MST로 해결할 수 있다(disjoint set + pq).
//skill.1 - 간선 정보를 무게제한을 기준으로 우선순위 큐에 저장한다.
//skill.2 - pq에서 pop 시키며 합집합으로 만들어 주고 시작점과 도착점의 부모 노드가 동일한지를 확인한다.
//skill.3 - 부모노드가 동일하다면 cost로 result를 갱신한다.

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#define INF 1e9
#define MAX 100001

using namespace std;

int result;

int N, M;
int s, e;
priority_queue<pair<pair<int, int>, int>> pq;

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

int main(void){
    cin >> N >> M;
    cin >> s >> e;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        pq.push({{c, a}, b});
    }
    for (int i = 1; i < N; i++) {
        parent[i] = i;
    }
    while (!pq.empty()) {
        int cost, a, b;
        cost = pq.top().first.first;
        a = pq.top().first.second;
        b = pq.top().second;
        
        pq.pop();
        
        union_find(a, b);
        if (find_parent(s) == find_parent(e)) {
            result = cost;
            break;
        }
    }
    cout << result;
    return 0;
}
