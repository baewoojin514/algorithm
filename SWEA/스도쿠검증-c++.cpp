#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#define MAX 9

using namespace std;

int board[MAX][MAX];

int visited[MAX];

bool threeByThreeCheck(){
    bool check = true;
    for (int i = 0; i < MAX; i += 3) {
        for (int j = 0; j < MAX; j += 3) {
            memset(visited, 0, sizeof(visited));
            int stx = i; int sty = j;
            for (int k1 = 0; k1 < 3; k1++) {
                for (int k2 = 0; k2 < 3; k2++) {
                    visited[board[stx + k1][sty + k2] - 1] += 1;
                }
            }
            int cnt = 0;
            for (int k = 0; k < MAX; k++) {
                if (visited[k] == 1) {
                    cnt += 1;
                }
            }
            if (cnt != MAX) {
                check = false;
            }
        }
    }
    if (!check) {
        return false;
    }
    return true;
}

bool checkByColumn(){
    bool check = true;
    for (int i = 0; i < MAX; i++) {
        memset(visited, 0, sizeof(visited));
        for (int j = 0; j < MAX; j++) {
            visited[board[i][j] - 1] += 1;
        }
        int cnt = 0;
        for (int k = 0; k < MAX; k++) {
            if (visited[k] == 1) {
                cnt += 1;
            }
        }
        if (cnt != MAX) {
            check = false;
        }
    }
    if (!check) {
        return false;
    }
    return true;
}

bool checkByRow(){
    bool check = true;
    for (int j = 0; j < MAX; j++) {
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < MAX; i++) {
            visited[board[i][j] - 1] += 1;
        }
        int cnt = 0;
        for (int k = 0; k < MAX; k++) {
            if (visited[k] == 1) {
                cnt += 1;
            }
        }
        if (cnt != MAX) {
            check = false;
        }
    }
    if (!check) {
        return false;
    }
    return true;
}

int main(void)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        memset(board, 0, sizeof(board));
        int tempResult;
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                cin >> board[i][j];
            }
        }
        
        bool check1 = threeByThreeCheck();
        bool check2 = checkByRow();
        bool check3 = checkByColumn();
        
        if (!check1 || !check2 || !check3) {
            tempResult = 0;
        }
        else{
            tempResult = 1;
        }
        
        cout << "#" << test_case << " " << tempResult << "\n";
    }
    return 0;
}
