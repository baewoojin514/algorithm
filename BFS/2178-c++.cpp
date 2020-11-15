//미로 탐색(2178)
//python과 동일한 알고리즘으로 문제를 해결한다.
//STL queue를 사용해서 bfs로 구현한다.
//마지막에 dist배열의 N-1, M-1을 출력한다.

#include <iostream>
#include <queue>

using namespace std;

int maze[101][101];
int dist[101][101];
int visited[101][101];
//배열의 크기만 지정하면 요소들은 0으로 초기화 된다.
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int N, M;

int main(void){
    cin >> N >> M;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            scanf("%1d", &maze[i][j]);
        }
    }
    queue<pair<int, int>> q;
    //python의 deque와 비슷한 원리로 사용한다.
    q.push(make_pair(0, 0));
    visited[0][0] = 1;
    dist[0][0] = 1;
    
    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i ++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx >= 0 && nx < N && ny >= 0 && ny < M){
                if (visited[nx][ny] == 0 && maze[nx][ny] == 1){
                    q.push(make_pair(nx, ny));
                    visited[nx][ny] = 1;
                    dist[nx][ny] = dist[cx][cy] + 1;
                }
            }
        }
    }
    printf("%d\n", dist[N - 1][M - 1]);
    
    return 0;
}
