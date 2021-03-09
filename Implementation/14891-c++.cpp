//톱니바퀴(14891)
//시뮬레이션 문제이다.
//톱니바퀴가 4개 임으로 모든 경우의 수를 if문을 통해 구현할 수 있다.

#include <algorithm>
#include <cstring>
#include <stdio.h>
#include <iostream>
#include <deque>
#define MAX 4
 
using namespace std;

deque<int> dq[MAX];
//배열 deque에 톱니바퀴 4개의 정보를 저장한다.
//deque의 pop을 통해 톱니바퀴의 회전을 쉽게 구현할 수 있다.
int K;
int result = 0;

int reverseDir(int cdir){
    //인접한 톱니의 극에 따라 방향을 뒤집어 줘야할 필요가 있다.
    if (cdir == 1) {
        return -1;
    }
    return 1;
}

void rotateDq(int idx, int dir){
    if (dir == 1) {
        int temp;
        temp = dq[idx].back();
        dq[idx].pop_back();
        dq[idx].push_front(temp);
    }
    else if (dir == -1){
        int temp;
        temp = dq[idx].front();
        dq[idx].pop_front();
        dq[idx].push_back(temp);
    }
}

void check(int idx, int dir){
    int rDir = reverseDir(dir);
    //현재 방향의 반대 방향이다.
    if (idx == 0) {
        if (dq[idx][2] != dq[idx + 1][6]) {
            if (dq[idx + 1][2] != dq[idx + 2][6]) {
                if (dq[idx + 2][2] != dq[idx + 3][6]) {
                    rotateDq(idx, dir);
                    rotateDq(idx + 1, rDir);
                    rotateDq(idx + 2, dir);
                    rotateDq(idx + 3, rDir);
                }
                else{
                    rotateDq(idx, dir);
                    rotateDq(idx + 1, rDir);
                    rotateDq(idx + 2, dir);
                }
            }
            else{
                rotateDq(idx, dir);
                rotateDq(idx + 1, rDir);
            }
        }
        else{
            rotateDq(idx, dir);
        }
    }
    else if (idx == 1){
        if (dq[idx][6] != dq[idx - 1][2]) {
            rotateDq(idx - 1, rDir);
        }
        if (dq[idx][2] != dq[idx + 1][6]) {
            if (dq[idx + 1][2] != dq[idx + 2][6]) {
                rotateDq(idx, dir);
                rotateDq(idx + 1, rDir);
                rotateDq(idx + 2, dir);
            }
            else{
                rotateDq(idx, dir);
                rotateDq(idx + 1, rDir);
            }
        }
        else{
            rotateDq(idx, dir);
        }
    }
    else if (idx == 2){
        if (dq[idx][2] != dq[idx + 1][6]) {
            rotateDq(idx + 1, rDir);
        }
        if (dq[idx][6] != dq[idx - 1][2]) {
            if (dq[idx - 1][6] != dq[idx - 2][2]) {
                rotateDq(idx, dir);
                rotateDq(idx - 1, rDir);
                rotateDq(idx - 2, dir);
            }
            else{
                rotateDq(idx, dir);
                rotateDq(idx - 1, rDir);
            }
        }
        else{
            rotateDq(idx, dir);
        }
    }
    else if (idx == 3){
        if (dq[idx][6] != dq[idx - 1][2]) {
            if (dq[idx - 1][6] != dq[idx - 2][2]) {
                if (dq[idx - 2][6] != dq[idx - 3][2]) {
                    rotateDq(idx, dir);
                    rotateDq(idx - 1, rDir);
                    rotateDq(idx - 2, dir);
                    rotateDq(idx - 3, rDir);
                }
                else{
                    rotateDq(idx, dir);
                    rotateDq(idx - 1, rDir);
                    rotateDq(idx - 2, dir);
                }
            }
            else{
                rotateDq(idx, dir);
                rotateDq(idx - 1, rDir);
            }
        }
        else{
            rotateDq(idx, dir);
        }
    }
}

int main(void){
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            int a;
            scanf("%1d", &a);
            dq[i].push_back(a);
        }
    }
    cin >> K;
    for (int i = 0; i < K; i++) {
        int idx, dir;
        cin >> idx >> dir;
        check(idx - 1, dir);
    }
    if (dq[0][0] == 1) {
        result += 1;
    }
    if (dq[1][0] == 1) {
        result += 2;
    }
    if (dq[2][0] == 1) {
        result += 4;
    }
    if (dq[3][0] == 1) {
        result += 8;
    }
    //톱니바퀴의 12시 방향의 N, S 극 여부에 따라 점수를 더한다.
    cout << result;
    return 0;
}
