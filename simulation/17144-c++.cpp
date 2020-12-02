//미세먼지 안녕!(17144)
//이중 for문을 돌며 먼지를 분산 시킨다.
//먼지의 분산값이 한번에 갱신되어야 error가 발생하지 않는다.
//공기청정기에 따라 먼지를 순환시킨다.
//먼지는 공기청정기를 만나면 없어진다.

#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <string.h>

using namespace std;

int board[51][51];
int temp[51][51];
//temp에 분산된 먼지들을 임시로 저장한다.

int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

int R;
int C;
int T;
int sum = 0;

queue<int> q;
//공기 청정기는 첫번째 열에 있기 때문에 좌표값은 하나만 저장하면 된다.
int a1 = 0;
int a2 = 0;

int main(void){
    cin >> R >> C >> T;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> board[i][j];
            if (board[i][j] == -1) {
                q.push(i);
                //q에 공기청정기 2개의 좌표를 저장한다.
            }
        }
    }
    a1 = q.front();
    q.pop();
    a2 = q.front();
    q.pop();
    for (int k = 0; k < T; k++) {
        memset(temp, 0, sizeof(temp));
        //시간 마다 분산되는 먼지를 저장할 것이기 때문에 초기화 해주어야 한다.
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (board[i][j] >= 5) {
                    //5로 나눈값 중 소수점을 버리고 분산 시키기 때문에 5 이상의 먼지가 있는 곳만 분산 시키면 된다.
                    int cnt = 0;
                    for (int h = 0; h < 4; h++) {
                        int A = i + dx[h];
                        int B = j + dy[h];
                        if (A >= 0 && A < R && B >= 0 && B < C) {
                            if (board[A][B] != -1) {
                                //공기 청정기 이거나 범위 밖인 곳에는 먼지를 분산 시킬 수 없다.
                                temp[A][B] += (int)(board[i][j]/5);
                                cnt += 1;
                            }
                        }
                    }
                    temp[i][j] -= cnt * (int)(board[i][j]/5);
                }
            }
        }
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                board[i][j] += temp[i][j];
            }
        }
        for (int i = a1 - 2; i >= 0; i--) {
            board[i + 1][0] = board[i][0];
        }
        for (int i = 0; i < C - 1; i++) {
            board[0][i] = board[0][i + 1];
        }
        for (int i = 0; i < a1; i++) {
            board[i][C - 1] = board[i + 1][C - 1];
        }
        for (int i = C - 2; i >= 0; i--) {
            board[a1][i + 1] = board[a1][i];
        }
        board[a1][1] = 0;
        //상단 공기 청정기 순환완료
        for (int i = a2 + 1; i < R - 1; i++) {
            board[i][0] = board[i + 1][0];
        }
        for (int i = 0; i < C - 1; i++) {
            board[R - 1][i] = board[R - 1][i + 1];
        }
        for (int i = R - 2; i > a2 - 1; i--) {
            board[i + 1][C - 1] = board[i][C - 1];
        }
        for (int i = C - 2; i >= 0; i--) {
            board[a2][i + 1] = board[a2][i];
        }
        board[a2][1] = 0;
        //하단 공기 청정기 순환완료
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (board[i][j] != -1) {
                sum += board[i][j];
            }
        }
    }
    cout << sum;
   
    return 0;
}
