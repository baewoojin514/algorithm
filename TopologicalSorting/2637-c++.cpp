//장난감조립(2637)
//위상정렬로 해결할 수 있다.
//skill.1 - 완성품의 수량을 1로 저장한다.
//skill.2 - 역으로 위상정렬을 하면서 result[nx] 에 result[cx] * cnt를 저장한다.

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <queue>
#define MAX 101

using namespace std;

vector<pair<int, int>> graph[MAX];
int indegree[MAX];
int check[MAX];
int result[MAX];
queue<int> q;

int N, M;

int main(void){
    memset(result, 0, sizeof(result));
    cin >> N;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int X, Y, K;
        cin >> X >> Y >> K;
        indegree[Y] += 1;
        check[X] += 1;
        graph[X].push_back(make_pair(Y, K));
    }
    result[N] = 1;
    q.push(N);
    
    while (!q.empty()) {
        int cx;
        cx = q.front();
        q.pop();
        
        for (int i = 0; i < graph[cx].size(); i++) {
            int nx, cnt;
            nx = graph[cx][i].first;
            cnt = graph[cx][i].second;
            result[nx] += result[cx] * cnt;
            indegree[nx] -= 1;
            if (indegree[nx] == 0) {
                q.push(nx);
            }
        }
    }
    for (int i = 1; i < N + 1; i++) {
        if (check[i] == 0) {
            cout << i << " " << result[i] << "\n";
        }
    }
    
    return 0;
}
