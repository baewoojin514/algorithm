//다리 만들기(2146)
//bfs와 dfs로 해결 가능하다.
//skill.1 - 먼저 bfs를 통해 같은 섬간 동일한 번호를 붙인다(1 부터 시작).
//skill.2 - 섬을 확장하는 함수를 만든다 => 섬을 확장하다가 현재 섬과 다른 번호를 만나면 ++한 count를 반환하고 최소 값으로 갱신한다.

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <cstring>

using namespace std;

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

int minDistance = 10000;

int N;
int board[100][100];
int visited[100][100];
int island[100][100];

void expansion(int islandNum){
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int>> bridge;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (island[i][j] == islandNum) {
                visited[i][j] = 1;
                bridge.push(make_pair(i, j));
                
            }
        }
    }
    int distance = 0;
    while (!bridge.empty()) {
        int qsize = bridge.size();
        for (int i = 0; i < qsize; i++) {
            int cx, cy;
            cx = bridge.front().first;
            cy = bridge.front().second;
            bridge.pop();
            for (int j = 0; j < 4; j++) {
                int nx, ny;
                nx = cx + dx[j];
                ny = cy + dy[j];
                if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                    if (visited[nx][ny] == 0) {
                        if (board[nx][ny] == 0) {
                            visited[nx][ny] = 1;
                            bridge.push(make_pair(nx, ny));
                        }
                        //다른 섬으로 다리를 놓기 때문에 섬이 아닌 좌표를 queue에 담는다.
                        else if (board[nx][ny] == 1 && island[nx][ny] != islandNum){
                            minDistance = min(minDistance, distance);
                        }
                        //섬인 좌표이면서 다른 섬인 경우 최단 거리를 갱신한다.
                    }
                }
            }
        }
        distance++;
    }
    
}

    
int main(void){
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
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
                        if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
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
    for (int i = 1; i <= cnt; i++) {
        expansion(i);
    }
    cout << minDistance;
    
    return 0;
}
