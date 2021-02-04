//다리 만들기2(17472)
//bfs와 dfs로 해결 가능하다.
//MST를 사용해야 한다 => union_find, find_parent
//skill.1 - 먼저 bfs를 통해 같은 섬간 동일한 번호를 붙인다(1 부터 시작).
//skill.2 - 다리를 놓을 수 있는 좌표를 판별하고 4방향에 대해서 dfs를 실행한다.
//skill.3 - 다른 섬을 만나면 시작 섬의 번호, 도착 섬의 번호, 다리의 길이를 graph vector에 저장한다.
//skill.4 - graph vector 정보를 가지고 MST 알고리즘을 적용해 답을 도출한다.

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <cstring>
#include <vector>
#define MAX 7


using namespace std;

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

int N;
int M;
int board[100][100];
int visited[100][100];
int island[100][100];

    
vector<pair<pair<int, int>, int>> graph;
int parent[MAX];

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

bool inside(int X, int Y){
    return X >= 0 && X < N && Y >= 0 && Y < M;
}

int main(void){
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 1 && visited[i][j] == 0) {
                cnt++;
                queue<pair<int, int >> num;
                num.push(make_pair(i, j));
                visited[i][j] = 1;
                island[i][j] = cnt;
                
                while (!num.empty()) {
                    int cx, cy;
                    cx = num.front().first;
                    cy = num.front().second;
                    
                    num.pop();
                    
                    for (int k = 0; k < 4; k++) {
                        int nx, ny;
                        nx = cx + dx[k];
                        ny = cy + dy[k];
                        if (inside(nx, ny)) {
                            if (board[nx][ny] == 1 && visited[nx][ny] == 0) {
                                visited[nx][ny] = 1;
                                island[nx][ny] = cnt;
                                num.push(make_pair(nx, ny));
                            }
                        }
                    }
                }
            }
        }
    }
    //같은 섬에 포함된 좌표들에 동일한 번호를 붙인다.
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (island[i][j]) {
                for (int k = 0; k < 4; k++) {
                    int nx, ny;
                    nx = i + dx[k];
                    ny = j + dy[k];
                    int tempDist = 0;
                    while (inside(nx, ny) && !island[nx][ny]) {
                        //board의 범위안에 있어야 하고 0 즉 바다여야 다리를 놓을 수 있다.
                        nx += dx[k];
                        ny += dy[k];
                        tempDist += 1;
                        if (inside(nx, ny) && (island[nx][ny] != island[i][j]) && island[nx][ny]) {
                            if (tempDist >= 2) {
                                graph.push_back({{tempDist, island[i][j]}, island[nx][ny]});
                            }
                        }
                    }
                    
                }
            }
        }
    }
    for (int i = 1; i < cnt + 1; i++) {
        parent[i] = i;
    }
    sort(graph.begin(), graph.end());
    int total = 0;
    int checkNum = 0;
    for (int i = 0; i < graph.size(); i++) {
        int cost, a, b;
        cost = graph[i].first.first;
        a = graph[i].first.second;
        b = graph[i].second;
        if (find_parent(a) != find_parent(b)) {
            union_find(a, b);
            total += cost;
            checkNum += 1;
        }
    }
    if (checkNum != cnt - 1) {
        cout << -1;
    }
    else{
        cout << total;
    }
    return 0;
}
