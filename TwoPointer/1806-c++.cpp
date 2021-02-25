//부분합(1806)
//수들의 합2 와 유사한 문제이다.
//skill.1 - 2003문제와 비슷한 문제이지만 부분 합이 S 이상인 경우 stx - edx + 1로 최소값을 갱신한다.
//skill.2 - result가 초기화된 값인 INF인 경우 0을 출력하고 아니면 result를 그대로 출력한다.

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#define MAX 100001

using namespace std;

int N;
int S;
int num[MAX];
int result = 100001;

int main(void){
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }
    int stx = 0;
    int edx = 0;
    int sum = num[0];
    
    while (edx <= N) {
        if (sum < S) {
            //S보다 작은 경우 index를 먼저 증가 시키고 해당 요소를 더해야 한다.
            edx += 1;
            sum += num[edx];
        }
        else{
            //이외의 경우는 stx의 요소를 먼저 빼고 index를 증가 시켜야 한다.
            result = min(result, edx - stx + 1);
            sum -= num[stx];
            stx += 1;
        }
    }
    if (result == 100001) {
        cout << 0;
    }
    else{
        cout << result;
    }
    return 0;
}
