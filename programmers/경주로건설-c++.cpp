//경주로 건설(programmers)
//bfs를 통해 해결 가능하다.
//0, 0 좌표에서 우측, 하단으로 출발하는 두가지 경우를 탐색해야 하기 때문에 bfs함수를 구현한다.
//visited 이차원 배열에 방문 여부를 cost로 표시한다.

#include <string>
#include <vector>
#include <cstring>
#include <deque>
#define MAX 25
#define INF 1e9

using namespace std;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {-1, 0, 1, 0};
int N;

bool inside(int X, int Y){
    return X >= 0 && X < N && Y >= 0 && Y < N;
}

int BFS(int dir, vector<vector<int>> board){
    int visited[MAX][MAX];
    memset(visited, -1, sizeof(visited));
    deque<pair<pair<int, int>, pair<int, int>>> q;
    q.push_back(make_pair(make_pair(0, 0), make_pair(0, dir)));
    visited[0][0] = 0;
    
    while (!q.empty()) {
        int cost, cx, cy, cdir;
        cost = q.front().first.first;
        cx = q.front().first.second;
        cy = q.front().second.first;
        cdir = q.front().second.second;
        
        q.pop_front();
        for (int i = 0; i < 4; i++) {
            int nx, ny;
            nx = cx + dx[i];
            ny = cy + dy[i];
            if (inside(nx, ny) && board[nx][ny] == 0) {
                if (visited[nx][ny] == -1) {
                    if (cdir == i) {
                        //같은 방향인 경우
                        visited[nx][ny] = cost + 100;
                        q.push_back(make_pair(make_pair(cost + 100, nx), make_pair(ny, i)));
                    }
                    else if ((cdir + 2) % 4 == i){
                        //수평한 방향인 경우
                        visited[nx][ny] = cost + 100;
                        q.push_back(make_pair(make_pair(cost + 100, nx), make_pair(ny, i)));
                    }
                    else {
                        //수직인 경우
                        visited[nx][ny] = cost + 600;
                        q.push_back(make_pair(make_pair(cost + 600, nx), make_pair(ny, i)));
                    }
                }
                else {
                    if (cdir == i) {
                        //같은 방향인 경우
                        if (visited[nx][ny] > cost + 100) {
                            visited[nx][ny] = cost + 100;
                            q.push_back(make_pair(make_pair(cost + 100, nx), make_pair(ny, i)));
                        }
                    }
                    else if ((cdir + 2) % 4 == i){
                        //수평한 방향인 경우
                        if (visited[nx][ny] > cost + 100) {
                            visited[nx][ny] = cost + 100;
                            q.push_back(make_pair(make_pair(cost + 100, nx), make_pair(ny, i)));
                        }
                    }
                    else {
                        //수직인 경우
                        if (visited[nx][ny] > cost + 600) {
                            visited[nx][ny] = cost + 600;
                            q.push_back(make_pair(make_pair(cost + 600, nx), make_pair(ny, i)));
                        }
                    }
                    
                }
            }
        }
    }
    return visited[N - 1][N - 1];
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    N = board.size();
    int result1 = BFS(1, board);
    int result2 = BFS(2, board);
    //아래 방향과 우측 방향으로 이동하는 두가지 경우에 대해서 최소값을 반환한다.
    answer = min(result1, result2);
    return answer;
}
