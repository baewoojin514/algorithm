//최대 정사각형(4095)
//dp로 해결할 수 있다.
//skill.1 - [i][j - 1], [i - 1][j - 1], [i - 1][j] 의 최소값이 1을 더한다.
//skill.2 - dp 2차원 배열의 최대값을 출력한다.

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <stdio.h>
#include <cstring>

#define MAX 1000

using namespace std;

int board[MAX][MAX];

int main(void){
    while (true) {
        memset(board, 0, sizeof(board));
        int N, M;
        cin >> N >> M;
        if (N == 0 && M == 0) {
            break;
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> board[i][j];
            }
        }
        for (int i = 1; i < N; i++) {
            for (int j = 1; j < M; j++) {
                if (board[i][j]) {
                    board[i][j] = min(board[i][j - 1], min(board[i - 1][j], board[i - 1][j - 1])) + 1;
                }
            }
        }
        int tempMax = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                tempMax = max(tempMax, board[i][j]);
            }
        }
        cout << tempMax << "\n";
    }
    return 0;
}
