#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#define MAX 15

using namespace std;

int board[MAX][MAX];

int dx[2] = {0, 1};
int dy[2] = {1, 0};

bool inRange(int X, int Y, int N){
    return X >= 0 && X < N && Y >= 0 && Y < N;
}

int main(void)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        memset(board, 0, sizeof(board));
        int tempResult = 0;
        int N, K;
        cin >> N >> K;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> board[i][j];
            }
        }
        //가로 순서로 확인한다.
        for (int i = 0; i < N; i++) {
            int count = 0;
            for (int j = 0; j < N; j++) {
                if (board[i][j]) {
                    count += 1;
                }
                else{
                    if (count == K) {
                        tempResult += 1;
                    }
                    count = 0;
                }
            }
            if (count == K) {
                //마지막까지 K인 경우를 확인해야 한다.
                tempResult += 1;
            }
        }
        //새로 순서로 확인한다.
        for (int j = 0; j < N; j++) {
            int count = 0;
            for (int i = 0; i < N; i++) {
                if (board[i][j]) {
                    count += 1;
                }
                else{
                    if (count == K) {
                        tempResult += 1;
                    }
                    count = 0;
                }
            }
            if (count == K) {
                //마지막까지 K인 경우를 확인해야 한다.
                tempResult += 1;
            }
        }
        cout << "#" << test_case << " " << tempResult << "\n";
    }
    return 0;
}
