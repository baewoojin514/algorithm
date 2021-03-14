//행성 연결(16398)
//MST를 통해 해결할 수 있다.
//skill.1 - 2차원 배열을 edge vector에 저장한다.
//skill.2 - MST를 통해 최소 cost를 계산한다.

#include <algorithm>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#define MAX 1001

using namespace std;

int N;
int parent[MAX];
int board[MAX][MAX];
vector<pair<pair<int, int>, int>> edge;
long long result = 0;

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
        return;
    }
    else{
        parent[b] = a;
        return;
    }
}

int main(void){
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (board[i][j]) {
                edge.push_back({{board[i][j], i + 1}, j + 1});
            }
        }
    }
    for (int i = 1; i < N + 1; i++) {
        parent[i] = i;
    }
    int cnt = 0;
    sort(edge.begin(), edge.end());
    for (int i = 0; i < edge.size(); i++) {
        if (cnt == N - 1) {
            break;
        }
        int cost, a, b;
        cost = edge[i].first.first;
        a = edge[i].first.second;
        b = edge[i].second;
        if (find_parent(a) != find_parent(b)) {
            union_find(a, b);
            result += cost;
            cnt += 1;
        }
    }
    cout << result;
    
    return 0;
}
