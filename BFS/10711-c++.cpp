//모래성(10711)
//bfs를 통해 8방향을 탐색하여 0인 부분을 count하고 count [i][j]인 경우 0으로 바꿔준다.
//skill.1 - 모래성이 파도에 의해서 사라지는 경우 0으로 표시한다.
//skill.2 - 모래성의 상태가 변하지 않는 경우 break를 통해 종료하고 time을 출력한다.

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#define MAX 1000

using namespace std;

int board[MAX][MAX];
int temp[MAX][MAX];

int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

int times = 0;

int H, W;

bool inRange(int X, int Y){
    return X >= 0 && X < H && Y >= 0 && Y < W;
}

void sandCastle(){
    while (true) {
        memset(temp, 0, sizeof(temp));
        vector<pair<int, int>> castleBrick;
        
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (board[i][j]) {
                    //모래성이 있는 경우만 탐색하면 된다.
                    int cx, cy, compare;
                    cx = i;
                    cy = j;
                    compare = board[i][j];
                    int cnt = 0;
                    for (int k = 0; k < 8; k++) {
                        int nx, ny;
                        nx = cx + dx[k];
                        ny = cy + dy[k];
                        if (inRange(nx, ny) && !board[nx][ny]) {
                            cnt += 1;
                        }
                    }
                    if (cnt >= compare) {
                        temp[cx][cy] = 1;
                        castleBrick.push_back(make_pair(cx, cy));
                    }
                }
            }
        }
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (temp[i][j]) {
                    board[i][j] = 0;
                }
            }
        }
        if (castleBrick.empty()) {
            return;
        }
        times += 1;
    }
}

int main(void){
    cin >> H >> W;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char input;
            cin >> input;
            if (input == '.') {
                board[i][j] = 0;
            }
            else{
                board[i][j] = input - '0';
            }
            
        }
    }
    sandCastle();
    
    cout << times;
    
    return 0;
}

//모래성(10711)
//bfs를 통해 해결할 수 있다.
//skill.1 - queue에 파도의 좌표들을 저장한다.
//skill.2 - queue에 저장된 좌표의 8방향에 대해서 탐색하고 모래성이 있는 경우 -=1 을 한다.
//skill.3 - 모래성이 0이 되면 queue에 저장한다. queue가 empty 상태라면 break를 통해 종료한다.

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#define MAX 1000

using namespace std;

int board[MAX][MAX];
queue<pair<int, int>> wave;

int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

int times = 0;

int H, W;

bool inRange(int X, int Y){
    return X >= 0 && X < H && Y >= 0 && Y < W;
}

void sandCastle(){
    while (true) {
        int qLen = wave.size();
        for (int i = 0; i < qLen; i++) {
            int cx, cy;
            cx = wave.front().first;
            cy = wave.front().second;
            
            wave.pop();
            for (int j = 0; j < 8; j++) {
                int nx, ny;
                nx = cx + dx[j];
                ny = cy + dy[j];
                if (inRange(nx, ny) && board[nx][ny]) {
                    board[nx][ny] -= 1;
                    //파도는 모래성에 영향을 줄 수 있다 따라서 -=1 한다.
                    if (board[nx][ny] == 0) {
                        //모래성이 무너지면 파도 queue에 추가한다.
                        wave.push(make_pair(nx, ny));
                    }
                }
            }
        }
        if (wave.empty()) {
            //파도 queue가 empty인 경우 더이상 상태가 변하지 않기 때문에 종료한다.
            return;
        }
        times += 1;
    }

}

int main(void){
    cin >> H >> W;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char input;
            cin >> input;
            if (input == '.') {
                board[i][j] = 0;
                wave.push(make_pair(i, j));
            }
            else{
                board[i][j] = input - '0';
            }
            
        }
    }
    sandCastle();
    
    cout << times;
    
    return 0;
}

