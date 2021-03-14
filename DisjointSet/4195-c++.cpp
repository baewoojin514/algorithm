//친구 네트워크(4195)
//disjoint set으로 해결할 수 있다.

#include <algorithm>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <map>
#define MAX 200001

using namespace std;

int parent[MAX];
int freind[MAX];
char f1[21];
char f2[21];

int T;

int find_parent(int X){
    if (parent[X] != X) {
        parent[X] = find_parent(parent[X]);
    }
    return parent[X];
}
int union_find(int a, int b){
    a = find_parent(a);
    b = find_parent(b);
    
    if (a != b) {
        parent[a] = b;
        freind[b] += freind[a];
        freind[a] = 1;
    }
    return freind[b];
}

int main(void){
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        memset(parent, 0, sizeof(parent));
        memset(freind, 0, sizeof(freind));
        map<string, int> m;
        int F;
        cin >> F;
        for (int j = 1; j < 2*F + 1; j++) {
            parent[j] = j;
            freind[j] = 1;
        }
        int idx = 0;
        for (int j = 0; j < F; j++) {
            scanf("%s %s", f1, f2);
            if (m.find(f1) == m.end()) {
                idx += 1;
                m[f1] = idx;
            }
            if (m.find(f2) == m.end()) {
                idx += 1;
                m[f2] = idx;
            }
            printf("%d\n", union_find(m[f1], m[f2]));
        }
    }
    return 0;
}
