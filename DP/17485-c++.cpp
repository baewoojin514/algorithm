//진우의 달 여행(Large)(17485)
//dp로 해결할 수 있다.
//같은 방향으로 움직일 수 없다는 조건을 반영하지 않아서 틀린 풀이이다.

#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#define MAX 1000
#define INF 1e9

using namespace std;

int N, M;
int space[MAX][MAX];
int result;

int main(void){
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> space[i][j];
        }
    }
    
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (j == 0 || j == M - 1) {
                space[i][j] = space[i][j] + min(space[i - 1][j], space[i - 1][j + 1]);
            }
            else{
                space[i][j] = space[i][j] + min(min(space[i - 1][j], space[i - 1][j + 1]), space[i - 1][j - 1]);
            }
        }
    }
    result = INF;
    
    for (int i = 0; i < M; i++) {
        result = min(result, space[N - 1][i]);
    }
    cout << result;
    
    return 0;
}
