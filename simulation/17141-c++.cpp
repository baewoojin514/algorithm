//연구소 2(17141)
//N과 M의 dfs를 사용해서 M개의 바이러스를 선택하는 combination을 구현한다.
//combination 함수에서 M개의 virus를 선택하면 bfs를 사용해서 바이러스를 확산시킨다.


#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int N;
int M;

int visited[10];
//dfs를 사용한 combination 구현을 위해 visited 배열을 사용한다.

int minTime = 2500;
int board[50][50];
int dist[50][50];

int virusCount = 0;

queue<pair<int, int>> virus;
vector<pair<int, int>> canbe;
//바이러스가 위치 가능한 모든 좌표를 저장하는 vector

void dfs(int index, int limit){
    if (limit == M) {
        memset(dist, -1, sizeof(dist));
        for (int i = 0; i < canbe.size(); i++) {
            if (visited[i] == 1) {
                virus.push(make_pair(canbe[i].first, canbe[i].second));
                dist[canbe[i].first][canbe[i].second] = 0;
            }
        }
        int tempTime = 0;
        int tempCount = 0;
        
        while (!virus.empty()) {
            int cx, cy;
            cx = virus.front().first;
            cy = virus.front().second;
            virus.pop();
            
            for (int j = 0; j < 4; j++) {
                int nx, ny;
                nx = cx + dx[j];
                ny = cy + dy[j];
                if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                    if (board[nx][ny] != 1 && dist[nx][ny] == -1) {
                        dist[nx][ny] = dist[cx][cy] + 1;
                        //dist를 먼저 갱신해야 minTime을 제대로 계산할 수 있다.
                        tempTime = dist[nx][ny];
                        tempCount += 1;
                        virus.push(make_pair(nx, ny));
                    }
                }
                
            }
        }
        if (virusCount == tempCount) {
            minTime = min(minTime, tempTime);
        }
        return;
    }
    for (int k = index; k < canbe.size(); k++) {
        if (visited[k] == 0) {
            visited[k] = 1;
            dfs(k + 1, limit + 1);
            visited[k] = 0;
        }
    }
}


int main(void){
    
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 0) {
                virusCount += 1;
            }
            else if (board[i][j] == 2){
                canbe.push_back(make_pair(i, j));
                board[i][j] = 0;
                virusCount += 1;
            }
        }
    }
    virusCount -= M;
    dfs(0, 0);
    if (minTime == 2500) {
        cout << -1;
    }
    else{
        cout << minTime;
    }
    
    return 0;
}
