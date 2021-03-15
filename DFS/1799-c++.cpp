//비숍(1799)
//시뮬레이션 문제이다.
//skill.1 - 체스판의 흑.백은 서로 비숍을 놓아도 영향을 미치지 못한다.
//skill.2 - 흑.백을 1, 2 즉 색깔로 구분하고 dfs를 각각 색깔에 대해 호출한다.

#include <algorithm>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#define MAX 10

using namespace std;

int N;
int check[MAX][MAX];

int bx[4] = {-1, -1, 1, 1};
int by[4] = {-1, 1, -1, 1};

int answer[3];
//정답을 저장할
int wL;
int bL;
//흑백 vector의 길이

vector<pair<int, int>> white;
//1저장
vector<pair<int, int>> black;
//2저장

bool inRange(int X, int Y){
    return X >= 0 && X < N && Y >= 0 && Y < N;
}

bool canBishop(int X, int Y){
    //대각선 4방향을 탐색하며 비숍을 놓을 수 있는지 확인한다.
    for (int i = 0; i < 4; i++) {
        int cx = X;
        int cy = Y;
        while (true) {
            if (!inRange(cx, cy)) {
                break;
            }
            if (check[cx][cy]) {
                //check 즉 비숍이 놓아져 있다면 놓을 수 없는 좌표임으로 false를 반환한다.
                return false;
            }
            cx += bx[i];
            cy += by[i];
        }
    }
    return true;
}

void dfs(int idx, int cnt, int color){
    answer[color] = max(answer[color], cnt);
    if (color == 1) {
        for (int i = idx + 1; i < wL; i++) {
            int cx, cy;
            cx = white[i].first;
            cy = white[i].second;
            if (!canBishop(cx, cy)) {
                continue;
            }
            check[cx][cy] = 1;
            dfs(i, cnt + 1, color);
            check[cx][cy] = 0;
        }
    }
    if (color == 2) {
        for (int i = idx + 1; i < bL; i++) {
            int cx, cy;
            cx = black[i].first;
            cy = black[i].second;
            if (!canBishop(cx, cy)) {
                continue;
            }
            check[cx][cy] = 1;
            dfs(i, cnt + 1, color);
            check[cx][cy] = 0;
        }
    }
}

int main(void){
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int input;
            cin >> input;
            if (input == 1) {
                if (i%2 == 0) {
                    if (j%2 == 0) {
                        white.push_back({i, j});
                    }
                    else{
                        black.push_back({i, j});
                    }
                }
                else{
                    if (j%2 == 1) {
                        white.push_back({i, j});
                    }
                    else{
                        black.push_back({i, j});
                    }
                }
            }
        }
    }
    wL = white.size();
    bL = black.size();
    dfs(-1, 0, 1);
    dfs(-1, 0, 2);
    
    cout << answer[1] + answer[2];
    
    return 0;
}
