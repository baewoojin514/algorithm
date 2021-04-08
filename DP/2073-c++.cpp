//수도배관공사(2073)
//dp로 해결할 수 있다.

#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#define MAX 100001
#define INF 1e9

using namespace std;

int dp[MAX];
int D, P;

int main(void){
    cin >> D >> P;
    
    dp[0] = INF;
    
    for (int i = 0; i < P; i++) {
        int L, C;
        cin >> L >> C;
        
        for (int j = D; j >= L; j--) {
            dp[j] = max(dp[j], min(C, dp[j - L]));
            //dp[j]는 dp[j]에 기존에 저장된 값과 j에서 현재 파이프의 L을 뺀 즉 직적의 파이프의 용량과 현재 용량의 최소값의 최대값이 된다.
        }
    }
    cout << dp[D];
    
    return 0;
}
