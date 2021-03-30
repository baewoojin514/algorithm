//욕심쟁이 판다(1937)
//dp 와 dfs를 통해 해결할 수 있다.
//skill.1 - 내리막 길과 유사한 유형의 문제이다.
//skill.2 - 방문하지 않은 곳을 0으로 구분한다.
//skill.3 - 방문하지 않은 곳이라면 1로 바꾸고 4방향을 탐색하면서 [i][j] = max([i][j], [nx][ny] + 1)로 갱신한다.

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <stdio.h>
#include <cstring>

#define MAX 500

using namespace std;

int N;
int board[MAX][MAX];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int dp[MAX][MAX];
int result = 0;

bool inRange(int X, int Y){
    return X >= 0 && X < N && Y >= 0 && Y < N;
}

int dfs(int cx, int cy){
    if (dp[cx][cy]) {
        return dp[cx][cy];
    }
    dp[cx][cy] = 1;
    //아직 방문하지 않은 곳이라면 첫 번째 날로 시작한다.
    for (int i = 0; i < 4; i++) {
        int nx, ny;
        nx = cx + dx[i];
        ny = cy + dy[i];
        
        if (inRange(nx, ny) && board[nx][ny] > board[cx][cy]) {
            dp[cx][cy] = max(dp[cx][cy], dfs(nx, ny) + 1);
            //[cx][cy]가 방문하지 않았던 곳이라면 다음 방문하는 [nx][ny]에 하루를 더해주면 된다.
        }
    }
    return dp[cx][cy];
}

int main(void){
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result = max(result, dfs(i, j));
        }
    }
    cout << result;
    
    return 0;
}
