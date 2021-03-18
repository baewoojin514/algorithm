//배열 탈출(11909)
//다익스트라 알고리즘으로 해결할 수 있다.
//skill.1 - visited[][] 2차원 배열을 dist 1차원 배열 처럼 사용하여 다익스트라 알고리즘을 사용한다.
//skill.2 - visted[][]를 재방문 하는 경우 최소값으로 갱신하여 준다.
//skill.3 - visited[n - 1][n - 1]을 출력한다.

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>

#define MAX 2223
#define INF 1e9
//무한을 의미하는 값으로 10억을 설정한다.

using namespace std;

int board[MAX][MAX];
int visited[MAX][MAX];
int dx[2] = {0, 1};
int dy[2] = {1, 0};
//우측 하단 순서이다.

int n;

queue<pair<int, int>> pq;

int checkRange(int X, int Y){
    if (X >= 0 && X < n - 1 && Y >= 0 && Y < n - 1) {
        //하, 우 방향으로 이동 가능하다.
        return 1;
    }
    else if (X == n - 1 && Y >= 0 && Y < n - 1){
        //우측 방향으로 이동 가능하다.
        return 2;
    }
    else if (Y == n - 1 && X >= 0 && X < n - 1){
        return 3;
        //하단 방향으로 이동 가능하다.
    }
    return 4;
}

int main(void){
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            visited[i][j] = INF;
        }
    }
    pq.push({0, 0});
    visited[0][0] = 0;
    
    while (!pq.empty()) {
        int cx, cy;
        cx = pq.front().first;
        cy = pq.front().second;
        
        pq.pop();
        
        if (cx == n - 1 && cy ==  n - 1) {
            break;
        }
        
        int check = checkRange(cx, cy);
        if (check == 1) {
            for (int j = 0; j < 2; j++) {
                int nx, ny;
                nx = cx + dx[j];
                ny = cy + dy[j];
                if (board[nx][ny] >= board[cx][cy]) {
                    int temp = board[nx][ny] + 1 - board[cx][cy];
                    visited[nx][ny] = min(visited[nx][ny], visited[cx][cy] + temp);
                    pq.push({nx, ny});
                }
                else{
                    visited[nx][ny] = min(visited[nx][ny], visited[cx][cy]);
                    pq.push({nx, ny});
                }
            }
        }
        else if (check == 2){
            int nx, ny;
            nx = cx + dx[0];
            ny = cy + dy[0];
            if (board[nx][ny] >= board[cx][cy]) {
                int temp = board[nx][ny] + 1 - board[cx][cy];
                visited[nx][ny] = min(visited[nx][ny], visited[cx][cy] + temp);
                pq.push({nx, ny});
            }
            else{
                visited[nx][ny] = min(visited[nx][ny], visited[cx][cy]);
                pq.push({nx, ny});
            }
        }
        else if (check == 3){
            int nx, ny;
            nx = cx + dx[1];
            ny = cy + dy[1];
            if (board[nx][ny] >= board[cx][cy]) {
                int temp = board[nx][ny] + 1 - board[cx][cy];
                visited[nx][ny] = min(visited[nx][ny], visited[cx][cy] + temp);
                pq.push({nx, ny});
            }
            else{
                visited[nx][ny] = min(visited[nx][ny], visited[cx][cy]);
                pq.push({nx, ny});
            }
        }
    }
    cout << visited[n - 1][n - 1];
    return 0;
}
