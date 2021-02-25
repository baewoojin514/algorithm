//수들의 합2(2003)
//투 포인터 알고리즘을 사용해서 해결할 수 있다.
//skill.1 - start, end 포인터 두개를 0으로 초기화 한다.
//skill.2 - 수들의 합이 M인 경우 count += 1을 한다.

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#define MAX 10001

using namespace std;

int N, M;
int num[MAX];
int result = 0;

int main(void){
    cin >> N >> M;
    
    for (int i = 0 ; i < N; i++) {
        cin >> num[i];
    }
    int stx = 0;
    int edx = 0;
    int sum = num[0];
    
    while (edx <= N) {
        if (sum == M) {
            //sum 이 M 과 같다면 result += 1을 한다.
            result += 1;
            edx += 1;
            sum += num[edx];
            sum -= num[stx];
            stx += 1;
        }
        else if (sum > M) {
            //sum이 M 이상이면 범위를 좁혀야 할 필요가 있다 따라서 start를 증가시킨다.
            sum -= num[stx];
            stx += 1;
        }
        else if (sum < M){
            //sum이 M 미만이면 범위를 넓혀야 할 필요가 있다. 따라서 end를 증가시킨다.
            edx += 1;
            sum += num[edx];
        }
    }
    cout << result;
    return 0;
}
