//파이프 옮기기1(17070)
//재귀 함수로 구현한다.
//x, y 좌표와 pipe의 종류를 함수 parameter로 사용한다.
//c++은 python3와 다르게 void type의 함수는 return하지 않아도 된다.
//변수가 전역변수로 선언되어 있으면 함수 내에서 사용 가능하다(global이 필요 없다).

#include <iostream>

using namespace std;

int N;
int board[16][16];
int totalCount = 0;

void pipeMover(int pipeNum, int cx, int cy){
    if (cx == N - 1 && cy == N - 1) {
        totalCount += 1;
    }
    else{
        if (pipeNum == 0) {
            if (cx >= 0 && cx < N && cy + 1 >= 0 && cy + 1 < N) {
                if (board[cx][cy + 1] == 0) {
                    pipeMover(0, cx, cy + 1);
                }
            }
            if (cx + 1 >= 0 && cx + 1 < N && cy + 1 >= 0 && cy + 1 < N) {
                if (board[cx + 1][cy + 1] == 0 && board[cx + 1][cy] == 0 && board[cx][cy + 1] == 0) {
                    pipeMover(2, cx + 1, cy + 1);
                }
            }
        }
        else if (pipeNum == 1) {
            if (cx + 1 >= 0 && cx + 1 < N && cy >= 0 && cy < N) {
                if (board[cx + 1][cy] == 0) {
                    pipeMover(1, cx + 1, cy);
                }
            }
            if (cx + 1 >= 0 && cx + 1 < N && cy + 1 >= 0 && cy + 1 < N) {
                if (board[cx + 1][cy + 1] == 0 && board[cx + 1][cy] == 0 && board[cx][cy + 1] == 0) {
                    pipeMover(2, cx + 1, cy + 1);
                }
            }
        }
        else if (pipeNum == 2){
            if (cx >= 0 && cx < N && cy + 1 >= 0 && cy + 1 < N) {
                if (board[cx][cy + 1] == 0) {
                    pipeMover(0, cx, cy + 1);
                }
            }
            if (cx + 1 >= 0 && cx + 1 < N && cy >= 0 && cy < N) {
                if (board[cx + 1][cy] == 0) {
                    pipeMover(1, cx + 1, cy);
                }
            }
            if (cx + 1 >= 0 && cx + 1 < N && cy + 1 >= 0 && cy + 1 < N) {
                if (board[cx + 1][cy + 1] == 0 && board[cx + 1][cy] == 0 && board[cx][cy + 1] == 0) {
                    pipeMover(2, cx + 1, cy + 1);
                }
            }
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
    pipeMover(0, 0, 1);
    
    cout << totalCount;
    
    return 0;
}
