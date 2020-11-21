//아기상어(16236)
//queue를 사용해서 bfs로 구현한다.
//queue의 이중 pair를 사용하여 python3와 동일한 logic으로 구현가능하다.
//가장 상단의 또 가장 왼쪽의 물고기를 구하는 방식이 python3보다 복잡하다.

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N;
int fish[20][20];

int totalTime = 0;
int fishSize = 2;
int tempEat = 0;

int visited[20][20];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int minDist = 0, minY = 999999999, minX = 999999999;

queue<pair<pair<int, int>, int>> shark;
queue<pair<pair<int, int>, int>> eat;

int main(void){
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> fish[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (fish[i][j] == 9) {
                shark.push(make_pair(make_pair(i, j), 0));
            }
        }
    }
    //queue의 pair를 이중으로 사용해서 좌표와 이동하는데 걸리는 시간을 저장한다.
    visited[shark.front().first.first][shark.front().first.second] = 1;
    fish[shark.front().first.first][shark.front().first.second] = 0;
    
    while (!shark.empty()) {
        int sharkSize = int(shark.size());
        //python3와 달리 queue에서 pop연산을 할경우 queue의 size를 미리 할당해 놓고 for문에 사용하여야 한다.
        for (int i = 0; i < sharkSize; i++) {
            int cx = shark.front().first.first;
            int cy = shark.front().first.second;
            int ct = shark.front().second;
            shark.pop();
            for (int j = 0; j < 4; j++) {
                int nx = cx + dx[j];
                int ny = cy + dy[j];
                if (nx >= 0 && nx < N && ny >= 0 && ny <N) {
                    if (visited[nx][ny] == 0) {
                        if (fish[nx][ny] > 0 && fish[nx][ny] < fishSize) {
                            eat.push(make_pair(make_pair(nx, ny), ct + 1));
                            visited[nx][ny] = 1;
                        }
                        //먹을 수 있는 물고기면 eat queue에 추가한다.
                        else if (fish[nx][ny] == 0 || fish[nx][ny] == fishSize){
                            shark.push(make_pair(make_pair(nx, ny), ct + 1));
                            visited[nx][ny] = 1;
                        }
                        //이동할 수 있는 좌표이면 이동한다.
                    }
                }
            }
        }
        if (eat.size() != 0) {
            int eatSize = int(eat.size());
            for (int i = 0; i < eatSize; i++) {
                int cx = eat.front().first.first;
                int cy = eat.front().first.second;
                int cd = eat.front().second;
                eat.pop();
                if (cx < minX) {
                    minX = cx;
                    minY = cy;
                    minDist = cd;
                }
                else if (cx == minX){
                    if (cy < minY) {
                        minY = cy;
                        minX = cx;
                        minDist = cd;
                    }
                }
            }
            tempEat += 1;
            if (tempEat == fishSize) {
                fishSize += 1;
                tempEat = 0;
            }
            fish[minX][minY] = 0;
            while (!shark.empty()) {
                shark.pop();
            }
            //python과 다르게 일일히 큐를 비워주어야 한다.
            shark.push(make_pair(make_pair(minX, minY), 0));
            totalTime += minDist;
            memset(visited, 0, sizeof(visited));
            visited[minX][minY] = 1;
            minDist = 0;
            minY = 999999999;
            minX = 999999999;
        }
        //python에서 if eat과 같은 의미로 사용할 수 있다.
        //python에서는 queue에서 min값을 추출하면 자동으로 문제의 조건에 명시되어 있는 좌표가 출력되었다. 하지만 c++에서는 조금더 섬세한 구현이 필요하다.
    }
    cout << totalTime;
    return 0;
}
