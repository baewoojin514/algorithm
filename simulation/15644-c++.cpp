//구슬 탈출3(15644)
//시뮬레이션 문제이다.
//dfs로 해결할 수 있다.
//skill.1 - 이전에 탐색했던 방향이거나 반대 방향은 탐색할 필요가 없다.
//skill.2 - 만약 회수가 10을 넘거나 현재 최소 값보다 큰 경우 return을 통해 prunning을 한다.
//skill.3 - 방향 index를 L,R,U,D로 바꾸는 함수를 구현한다.
//skill.4 - dfs의 parameter로 현재까지 기울인 방향들을 담고있는 string을 통해 재귀함수를 호출한다.

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <vector>
#define MAX 10
#define INF 1e9

using namespace std;

int N, M;
char board[MAX][MAX];
int rX, rY, bX, bY;
//빨간, 파란 공의 좌표를 저장한다.
int result = INF;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
//하, 상, 우, 좌 방향이다.
vector<string> dirResult;

char idxToChar(int idx){
    if (idx == 0) {
        return 'D';
    }
    else if (idx == 1) {
        return 'U';
    }
    else if (idx == 2){
        return 'R';
    }
    return 'L';
}

int reverseDir(int cdir){
    if (cdir == 0) {
        return 1;
    }
    else if (cdir == 1){
        return 0;
    }
    else if (cdir == 2){
        return 3;
    }
    return 2;
}

int calDist(int cx, int cy, int nx, int ny){
    return abs(cx - nx) + abs(cy - ny);
}

void dfs(int rx, int ry, int bx, int by, int tempCnt, int cdir, string temp){
    if (tempCnt > result || tempCnt > 10) {
        //현재 까지의 cnt가 result 또는 10 보다 크다면 return을 통해 prunning을 한다.
        return;
    }
    bool red = true;
    bool blue = true;
    int rsX, rsY, bsX, bsY;
    rsX = rx;
    rsY = ry;
    bsX = bx;
    bsY = by;
    while (true) {
        rx += dx[cdir]; ry += dy[cdir];
        if (board[rx][ry] == 'O') {
            red = false;
            break;
        }
        if (board[rx][ry] == '#') {
            break;
        }
    }
    rx -= dx[cdir];
    ry -= dy[cdir];
    while (true) {
        bx += dx[cdir]; by += dy[cdir];
        if (board[bx][by] == 'O') {
            blue = false;
            break;
        }
        if (board[bx][by] == '#') {
            break;
        }
    }
    bx -= dx[cdir];
    by -= dy[cdir];
    if (!blue) {
        //피란 공이 빠지면 무조건 return을 통해 prunning을 한다.
        return;
    }
    else{
        if (!red) {
            result = min(result, tempCnt);
            dirResult.push_back(temp);
            return;
        }
    }
    
    if (rx == bx && ry == by) {
        int temp1, temp2;
        temp1 = calDist(rx, ry, rsX, rsY);
        //빨간공이 이동한 거리이다.
        temp2 = calDist(bx, by, bsX, bsY);
        //파란공이 이동한 거리이다.
        if (temp1 > temp2) {
            //빨간공이 파란공 보다 이동한 거리가 더 길다면 한칸 뒤로 보내준다.
            rx -= dx[cdir];
            ry -= dy[cdir];
        }
        else if (temp1 < temp2){
            //파란공이 빨간공 보다 이동한 거리가 더 길다면 한칸 뒤로 보내준다.
            bx -= dx[cdir];
            by -= dy[cdir];
        }
    }
    for (int i = 0; i < 4; i++) {
        if (i == cdir) {
            //깉은 방향을 다시 탐색할 필요가 없다.
            continue;
        }
        if (i == reverseDir(cdir)) {
            //반대방향 역시 되돌아 탐색할 필요가 없다.
            continue;
        }
        char tempDir = idxToChar(i);
        temp += tempDir;
        dfs(rx, ry, bx, by, tempCnt + 1, i, temp);
        string temp2;
        temp2 = temp.substr(0, temp.size()-1);
        temp = temp2;
    }
}

int main(void){
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'R') {
                rX = i;
                rY = j;
            }
            if (board[i][j] == 'B') {
                bX = i;
                bY = j;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        char cdir = idxToChar(i);
        string temp1 = "";
        string temp2;
        temp1 += cdir;
        dfs(rX, rY, bX, bY, 1, i, temp1);
        temp2 = temp1.substr(0, temp1.size()-1);
        temp1 = temp2;
    }
    if (result > 10 || result == INF) {
        cout << -1;
    }
    else{
        string dirList;
        for (int i = 0; i < dirResult.size(); i++) {
            if (dirResult[i].size() == result) {
                dirList = dirResult[i];
            }
        }
        cout << result << "\n";
        cout << dirList;
    }
    
    return 0;
}
