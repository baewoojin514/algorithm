//역사(1613)
//플로이드 워셜 알고리즘을 사용해서 해결할 수 있다.
//역사의 전후 관계를 최단 경로의 시작, 도착 지점으로 치환할 수 있다.
//skill.1 - 주어진 역사 전후관계에 대해서 플로이드 워셜 알고리즘을 적용한다.
//skill.2 - s개의 전후관계에 대해서 순서에 따라 1, -1을 출력하고, INF일 경우 0을 출력한다.
//시간초과가 발생했다. 전후관계 입력시 1, -1로 이차원 배열 요소를 처리해서 시간복잡도를 줄일 수 있다.

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define MAX 401
#define INF 1e9

using namespace std;

int n, k;
int s;
int graph[MAX][MAX];

int main(void){
    cin >> n >> k;
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            if (i == j) {
                graph[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a>> b;
        graph[a][b] = 1;
    }
    for (int k = 1; k < n + 1; k++) {
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                if (graph[i][k] == 1 && graph[k][j] == 1) {
                    graph[i][j] = 1;
                }
            }
        }
    }
    cin >> s;
    for (int i = 0; i < s; i++) {
        int a, b;
        cin >> a >> b;
        if (graph[a][b] == 1) {
            cout << -1 << "\n";
        }
        else if (graph[b][a] == 1){
            cout << 1 << "\n";
        }
        else{
            cout << 0 << "\n";
        }
    }
    return 0;
}
