//인내의 도미노 장인 호석(20165)
//시뮬레이션 문제이다.
//dfs 재귀함수 조건이 까다로운 문제이다.

#include <algorithm>
#include <cstring>
#include <stdio.h>
#include <iostream>
#define MAX 100
 
using namespace std;

int board[MAX][MAX];
char checkBoard[MAX][MAX];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
//좌, 하, 우, 상 순서이다.

int N, M, R;
int result = 0;

int dirToInt(char dir){
    if (dir == 'E') {
        return 2;
    }
    else if (dir == 'W'){
        return 0;
    }
    else if (dir == 'S'){
        return 1;
    }
    return 3;
}

bool inRange(int X, int Y){
    return X >= 0 && X < N && Y >= 0 && Y < M;
}

void fallDomino(int cx, int cy, char cDir, int cnt){
    int dirIdx = dirToInt(cDir);
    int nx, ny;
    for (int i = 0; i < cnt; i++) {
        nx = cx + dx[dirIdx] * i;
        ny = cy + dy[dirIdx] * i;
        if (!inRange(nx, ny)) {
            continue;
        }
        if (checkBoard[nx][ny] == 'S') {
            //도미노가 위치한 경우만 처리하면 된다.
            if (i > 0) {
                fallDomino(nx, ny, cDir, board[nx][ny]);
                //i가 0이상인 경우 즉 현재 도미노가 다른 도미노를 넘어뜨리는 경우 해당 도미노 부터 다시 시작해야 한다.
            }
            else{
                result += 1;
                checkBoard[nx][ny] = 'F';
                //현재 도미노인 경우 넘어뜨리고 result를 += 1 하면 된다.
            }
        }
    }
}

int main(void){
    cin >> N >> M >> R;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            checkBoard[i][j] = 'S';
        }
    }
    for (int i = 0; i < R; i++) {
        int fX, fY;
        char cmd;
        cin >> fX >> fY >> cmd;
        //공격
        if (checkBoard[fX - 1][fY - 1] == 'S') {
            fallDomino(fX - 1, fY - 1, cmd, board[fX - 1][fY - 1]);
        }
        int dX, dY;
        cin >> dX >> dY;
        if (checkBoard[dX - 1][dY - 1] == 'F') {
            //수비는 넘어져 있는 도미노를 다시 세울 수 있다.
            checkBoard[dX - 1][dY - 1] = 'S';
        }
    }
    cout << result << "\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << checkBoard[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
