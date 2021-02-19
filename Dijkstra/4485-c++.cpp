//녹색 옷 입은 애가 젤다지?(4485)
//bfs로 해결 가능하다.
//skill.1 - 루피가 최소가 되게 이동해야 한다. 즉 이동한 좌표의 요소값이 최소가 되게 이동해야 한다.
//skill.2 - 우선순위 큐를 사용해서 다익스트라 알고리즘으로 해결할 수 있다.
//skill.3 - [N - 1][N - 1]에 도착하면 이동하면서 잃은 루피의 총합을 출력한다.

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#define MAX 125
//대문자 알파벳의 개수는 26개이다.

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int T = 1;

int N;
int board[MAX][MAX];
int visited[MAX][MAX];
priority_queue<pair<pair<int, int>, int>> pq;

int main(void){
    while (true) {
        cin >> N;
        
        if (N == 0) {
            break;
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> board[i][j];
            }
        }
        visited[0][0] = 1;
        pq.push({{-board[0][0], 0}, 0});
        while (!pq.empty()) {
            int rupee, cx, cy;
            rupee = -pq.top().first.first;
            cx = pq.top().first.second;
            cy = pq.top().second;
            
            pq.pop();
            
            if (cx == N - 1 && cy == N - 1) {
                cout << "Problem " << T << ":" << " " << rupee << "\n";
                T++;
            }
            for (int j = 0; j < 4; j++) {
                int nx, ny;
                nx = cx + dx[j];
                ny = cy + dy[j];
                if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                    if (visited[nx][ny] == 0) {
                        visited[nx][ny] = 1;
                        pq.push(make_pair(make_pair(-(rupee + board[nx][ny]), nx), ny));
                    }
                }
            }
            
        }
        pq.empty();
        memset(board, 0, sizeof(board));
        memset(visited, 0, sizeof(visited));
    }
    return 0;
}
