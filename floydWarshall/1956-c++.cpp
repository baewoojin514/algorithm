//운동(1956)
//플로이드 와샬 알고리즘으로 해결할 수 있다.
//skill.1 - 플로이드 와샬 알고리즘을 통해 이차원 distance 배열을 갱신한다.
//skill.2 - i,j == j,i 인 경로의 합의 최소값을 구하면 된다.

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#define MAX 400
#define INF 1e9

using namespace std;

int dist[MAX][MAX];
int result;

int V, E;

int main(void){
    cin >> V >> E;
    result = INF;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            dist[i][j] = INF;
        }
    }
    while (E--) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a - 1][b - 1] = c;
    }
    
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            for (int k = 0; k < V; k++) {
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i == j) {
                continue;
            }
            if (dist[i][j] != INF && dist[j][i] != INF) {
                result = min(result, dist[i][j] + dist[j][i]);
            }
        }
    }
    if (result == INF) {
        cout << -1;
    }
    else{
        cout << result;
    }
    return 0;
}
