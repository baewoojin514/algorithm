//군사 이동(11085)
//disjoint set으로 해결할 수 있다.
//skill.1 - 우선순위큐를 사용하여 경로의 넓이가 큰 것을 우선 꺼낸다.
//skill.2 - 해당 경로를 union_find를 통해 합집합으로 만들어 준다.
//skill.3 - c와 v의 부모가 같은지를 확인하고 같다면 그 순간 경로가 완성된 것이다.
//skill.4 - 3일 때의 tempCost를 출력한다.

#include <algorithm>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <queue>
#define MAX 1000

using namespace std;

int p, w, c, v;
int parent[MAX];

priority_queue<pair<pair<int, int>, int>> pq;

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
    scanf("%d %d", &p, &w);
    scanf("%d %d", &c, &v);
    
    for (int i = 0; i < w; i++) {
        int a, b, cost;
        scanf("%d %d %d", &a, &b, &cost);
        pq.push({{cost, a}, b});
    }
    for (int i = 0; i < p; i++) {
        parent[i] = i;
    }
    while (!pq.empty()) {
        int tempCost, a, b;
        tempCost = pq.top().first.first;
        a = pq.top().first.second;
        b = pq.top().second;
        
        pq.pop();
        
        union_find(a, b);
        if (find_parent(c) == find_parent(v)) {
            printf("%d", tempCost);
            break;
        }
    }
    return 0;
}
