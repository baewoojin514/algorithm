#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string.h>
#define MAX 100
#define INF 1e9

using namespace std;

int N, M, T;
int board[MAX][MAX];
int visited[MAX][MAX];

int sI, sJ;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool inRange(int X, int Y){
    return X >= 0 && X < N && Y >= 0 && Y < M;
}

int findPrincess(int destX, int destY){
    queue<pair<int, int>> q;
    memset(visited, 0, sizeof(visited));
    
    visited[0][0] = 1;
    q.push(make_pair(0, 0));
    
    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if (inRange(nx, ny)) {
                if (visited[nx][ny] == 0 && board[nx][ny] != 1) {
                    visited[nx][ny] = visited[cx][cy] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    
    if (visited[destX][destY] == 0) {
        return INF;
    }
    else{
        return visited[destX][destY] - 1;
    }
}

int main(void)
{
    cin >> N >> M >> T;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) {
                sI = i;
                sJ = j;
            }
        }
    }
    
    int temp1 = findPrincess(N - 1, M - 1);
    int temp2 = findPrincess(sI, sJ) + (N - 1 - sI) + (M - 1 - sJ);
    
    int result = min(temp1, temp2);
    
    if (result <= T ) {
        cout << result;
    }
    else{
        cout << "Fail";
    }
    
    return 0;
}
