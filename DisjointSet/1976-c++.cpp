//여행가자(1976)
//disjoint set 문제이다.
//find_parent 와 union_find 함수를 사용하여 구현할 수 있다.
//skill.1 - 1이 입력으로 들어오는 경우 union_find 를 통해 합집합으로 만든다.
//skill.2 - path를 탐색하면서 find_parent를 통해 부모가 같은지 확인하고 같지 않다면 불가능한 경로로 판단한다.

#include <algorithm>
#include <cstring>
#include <iostream>
#include <stdio.h>
#define MAX 201
#define travelMax 1000

using namespace std;

int parent[MAX];
int path[travelMax];
int N, M;

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
}

int main(void){
    cin >> N;
    cin >> M;
    for (int i = 1; i < N + 1; i++) {
        parent[i] = i;
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int tmp;
            cin >> tmp;
            if (tmp) {
                union_find(i + 1, j + 1);
            }
        }
    }
    for (int i = 0; i < M; i++) {
        cin >> path[i];
    }
    bool flags = true;
    for (int i = 0; i < M - 1; i++) {
        if (find_parent(path[i]) != find_parent(path[i + 1])) {
            flags = false;
            break;
        }
    }
    if (!flags) {
        cout << "NO";
    }
    else{
        cout << "YES";
    }
    
    return 0;
}
