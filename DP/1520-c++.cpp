//내리막 길(1520)
//dp 와 dfs를 통해 해결할 수 있다.
//skill.1 - 방문하지 않았던 곳을 -1을 통해 구분한다.
//skill.2 - 이미 방문했던 곳이면 dp[i][j]를 반환하고 [m][n]에 도착하면 1을 반환한다(목적지로 가는 경우의 수가 1가지 있다는 의미).
//skill.3 - [0][0]을 출력한다.

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <stdio.h>
#include <cstring>

#define MAX 500

using namespace std;

int M, N;
int board[MAX][MAX];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int dp[MAX][MAX];

bool inRange(int X, int Y){
    return X >= 0 && X < M && Y >= 0 && Y < N;
}

int dfs(int cx, int cy){
    if (cx == M - 1 && cy == N - 1) {
        return 1;
    }
    if (dp[cx][cy] == -1) {
        dp[cx][cy] = 0;
        for (int i = 0; i < 4; i++) {
            int nx, ny;
            nx = cx + dx[i];
            ny = cy + dy[i];
            if (inRange(nx, ny) && board[nx][ny] < board[cx][cy]) {
                dp[cx][cy] += dfs(nx, ny);
            }
        }
    }
    return dp[cx][cy];
}

int main(void){
    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    
    cout << dfs(0, 0);
    
    return 0;
}
