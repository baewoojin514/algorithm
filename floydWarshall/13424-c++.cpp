//비밀 모임(13424)
//python3와 같은 방식으로 구현한다.
//플로이드 와샬 알고리즘을 사용한 최단 경로 알고리즘 문제이다.
//K개의 방에 대해서 K를 제외한 나머지 방까지 갈 수 있는 최단 거리의 총합이 가장 적은 경우의 방 번호를 출력한다.

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <limits>
int INF = 987654321;

using namespace std;

int T;
int N;
int M;
int K;
int friends[100];
int graph[100][100];
int result = -1;

int main(void){
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N >> M;
        
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                graph[j][k] = INF;
            }
        }
        for (int j = 0; j < M; j++) {
            int a, b, c;
            cin >> a >> b >> c;
            graph[a - 1][b - 1] = min(graph[a - 1][b - 1], c);
            graph[b - 1][a - 1] = min(graph[b - 1][a - 1], c);
        }
        cin >> K;
        
        for (int j = 0; j < K; j++) {
            cin >> friends[j];
        }
        for (int j1 = 0; j1 < N; j1++) {
            for (int j2 = 0; j2 < N; j2++) {
                for (int j3 = 0; j3 < N; j3++) {
                    if (j2 == j3) {
                        graph[j2][j3] = 0;
                    }
                    else{
                        graph[j2][j3] = min(graph[j2][j3], graph[j2][j1] + graph[j1][j3]);
                    }
                }
            }
        }
        for (int j = 0; j < N; j++) {
            int tempDistance = 0;
            for (int k = 0; k < K; k++) {
                tempDistance += graph[j][friends[k] - 1];
            }
            if (INF > tempDistance) {
                result = j;
                INF = tempDistance;
            }
        }
        cout << result + 1 << '\n';
        INF = 987654321;
    }
    return 0;
}
