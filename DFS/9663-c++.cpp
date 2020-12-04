//N-Queen(9663)
//python3와 동일한 알고리즘으로 풀이한다.
//dfs재귀 함수로 cnt를 parameter로 넘겨서 호출한다.
//abs즉 절대값 함수를 사용하기 위해서 stdlib.h가 필요하다.
//똑같은 로직 이지만 python3로는 시간초과가 발생하였다.

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <stdlib.h>

using namespace std;

int N;
int num[16];

int result = 0;

void dfs(int cnt){
    if (cnt == N) {
        result += 1;
        return;
    }
    else{
        for (int k = 0; k < N; k++) {
            num[cnt] = k;
            bool flags = true;
            for (int j = 0; j < cnt; j++) {
                if (num[j] == num[cnt] || abs(num[j] - num[cnt]) == cnt - j) {
                    flags = false;
                }
            }
            if (flags) {
                dfs(cnt + 1);
            }
        }
    }
}

int main(void){
    cin >> N;
    dfs(0);
    //dfs재귀 함수를 호출한다.
    cout << result;
    return 0;
}
