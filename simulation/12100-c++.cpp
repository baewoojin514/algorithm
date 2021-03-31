//2048(Easy)
//시뮬레이션 문제이다.
//dfs로 해결할 수 있다.
//skill.1 - 최대 5번 이동할 수 있다. 따라서 0, 1, 2, 3 의 길이 5인 중복수열을 dfs를 통해 구한다.
//skill.2 - 5개의 방향에 대해 좌표들을 움직인다.
//skill.3 - 이동 방향으로 인접한 좌표의 값고 동일한 값이 있다면 해당 값이 * 2를 한다.
//skill.4 - 이동 방향으로 다시 한번 이동한다.
//skill.5 - 5번 이동한 후 board에 있는 최대 값으로 result를 갱신한다.

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <stdio.h>
#include <cstring>
#include <vector>
#define MAX 20

using namespace std;

int board[MAX][MAX];
int temp[MAX][MAX];
vector<int> canbe;

int N;
int result = 0;

bool inRange(int X, int Y){
    return X >= 0 && X < N && Y >= 0 && Y < N;
}

void copy_board(){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            temp[i][j] = board[i][j];
        }
    }
    return;
}

void move_left(){
    for (int i = 0; i < N; i++) {
        for (int j = 1; j < N; j++) {
            if (temp[i][j]) {
                int cy = j;
                while (true) {
                    cy -= 1;
                    //왼쪽으로 한칸씩 이동한다.
                    if (temp[i][cy]) {
                        break;
                    }
                    if (!inRange(i, cy)) {
                        break;
                    }
                }
                cy += 1;
                if (cy != j) {
                    //이동할 수 없는 경우는 이동할 필요가 없다.
                    temp[i][cy] = temp[i][j];
                    temp[i][j] = 0;
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {
            if (temp[i][j] == temp[i][j + 1]) {
                temp[i][j] *= 2;
                temp[i][j + 1] = 0;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 1; j < N; j++) {
            if (temp[i][j]) {
                int cy = j;
                while (true) {
                    cy -= 1;
                    //왼쪽으로 한칸씩 이동한다.
                    if (temp[i][cy]) {
                        break;
                    }
                    if (!inRange(i, cy)) {
                        break;
                    }
                }
                cy += 1;
                if (cy != j) {
                    //이동할 수 없는 경우는 이동할 필요가 없다.
                    temp[i][cy] = temp[i][j];
                    temp[i][j] = 0;
                }
            }
        }
    }
    return;
}

void move_down(){
    for (int i = N - 2; i >= 0; i--) {
        for (int j = 0; j < N; j++) {
            if (temp[i][j]) {
                int cx = i;
                while (true) {
                    cx += 1;
                    if (temp[cx][j]) {
                        break;
                    }
                    if (!inRange(cx, j)) {
                        break;
                    }
                }
                cx -= 1;
                if (cx != i) {
                    temp[cx][j] = temp[i][j];
                    temp[i][j] = 0;
                }
            }
        }
    }
    for (int i = N - 1; i > 0; i--) {
        for (int j = 0; j < N; j++) {
            if (temp[i][j] == temp[i - 1][j]) {
                temp[i][j] *= 2;
                temp[i - 1][j] = 0;
            }
        }
    }
    for (int i = N - 2; i >= 0; i--) {
        for (int j = 0; j < N; j++) {
            if (temp[i][j]) {
                int cx = i;
                while (true) {
                    cx += 1;
                    if (temp[cx][j]) {
                        break;
                    }
                    if (!inRange(cx, j)) {
                        break;
                    }
                }
                cx -= 1;
                if (cx != i) {
                    temp[cx][j] = temp[i][j];
                    temp[i][j] = 0;
                }
            }
        }
    }
    return;
}

void move_right(){
    for (int i = 0; i < N; i++) {
        for (int j = N - 2; j >= 0; j--) {
            if (temp[i][j]) {
                int cy = j;
                while (true) {
                    cy += 1;
                    if (temp[i][cy]) {
                        break;
                    }
                    if (!inRange(i, cy)) {
                        break;
                    }
                }
                cy -= 1;
                if (cy != j) {
                    temp[i][cy] = temp[i][j];
                    temp[i][j] = 0;
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = N - 1; j > 0; j--) {
            if (temp[i][j] == temp[i][j - 1]) {
                temp[i][j] *= 2;
                temp[i][j - 1] = 0;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = N - 2; j >= 0; j--) {
            if (temp[i][j]) {
                int cy = j;
                while (true) {
                    cy += 1;
                    if (temp[i][cy]) {
                        break;
                    }
                    if (!inRange(i, cy)) {
                        break;
                    }
                }
                cy -= 1;
                if (cy != j) {
                    temp[i][cy] = temp[i][j];
                    temp[i][j] = 0;
                }
            }
        }
    }
    return;
}

void move_up(){
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (temp[i][j]) {
                int cx = i;
                while (true) {
                    cx -= 1;
                    if (temp[cx][j]) {
                        break;
                    }
                    if (!inRange(cx, j)) {
                        break;
                    }
                }
                cx += 1;
                if (cx != i) {
                    temp[cx][j] = temp[i][j];
                    temp[i][j] = 0;
                }
            }
        }
    }
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N; j++) {
            if (temp[i][j] == temp[i + 1][j]) {
                temp[i][j] *= 2;
                temp[i + 1][j] = 0;
            }
        }
    }
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (temp[i][j]) {
                int cx = i;
                while (true) {
                    cx -= 1;
                    if (temp[cx][j]) {
                        break;
                    }
                    if (!inRange(cx, j)) {
                        break;
                    }
                }
                cx += 1;
                if (cx != i) {
                    temp[cx][j] = temp[i][j];
                    temp[i][j] = 0;
                }
            }
        }
    }
    return;
}

void playGame(){
    for (int i = 0; i < 5; i++) {
        int cdir = canbe[i];
        if (cdir == 0) {
            move_left();
        }
        if (cdir == 1) {
            move_down();
        }
        if (cdir == 2) {
            move_right();
        }
        if (cdir == 3) {
            move_up();
        }
    }
}

int maxValue(){
    int tempMax = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            tempMax = max(tempMax, temp[i][j]);
        }
    }
    return tempMax;
}

void dfs(int cnt){
    if (cnt == 5) {
        copy_board();
        playGame();
        int tempMax = maxValue();
        result = max(result, tempMax);
        return;
    }
    for (int i = 0; i < 4; i++) {
        canbe[cnt] = i;
        dfs(cnt + 1);
        canbe[cnt] = 0;
    }
}

int main(void){
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    canbe.resize(5);
    dfs(0);
    
    cout << result;
    
    return 0;
}
