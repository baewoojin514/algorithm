//키 순서(2458)
//플로이드 워셜 알고리즘을 사용해서 해결할 수 있다.
//skill.1 - 키가 큰 학생을 1 작은 학생을 -1로 가정하고 플로이드 워셜 알고리즘을 적용한다.
//skill.2 - 각 행에 대해 0이 아닌 경우의 수를 모두 더하여 N - 1인 경우 신장의 대소 관계가 확실하여 순서를 매길 수 있는 경우이다.

#include <iostream>
#include <algorithm>
#include <stdio.h>
#define MAX 501

using namespace std;
int N, M;
int graph[MAX][MAX];
int result = 0;

int main(void){
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a][b] = 1;
        graph[b][a] = -1;
    }
    for (int k = 1; k < N + 1; k++) {
        for (int i = 1; i < N + 1; i++) {
            for (int j = 1; j < N + 1; j++) {
                if (graph[i][k] == 1 && graph[k][j] == 1) {
                    graph[i][j] = 1;
                }
                //j가 i보다 장신인 경우 1로 표기한다.
                else if (graph[i][k] == -1 && graph[k][j] == -1){
                    graph[i][j] = -1;
                }
                //i가 j보다 장신인 경우 -1로 표기한다.
            }
        }
    }
    for (int i = 1; i < N + 1; i++) {
        int temp = 0;
        for (int j = 1; j < N + 1; j++) {
            if (graph[i][j] != 0) {
                temp += 1;
            }
        }
        if (temp == N - 1) {
            result += 1;
        }
    }
    printf("%d", result);
   
    return 0;
}
