//1학년(5557)
//dp로 해결할 수 있다.
//skill.1 - dp[i][j]은 i번의 연산을 통해 0 ~ 20 사이의 정수 j를 만들 수 있는 경우의 수이다.
//skill.2 - j - arr[i] >= 0 이거나 j + arr[i] <= 20 dp[i][j - arr[i]],  dp[i][j + arr[i]] += dp[i - 1][j]을 한다.
//skill.3 - dp[N - 1][arr[N - 1]] 을 출력한다.

#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#define MAX 101

using namespace std;

long long dp[MAX][21];
int num[MAX];

int N;

int main(void){
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }
    dp[0][num[0]] = 1;
    
    for (int i = 1; i < N - 1 ; i++) {
        for (int j = 0; j <= 20; j++) {
            if (dp[i - 1][j]) {
                if (j - num[i] >= 0) {
                    dp[i][j - num[i]] += dp[i - 1][j];
                }
                if (j + num[i] <= 20) {
                    dp[i][j + num[i]] += dp[i - 1][j];
                }
            }
        }
    }
    cout << dp[N - 2][num[N - 1]] << "\n";
    
    return 0;
}
