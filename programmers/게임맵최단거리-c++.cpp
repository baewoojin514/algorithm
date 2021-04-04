//게임 맵 최단거리(programmers)
//bfs로 해결할 수 있다.
//skill.1 - 2차원 배열에 최단거리를 저장한다.
//skill.2 - 최단 거리를 계산하기 위해서는 방문한 곳을 다시 방문하는 경우가 발생한다.
//skill.3 - cost[nx] > cost[cx] + 1인 경우 최소값으로 갱신한다.

#include <vector>
#include <queue>
#include <cstring>
#define MAX 100
#define INF 1e9
using namespace std;

int cost[MAX][MAX];
queue<pair<int, int>> q;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int N, M;

bool inRange(int X, int Y){
    return X >= 0 && X < N && Y >= 0 && Y < M;
}

int solution(vector<vector<int>> maps)
{
    N = maps.size();
    M = maps[0].size();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cost[i][j] = INF;
        }
    }

    q.push(make_pair(0, 0));
    cost[0][0] = 1;
    
    while (!q.empty()) {
        int cx, cy;
        cx = q.front().first;
        cy = q.front().second;
        
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx, ny;
            nx = cx + dx[i];
            ny = cy + dy[i];
            if (inRange(nx, ny) && maps[nx][ny] == 1) {
                if (cost[nx][ny] > cost[cx][cy] + 1) {
                    cost[nx][ny] = cost[cx][cy] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    
    int answer = 0;
    if (cost[N - 1][M - 1] == INF) {
        answer = -1;
    }
    else{
        answer = cost[N - 1][M - 1];
    }
    return answer;
}
