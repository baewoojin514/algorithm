#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string.h>

using namespace std;

char board[12][6];
int visited[12][6];
int result;
vector<pair<int, int>> tmpIdx;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool inRange(int cx, int cy){
    return cx >= 0 && cx < 12 && cy >= 0 && cy < 6;
}

int cntSameColor(int stX, int stY){
    int tempCnt = 1;
    char tempColor = board[stX][stY];
    
    queue<pair<int, int>> q;
    q.push(make_pair(stX, stY));
    
    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if (inRange(nx, ny) && !visited[nx][ny]) {
                if (board[nx][ny] == tempColor) {
                    visited[nx][ny] = 1;
                    q.push(make_pair(nx, ny));
                    tmpIdx.push_back(make_pair(nx, ny));
                    tempCnt += 1;
                }
            }
        }
    }
    return tempCnt;
}

void delBoard(){
    for (int i = 0; i < tmpIdx.size(); i++) {
        int cx = tmpIdx[i].first;
        int cy = tmpIdx[i].second;
        
        board[cx][cy] = '.';
    }
}

void moveBoard(){
    for (int i = 0; i < 6; i++) {
        char tmpBrd[] = "............";
        int cnt = 0;
        for (int j = 11; j >= 0; j--) {
            if (board[j][i] != '.') {
                cnt += 1;
                tmpBrd[cnt - 1] = board[j][i];
            }
        }
        for (int j = 0; j < 12; j++) {
            board[11 - j][i] = tmpBrd[j];
        }
    }
}

int main(void)
{
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> board[i][j];
        }
    }
    
    result = 0;
    while (true) {
        moveBoard();
        
        int flag = 0;
        memset(visited, 0, sizeof(visited));
        for (int i = 11; i >= 0; i--) {
            for (int j = 0; j < 6; j++) {
                if (board[i][j] != '.' && !visited[i][j]) {
                    tmpIdx.push_back(make_pair(i, j));
                    visited[i][j] = 1;
                    
                    if (cntSameColor(i, j) >= 4) {
                        flag += 1;
                        delBoard();
                    }
                    tmpIdx.clear();
                }
            }
        }
        if (!flag) {
            break;
        }
        result += 1;
    }
    
    cout << result;
    
    return 0;
}
