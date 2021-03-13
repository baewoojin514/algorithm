//낚시왕(17143)
//시뮬레이션 문제이다.
//skill.1 - 열을 기준으로 이동하면서 상어를 잡아먹는다(huntShark 함수).
//skill.2 - 상어가 움직이는 함수를 구현한다.

#include <algorithm>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#define MAX 100

using namespace std;

struct SHARK{
    int s, d, z;
};
//좌표, 속력, 방향, 크기 순서이다.

vector<SHARK> shark[MAX][MAX];
vector<SHARK> tempShark[MAX][MAX];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
//상, 하, 우, 좌 순서이다.

int result = 0;
int changeDir[4] = {1, 0, 3, 2};

int R, C, M;

bool inRange(int X, int Y){
    return X >= 0 && X < R && Y >= 0 && Y < C;
}

void eatShark(int idx){
    for (int i = 0; i < R; i++) {
        if (shark[i][idx].size() != 0) {
            result += shark[i][idx][0].z;
            shark[i][idx].pop_back();
            break;
        }
    }
}
void moveShark(){
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (shark[i][j].size() == 0) {
                continue;
            }
            int cx, cy, cdir, cvelo, csize;
            cx = i; cy = j; cdir = shark[i][j][0].d; cvelo = shark[i][j][0].s; csize = shark[i][j][0].z;
            shark[i][j].pop_back();
            for (int k = 0; k < cvelo; k++) {
                cx += dx[cdir];
                cy += dy[cdir];
                if (!inRange(cx, cy)) {
                    cdir = changeDir[cdir];
                    cx += dx[cdir] * 2;
                    cy += dy[cdir] * 2;
                }
            }
            if (tempShark[cx][cy].size() != 0) {
                if (tempShark[cx][cy][0].z < csize) {
                    //원래 상어가 있는 경우 크기를 비교한다.
                    tempShark[cx][cy].pop_back();
                    tempShark[cx][cy].push_back({cvelo, cdir, csize});
                }
            }
            else{
                //상어가 없던 곳이면 그냥 push_back 한다.
                tempShark[cx][cy].push_back({cvelo, cdir, csize});
            }
        }
    }
    return;
}


int main(void){
    cin >> R >> C >> M;
    for (int i = 0; i < M; i++) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        r -= 1;
        c -= 1;
        d -= 1;
        if (d == 0 || d == 1) {
            s %= (2 * (R - 1));
        }
        if (d == 2 || d == 3) {
            s %= (2 * (C - 1));
        }
        shark[r][c].push_back({s, d, z});
    }
    for (int i = 0; i < C; i++) {
        eatShark(i);
        for (int j = 0; j < R; j++) {
            for (int k = 0; k < C; k++) {
                tempShark[j][k].clear();
            }
        }
        //tempShark를 초기화 한다.
        moveShark();
        for (int j = 0; j < R; j++) {
            for (int k = 0; k < C; k++) {
                shark[j][k] = tempShark[j][k];
            }
        }
    }
    cout << result;
    return 0;
}
