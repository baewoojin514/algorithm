//물대기(1368)
//MST로 해결할 수 있다.
//우물을 직접파는 경우와 다른 논에서 물을 끌어다 쓰는 경우를 비교하여 MST를 만들어야 한다.
//skill.1 - 우물을 직접파는 경우를 0번 node와 연결한다(cost는 유지).
//skill.2 - 간선 정보를 가지고 MST를 만들고 totalcost를 출력한다.

#include <algorithm>
#include <cstring>
#include <stdio.h>
#include <iostream>
#include <vector>
#define MAX 301
 
using namespace std;

int N;
int parent[MAX];
vector<pair<pair<int, int>, int>> edge;
int result = 0;

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
    for (int i = 1; i < N + 1; i++) {
        int tmp;
        cin >> tmp;
        edge.push_back({{tmp, 0}, i});
        //우물을 직접 파는 경우를 0번 노드와 연결한다.
    }
    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < N + 1; j++) {
            int tmp;
            cin >> tmp;
            edge.push_back({{tmp, i}, j});
        }
    }
    for (int i = 0; i < N + 1; i++) {
        parent[i] = i;
    }
    sort(edge.begin(), edge.end());
    for (int i = 0; i < edge.size(); i++) {
        int cost, a, b;
        cost = edge[i].first.first;
        a = edge[i].first.second;
        b = edge[i].second;
        if (find_parent(a) != find_parent(b)) {
            union_find(a, b);
            result += cost;
        }
    }
    cout << result;
    
    return 0;
}
