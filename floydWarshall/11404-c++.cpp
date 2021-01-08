//플로이드(11404)
//python3와 같은 방식으로 구현한다.
//플로이드 와샬 알고리즘을 사용한 최단 경로 알고리즘 문제이다.
//동일 도시간 경로가 여러개일 수도 있기 때문에 최소값을 계속 갱신한다.
//graph 이차원 배열의 초기값을 무한대로 초기화 한다.
//마지막에 도시간 경로가 없을 경우 0을 출력하고 아닐 경우 최단 경로를 출력한다.

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <limits>
#define INF 987654321

using namespace std;

int n;
int m;

int graph[100][100];

int main(void){
    cin >> n;
    cin >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = INF;
        }
    }
   
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a - 1][b - 1] = min(graph[a - 1][b - 1], c);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (j != k) {
                    graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == INF) {
                cout << 0 << " ";
            }
            else{
                cout << graph[i][j] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}
