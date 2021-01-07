//연구소3(17142)
//python3와 같은 방식으로 구현한다.
//바이러스 m개를 선택하는 경우 python3에서는 combination을 사용하면 되지만 c++에서는 dfs를 사용해서 재귀로 구현해야 한다.
//비활성화 바이러스가 활성화 바이러스로 변하여 퍼뜨리는 경우를 제외해야 한다.
//skill.1 - 처음에 바이러스를 순수하게 퍼뜨릴 수 있는 빈칸 즉 0의 개수를 count한다.
//skill.2 - 빈칸에 바이러스를 퍼뜨리는 경우를 count한다.
//skill.3 - 2개의 count가 동일할 경우 빈칸에 바이러스를 퍼뜨린 경우이다. 이경우 빈칸이 존재하지 않다면 그 시간을 최소값으로 갱신한다.
//skill.4 - dfs를 함수로 재귀 함수로 구현하고 선택한 바이러스가 M개일 경우 bfs실행한다.

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int minTime = 2500;
//50 x 50 = 2500
int visited[10];
//바이러스는 최대 10개 임으로 재귀 함수에서 선택 여부를 판별하기 위해 사용한다.
int virusCount = 0;
void virusSpread(void);
//parameter가 없는 void함수를 호출하는 방법이다.

vector<pair<int, int>> virus;
queue<pair<int, int>> tempVirus;

int board[50][50];
int dist[50][50];
int N;
int M;

void dfs(int index, int limit){
    if (limit == M) {
        memset(dist, -1, sizeof(dist));
        //모든 경우의 수를 확인하기 위해 dist배열을 -1로 초기화 한다.
        for (int i = 0; i < virus.size(); i++) {
            if (visited[i] == 1) {
                tempVirus.push(make_pair(virus[i].first, virus[i].second));
                dist[virus[i].first][virus[i].second] = 0;
            }
        }
        virusSpread();
        return;
    }
    for (int j = index; j < virus.size(); j++) {
        if (visited[j] == 1) {
            continue;
        }
        visited[j] = 1;
        dfs(j + 1, limit + 1);
        visited[j] = 0;
        //backtracking!!
    }
    
}

void virusSpread(void){
    int tempTime = 0;
    int tempCount = 0;
    
    while (!tempVirus.empty()) {
        int cx, cy;
        cx = tempVirus.front().first;
        cy = tempVirus.front().second;
        tempVirus.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx, ny;
            nx = cx + dx[i];
            ny = cy + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                if (board[nx][ny] != 1 && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[cx][cy] + 1;
                    if (board[nx][ny] == 0) {
                        tempCount += 1;
                        tempTime = dist[nx][ny];
                    }
                    tempVirus.push(make_pair(nx, ny));
                    
                }
            }
        }
    }
    if (tempCount == virusCount) {
        minTime = min(minTime, tempTime);
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
                virus.push_back(make_pair(i, j));
            }
        }
    }
    dfs(0, 0);
    
    if (minTime == 2500) {
        cout << -1;
    }
    else{
        cout << minTime;
    }
    return 0;
}
