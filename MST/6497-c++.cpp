//전력난(6497)
//MST 알고리즘으로 해결 가능하다.
//skill.1 - 간선 정보를 입력 받으며 모든 cost를 더한다.
//skill.2 - MST의 cost를 더하고 1에서 계산된 cost에서 차감한다.

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cstdio>
#include <cstring>
#include <vector>
#define MAX 200000

using namespace std;

int parent[MAX];
int m, n;
vector<pair<pair<int, int>, int>> edges;

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
    while (true) {
        int totalCost = 0;
        scanf("%d %d", &m, &n);
        if (m == 0 && n == 0) {
            break;
        }
        for (int i = 0; i < n; i++) {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            totalCost += c;
            edges.push_back(make_pair(make_pair(c, a), b));
        }
        memset(parent, 0, sizeof(parent));
        //여러개의 testcase가 입력으로 들어오기 때문에 parent 배열을 초기화해야 한다.
        for (int i = 0; i < m; i++) {
            parent[i] = i;
        }
        sort(edges.begin(), edges.end());
        int total = 0;
        for (int i = 0; i < edges.size(); i++) {
            int cost, a, b;
            cost = edges[i].first.first;
            a = edges[i].first.second;
            b = edges[i].second;
            if (find_parent(a) != find_parent(b)) {
                union_find(a, b);
                total += cost;
            }
        }
        edges.clear();
        printf("%d\n", totalCost - total);
    }
    return 0;
}
