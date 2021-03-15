//세 용액(2473)
//two pointer로 해결할 수 있다.
//skill.1 - 한 용액을 고정하고 idx + 1 ~ N - 1 까지를 두 포인터를 통해 탐색한다.
//skill.2 - 1의 과정을 반복하면서 최소값을 갱신한다.

#include <algorithm>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#define INF 3e9

using namespace std;

int N;
long long minimum = INF;

vector<long long> yongack;
int result1;
int result2;
int result3;

int main(void){
    cin >> N;
    for (int i = 0; i < N; i++) {
        long long input;
        cin >> input;
        yongack.push_back(input);
    }
    sort(yongack.begin(), yongack.end());
    for (int i = 0; i < N; i++) {
        int stx = i + 1;
        int edx = N - 1;
        while (stx < edx) {
            long long tempSum = yongack[i] + yongack[stx] + yongack[edx];
            if (minimum >= abs(tempSum)) {
                minimum = abs(tempSum);
                result1 = i;
                result2 = stx;
                result3 = edx;
            }
            if (tempSum <= 0) {
                //음수라면 양수에 가까워 지기 위해 stx를 += 1 하여야 한다.
                stx += 1;
            }
            else{
                //양수라면 합을 용액의 합을 줄이기 위해 edx를 -= 1 하여야 한다.
                edx -= 1;
            }
        }
    }
    cout << yongack[result1] << " " << yongack[result2] << " " << yongack[result3];
    
    return 0;
}
