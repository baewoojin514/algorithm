//친구비(16562)
//disjoint set 문제이다.
//find_parent 와 union_find 함수를 사용하여 구현할 수 있다.
//skill.1 - 친구 관계를 가지고 합집합을 만든다(합집합 연산시 친구비가 작은 사람이 부모가 되도록 한다).
//skill.2 - parent 배열을 탐색하면서 모든 최종 부모를 집합에 저장한다.
//skill.3 - 최종 부모들의 친구비 합이 K 이하라면 totalCost를 출력하고 아니라면 Oh no를 출력한다.

#include <algorithm>
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <set>
#define MAX 10001

using namespace std;

int parent[MAX];
int friendCost[MAX];
int N, M, K;
int totalCost = 0;

int find_parent(int X){
    if (parent[X] != X) {
        parent[X] = find_parent(parent[X]);
    }
    return parent[X];
}

void union_find(int a, int b){
    a = find_parent(a);
    b = find_parent(b);
    
    if (friendCost[a] > friendCost[b]) {
        parent[a] = b;
    }
    else{
        parent[b] = a;
    }
}

int main(void){
    cin >> N >> M >> K;
    
    for (int i = 1; i < N + 1; i++) {
        cin >> friendCost[i];
    }
    for (int i = 1; i < N + 1; i++) {
        parent[i] = i;
    }
    
    for (int i = 0; i < M; i++) {
        int v, w;
        cin >> v >> w;
        union_find(v, w);
    }
    for (int i = 1; i < N + 1; i++) {
        if (find_parent(i) != find_parent(0)) {
            totalCost += friendCost[find_parent(i)];
            union_find(i, 0);
        }
    }
    
    if (totalCost <= K) {
        cout << totalCost;
    }
    else{
        cout << "Oh no";
    }
    return 0;
}
