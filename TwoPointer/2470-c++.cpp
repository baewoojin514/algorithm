//두 용액(2470)

#include <algorithm>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#define INF 2e9

using namespace std;

int N;
long long minimum = INF;

vector<long long> yongack;
int result1;
int result2;

int main(void){
    cin >> N;
    for (int i = 0; i < N; i++) {
        long long input;
        cin >> input;
        yongack.push_back(input);
    }
    sort(yongack.begin(), yongack.end());
    int stx = 0;
    int edx = N - 1;
    while (stx < edx) {
        long long tempSum = yongack[stx] + yongack[edx];
        if (minimum >= abs(tempSum)) {
            minimum = abs(tempSum);
            result1 = stx;
            result2 = edx;
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
    cout << yongack[result1] << " " << yongack[result2];
    
    return 0;
}
