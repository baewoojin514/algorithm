//벽 부수고 이동하기(2206)
//벽을 하나까지 부수고 이동할 수 있다.
//skill.1 - 벽을 부수고 이동한 경우 visited[][][1] 에 거리를 갱신한다.
//skill.2 - 벽을 부수지 않고 이동한 경우 visited[][][0] 에 거리를 갱신한다.


#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
int board[1000][1000];
int visited[1000][1000][2];

queue<pair<pair<int, int>, int>> crack;
//좌표, 벽을 부쉈는지 여부 flags를 순서대로 저장한다.

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int canbe1, canbe2;

int main(void){
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &board[i][j]);
            //정수형 입력이 공백 없이 주어지는 경우 1d를 통해 처리한다.
        }
    }
    memset(visited, -1, sizeof(visited));
    visited[0][0][0] = 1;
    crack.push(make_pair(make_pair(0, 0), 0));
    
    while (!crack.empty()) {
        int cx, cy, flags;
        cx = crack.front().first.first;
        cy = crack.front().first.second;
        flags = crack.front().second;
        
        crack.pop();
        for (int i = 0; i < 4; i++) {
            int nx, ny;
            nx = cx + dx[i];
            ny = cy + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (board[nx][ny] == 0 && visited[nx][ny][flags] == -1) {
                    visited[nx][ny][flags] = visited[cx][cy][flags] + 1;
                    crack.push(make_pair(make_pair(nx, ny), flags));
                }
                else if (board[nx][ny] == 1 && visited[nx][ny][1] == -1 && flags == 0){
                    visited[nx][ny][1] = visited[cx][cy][flags] + 1;
                    crack.push(make_pair(make_pair(nx, ny), 1));
                }
            }
        }
    }
    canbe1 = visited[N - 1][M - 1][0];
    canbe2 = visited[N - 1][M - 1][1];
    if (canbe1 == -1 && canbe2 != -1) {
        cout << canbe2;
    }
    else if (canbe1 != -1 && canbe2 == -1){
        cout << canbe1;
    }
    else{
        cout << min(canbe1, canbe2);
    }
    return 0;
}
