//화성 탐사
//bfs 탐색을 통해 해결할 수 있다.
//skill.1 - 최소비용으로 이동해야 하기 때문에 우선순위 큐를 사용해서 비용이 가장 적은 경우를 먼저 탐색한다.
//skill.2 - [N - 1][N - 1]에 도착한 경우 cost를 출력하고 break문을 통해 종료한다.

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

#define MAX 126

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int T;
priority_queue<pair<pair<int, int>, int>> pq;
int board[MAX][MAX];
int visited[MAX][MAX];

int main(void){
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                cin >> board[j][k];
            }
        }
        visited[0][0] = 1;
        pq.push({{-board[0][0], 0}, 0});
        while (!pq.empty()) {
            int cost, x, y;
            cost = -pq.top().first.first;
            x = pq.top().first.second;
            y = pq.top().second;
            
            pq.pop();
            
            if (x == N - 1 && y == N - 1) {
                printf("%d\n", cost);
            }
            for (int j = 0; j < 4; j++) {
                int nx, ny;
                nx = x + dx[j];
                ny = y + dy[j];
                if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                    if (visited[nx][ny] == 0) {
                        visited[nx][ny] = 1;
                        pq.push(make_pair(make_pair(-(cost + board[nx][ny]), nx), ny));
                    }
                }
            }
        }
        pq.empty();
        memset(visited, 0, sizeof(visited));
        memset(board, 0, sizeof(board));
    }
    return 0;
}
