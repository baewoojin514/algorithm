//현수막(14716)
//deque를 사용해서 문제를 해결한다.
//2차원 visited 배열을 사용해야 한다.
//bfs방식으로 python3와 동일한 알고리즘으로 구현한다.
//1로 인접한 8방향으로 서로 연결된 덩어리의 개수를 count한다.

#include <iostream>
#include <queue>

using namespace std;

int M;
int N;
bool visited[250][250];
//배열의 모든 요소는 false로 초기화 되어 있다.
int banner[250][250];

int dx[8] = {-1, 0, 1, 0, 1, 1, -1, -1};
int dy[8] = {0, -1, 0, 1, 1, -1, 1, -1};

int totoalCount = 0;

int main(void){
    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> banner[i][j];
        }
    }
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (banner[i][j] == 1 && visited[i][j] == false) {
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                visited[i][j] = true;
                
                while (!q.empty()) {
                    int cx = q.front().first;
                    int cy = q.front().second;
                    q.pop();
                    for (int k = 0; k < 8; k++) {
                        int nx = cx + dx[k];
                        int ny = cy + dy[k];
                        if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
                            if (visited[nx][ny] == false && banner[nx][ny] == 1) {
                                visited[nx][ny] = true;
                                q.push(make_pair(nx, ny));
                            }
                        }
                    }
                    
                }
                totoalCount += 1;
            }
        }
    }
    printf("%d", totoalCount);
    return 0;
}
