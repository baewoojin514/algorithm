# 플로이드 워셜(Floyd-Warshall)

|problem|solved(python/c++)|
|---|---|
|[2610](https://www.acmicpc.net/problem/2610)|v/v|

- 다익스트라 알고리즘은 '한 지점에서 다른 특정 지점까지의 최단 경로'를 구하는 알고리즘이다.
- 플로이드 워셜 알고리즘은 '모든 지점에서 다른 모든 지점까지의 최단 경로'를 구하는 알고리즘이다.

## floyd-warshall algorithm

~~~
1. 단계마다 거쳐가는 노드를 기준으로 알고리즘을 수행한다. 하지만 매번 방문하지 않은 노드 중에서 최단 경로를 갖는 노드를 찾을 필요가 없다.
2. O(N^2)의 연산을 통해 현재 노드를 거쳐가는 모든 경로를 고려한다. 따라서 총 시간 복잡도는 O(N^3)이다.
3. 다익스트라 알고리즘과는 다르게 2차원 배열이나 리스트에 최단 거리 정보를 저장하기 때문에 N번의 단계에 거쳐 매번 O(N^2)의 시간이 소요된다.
~~~

## c++ code

```c
//플로이드 워셜 알고리즘
//모든 지점에서 다른 모든 지점으로 가는 최단 경로를 계산하는 경우 유용하다.

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define MAX 501
#define INF 1e9
//무한을 의미하는 값으로 10억을 설정한다.

using namespace std;

int N, M;
int graph[MAX][MAX];

int main(void){
    cin >> N;
    cin >> M;
    
    for (int i = 0; i < 501; i++) {
        fill(graph[i], graph[i] + 501, INF);
    }
    //최단 경로 2차원 배열을 INF로 초기화한다.
    
    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < N + 1; j++) {
            if (i == j) {
                graph[i][j] = 0;
            }
        }
    }
    //자기 자신에서 자기 자신으로 가는 경로를 0으로 초기화한다.

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = c;
    }
    for (int k = 1; k < N + 1; k++) {
        for (int i = 1; i < N + 1; i++) {
            for (int j = 1; j < N + 1; j++) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
    //최단 경로 2차원 배열을 최소값으로 갱신한다.
    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < N + 1; j++) {
            if (graph[i][j] == INF) {
                cout << "INFINITY" << " ";
            }
            else{
                cout << graph[i][j] << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
```
