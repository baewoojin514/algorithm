//목장 건설하기(14925)
//dp로 해결할 수 있다.
//skill.1 - [i][j - 1], [i - 1][j - 1], [i - 1][j] 의 최소값이 1을 더한다.
//skill.2 - dp 2차원 배열의 최대값을 출력한다.
//skill.3 - 1, 2가 아닌 경우 1로 바꾸고 1, 2인 경우 0으로 바꾼다.
//skill.4 - 가장 큰 정사각형 변의 길이를 구하고 출력한다.

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <stdio.h>
#include <cstring>

#define MAX 1000

using namespace std;

int board[MAX][MAX];
int dp[MAX][MAX];
int M, N;
int result;

int main(void){
    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j]) {
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = 1;
            }
        }
    }
    for (int i = 1; i < M; i++) {
        for (int j = 1; j < N; j++) {
            if (dp[i][j]) {
                dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
            }
        }
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            result = max(result, dp[i][j]);
        }
    }
    
    cout << result;
    
    return 0;
}
