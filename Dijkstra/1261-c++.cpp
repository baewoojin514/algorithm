//알고스팟(1261)
//python3와 동일한 알고리즘으로 풀이한다.
//python3의 heapq인 우선순위 큐를 사용한다.
//cnt를 -로 넣어서 가장 작은 cnt에 해당하는 경우가 먼저 pop되도록 구현한다.
//while문 초기에 목적지에 도착했는지 검사하고 cnt를 출력후 break를 통해 종료한다.
//우선순위 큐의 경우 front가 아니라 top으로 첫번째 요소를 사용한다.

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

int N;
int M;

int board[100][100];
int visited[100][100];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

priority_queue<pair<pair<int, int>, int>> q;
//우선순위 큐를 선언한다.

int main(void){
    cin >> M >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &board[i][j]);
            //입력을 잘 확인하고 행의 요소들이 붙어 있는 경우 scanf를 사용해서 구현한다.
        }
    }
    q.push({{0, 0}, 0});
    //cnt, 좌표 순으로 삽입한다.
    visited[0][0] = 1;
    while (!q.empty()) {
        int cnt = -q.top().first.first;
        int cx = q.top().first.second;
        int cy = q.top().second;
        q.pop();
        if (cx == N - 1 && cy == M - 1) {
            cout << cnt;
            break;
        }
        else{
            for (int k = 0; k < 4; k++) {
                int nx = cx + dx[k];
                int ny = cy + dy[k];
                if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                    if (visited[nx][ny] == 0) {
                        if (board[nx][ny] == 0) {
                            visited[nx][ny] = 1;
                            q.push({{-cnt, nx}, ny});
                        }
                        else if (board[nx][ny] == 1){
                            visited[nx][ny] = 1;
                            q.push({{-(cnt + 1), nx}, ny});
                        }
                    }
                }
            }
            
        }
    }
    
    return 0;
}
