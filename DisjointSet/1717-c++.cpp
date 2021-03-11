//집합의 표현(1717)
//disjoint set 문제이다.
//find_parent 와 union_find 함수를 사용하여 구현할 수 있다.
//skill.1 - 0인 경우 union_find를 사용한다.
//skill.2 - 1인 경우 find_parent를 통해 부모가 같은지 확인하고 같다면 YES 아니면 NO를 출력한다.

#include <algorithm>
#include <cstring>
#include <iostream>
#include <stdio.h>
#define MAX 1000001

using namespace std;

int parent[MAX];
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
    scanf("%d %d", &N, &M);
    
    for (int i = 1; i < N + 1; i++) {
        parent[i] = i;
    }
    
    for (int i = 0; i < M; i++) {
        int op, a, b;
        scanf("%d %d %d", &op, &a, &b);
        
        if (op == 0) {
            union_find(a, b);
        }
        else if (op == 1){
            if (find_parent(a) == find_parent(b)) {
                printf("YES\n");
            }
            else if (find_parent(a) != find_parent(b)){
                printf("NO\n");
            }
        }
    }
    return 0;
}
