//가장 긴 증가하는 부분 수열(11053)
//최장 증가 수열은 LIS 알고리즘을 사용하여 구할 수 있다.
//LIS 알고리즘은 DP로 구현이 가능하다.

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#define MAX 1000

using namespace std;

int N;
int num[MAX];
int DP[MAX];

int main(void){
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }
    for (int i = 0; i < N; i++) {
        DP[i] = 1;
        for (int j = 0; j < i; j++) {
            if (num[j] < num[i]) {
                DP[i] = max(DP[i], DP[j] + 1);
            }
        }
    }
    int maxValue = 0;
    for (int i = 0; i < N; i++) {
        maxValue = max(maxValue, DP[i]);
    }
    cout << maxValue;
    
    return 0;
}
