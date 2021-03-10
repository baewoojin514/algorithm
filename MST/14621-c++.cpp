//나만 안되는 연애(14621)
//MST로 해결할 수 있다.
//skill.1 - 입력을 받으면서 edge vector에 저장한다.
//skill.2 - MST를 만들면서 M, W 인 경우만 연결한다.
//skill.3 - 연결 가능한 경우 visited를 1로 바꾼다. 모든 요소가 1이 아닌 경우 즉 연결 불가능한 경우 -1을 출력한다.

#include <algorithm>
#include <cstring>
#include <stdio.h>
#include <iostream>
#include <vector>
#define MAX 1001
 
using namespace std;

int N, M;
int parent[MAX];
vector<pair<pair<int, int>, int>> edge;
char sex[MAX];
int result = 0;
int visited[MAX];

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
    for (int i = 0; i < N; i++) {
        cin >> sex[i + 1];
    }
    for (int i = 0; i < M; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        edge.push_back({{d, u}, v});
    }
    for (int i = 1; i < N + 1; i++) {
        parent[i] = i;
    }
    sort(edge.begin(), edge.end());
    
    for (int i = 0; i < M; i++) {
        int cost, a, b;
        cost = edge[i].first.first;
        a = edge[i].first.second;
        b = edge[i].second;
        if (find_parent(a) != find_parent(b)) {
            if (sex[a] != sex[b]) {
                union_find(a, b);
                result += cost;
                visited[a] = 1;
                visited[b] = 1;
            }
        }
    }
    bool flags = true;
    for (int i = 1; i < N + 1; i++) {
        if (visited[i] == 0) {
            flags = false;
            break;
        }
    }
    if (!flags) {
        cout << -1;
    }
    else{
        cout << result;
    }
    
    return 0;
}
