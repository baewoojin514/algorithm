//마법사 상어와 토네이도(20057)
//시뮬레이션 문제이다.
//dfs재귀 함수를 구현한다.
//skill.1 - 토네이도는 각기 다른 방향에 대해서 2번 같은 거리로 움직인다(예외 : 마지막에 N거리로 3번 움직인다).
//skill.2 - 일정 비율로 모래를 퍼뜨릴 때 4방향에 대해서 퍼지는 좌표와 해당 좌표로 퍼지는 비율을 각각 배열에 저장한다.

#include <algorithm>
#include <cstring>
#include <stdio.h>
#include <iostream>
#define MAX 499
 
using namespace std;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {-1, 0, 1, 0};
//좌, 하, 우, 상 순서이다.

const int sandRatio[9] = {1, 1, 7, 7, 2, 2, 10, 10, 5};
//흩날리는 모래의 비율이다.

const int spreadX[4][9] = {{-1, 1, -1, 1, -2, 2, -1, 1, 0}, {-1, -1, 0, 0, 0, 0, 1, 1, 2}, {-1, 1, -1, 1, -2, 2, -1, 1, 0}, {1, 1, 0, 0, 0, 0, -1, -1, -2}};
const int spreadY[4][9] = {{1, 1, 0, 0, 0, 0, -1, -1, -2}, {1, -1, 1, -1, 2, -2, 1, -1, 0}, {-1, -1, 0, 0, 0, 0, 1, 1, 2}, {1, -1, 1, -1, 2, -2, 1, -1, 0}};
//방향별 비율이 퍼지는 좌표이다.

int board[MAX][MAX];
int N;
int stx, sty;
int result = 0;

bool inRange(int X, int Y){
    return X >= 0 && X < N && Y >= 0 && Y < N;
}
void sandSpread(int dir){
    int tempVal = board[stx][sty];
    //tempVal에 해당하는 모래양을 퍼뜨려야 한다.
    for (int i = 0; i < 9; i++) {
        int nx, ny;
        nx = stx + spreadX[dir][i];
        ny = sty + spreadY[dir][i];
        int tempSand = (sandRatio[i] * tempVal) / 100;
        board[stx][sty] -= tempSand;
        //일정한 비율로 퍼질 수 있는 모래의 양이다.
        if (inRange(nx, ny)) {
            //범위 내라면 해당 좌표에 더한다.
            board[nx][ny] += tempSand;
        }
        else if (!inRange(nx, ny)){
            //범위 밖으로 나간다면 result에 더한다.
            result += tempSand;
        }
    }
    //일정 비율로 퍼진 모래를 제외한 모래를 더음 좌표로 퍼뜨린다.
    int nx, ny;
    nx = stx + dx[dir];
    ny = sty + dy[dir];
    if (!inRange(nx, ny)) {
        result += board[stx][sty];
        board[stx][sty] = 0;
        return;
        //모래가 모두 이동하면 0으로 바꿔준다.
    }
    board[nx][ny] += board[stx][sty];
    board[stx][sty] = 0;
}

void dfs(int dir){
    int cnt = 1;
    int cDir = dir;
    for (int i = 1; i < 2*N - 1; i++) {
        for (int k = 0; k < cnt; k++) {
            stx += dx[cDir];
            sty += dy[cDir];
            sandSpread(cDir);
        }
        cDir = (cDir + 1) % 4;
        if (i % 2 == 0) {
            cnt += 1;
        }
    }
}

int main(void){
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    //토네이도는 항상 중앙지점에서 시작한다.
    stx = N / 2;
    sty = N / 2;
    
    dfs(0);
    
    for (int i = 0; i < N; i++) {
        stx += dx[0];
        sty += dy[0];
        //dis 만큼 이동하면서 바람을 퍼뜨린다.
        sandSpread(0);
    }
    //마지막 N - 1번 만큼은 총 3번 이동하기 때문에 한번 더 이동시키고 모래를 퍼뜨려야 한다.
    cout << result;
    
    return 0;
}
