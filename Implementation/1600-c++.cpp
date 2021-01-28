//말이 되고픈 원숭이(1600)
//python3 와 풀이 방법이 동일하다.
//원숭이의 이동 즉 BFS를 함수로 구현한다.
//K번 말 처럼 이동할 수 있다.
//말 처럼 이동하는 능력을 사용한 회수가 K보다 작은 경우 먼저 말 처럼 이동한 정보를 deque에 append한다.
//skill.1 - 같은 좌표라 할지라도 말의 능력을 사용한 경우의 수를 구분해야 한다.
//skill.2 - visited 리스트를 3차원으로 만든다 => 같은 회수에 대해서는 먼저 도착한 경우가 선점한다.
//skill.3 - 목표 지점에 도착한 경우 이동한 회수를 출력한다.
//skill.4 - deque에 삽입해야 할 정보는 좌표, 말의 능력을 사용한 회수, 이동한 회수 이다.


#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int result;

int K;
int W, H;
int board[200][200];
int visited[200][200][31];

queue<pair<pair<int, int>, pair<int, int>>> monkey;
//좌표, 사용한 말의 능력의 개수, 이동 회수

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int hdx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int hdy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

int bfs(int x, int y){
    visited[0][0][0] = 1;
    monkey.push(make_pair(make_pair(0, 0), make_pair(0, 0)));
    
    while (!monkey.empty()) {
        int cx, cy, horsePower, cnt;
        cx = monkey.front().first.first;
        cy = monkey.front().first.second;
        horsePower = monkey.front().second.first;
        cnt = monkey.front().second.second;
        
        monkey.pop();
        
        if (cx == H - 1 && cy == W - 1) {
            return cnt;
        }
        
        if (horsePower < K) {
            for (int i = 0; i < 8; i++) {
                int nx, ny;
                nx = cx + hdx[i];
                ny = cy + hdy[i];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W) {
                    if (board[nx][ny] == 0 && visited[nx][ny][horsePower + 1] == 0) {
                        visited[nx][ny][horsePower + 1] = 1;
                        monkey.push(make_pair(make_pair(nx, ny), make_pair(horsePower + 1, cnt + 1)));
                    }
                }
            }
        }
        for (int i = 0; i < 4; i++) {
            int nx, ny;
            nx = cx + dx[i];
            ny = cy + dy[i];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W) {
                if (board[nx][ny] == 0 && visited[nx][ny][horsePower] == 0) {
                    visited[nx][ny][horsePower] = 1;
                    monkey.push(make_pair(make_pair(nx, ny), make_pair(horsePower, cnt + 1)));
                    
                }
            }
        }
    }
    
    return -1;
}

    
int main(void){
    
    cin >> K;
    cin >> W >> H;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> board[i][j];
        }
    }
    result = bfs(0, 0);
    
    cout << result;
    
    return 0;
}
