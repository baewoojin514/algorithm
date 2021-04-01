//호석이 두 마리 치킨(21278)
//플로이드 워셜로 해결할 수 있다.
//skill.1 - 입력받은 간선 정보를 플로이드 워셜 알고리즘을 통해 최단거리로 갱신한다.
//skill.2 - N개의 건물중 2개를 고르고 각 건물에서 해당 치킨 집과의 왕복 거리를 최대값으로 갱신한다.

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <stdio.h>
#include <cstring>
#include <vector>
#define MAX 100
#define INF 1e9

using namespace std;

int board[MAX][MAX];
int N, M;
int result = INF;
int chicken1 = INF;
int chicken2 = INF;
vector<int> canbe;
int visited[MAX];
vector<pair<pair<int, int>, int>> canbeResult;

void dfs(int cnt, int idx){
    if (cnt == 2) {
        int tempResult = 0;
        int temp1 = canbe[0];
        int temp2 = canbe[1];
        for (int i = 0; i < N; i++) {
            tempResult += min(board[i][temp1], board[i][temp2]) * 2;
        }
        canbeResult.push_back({{tempResult, temp1}, temp2});
        return;
    }
    for (int i = idx; i < N; i++) {
        if (visited[i] == 0) {
            canbe[cnt] = i;
            visited[i] = 1;
            dfs(cnt + 1, i);
            canbe[cnt] = 0;
            visited[i] = 0;
        }
    }
}

int main(void){
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            board[i][j] = INF;
        }
    }
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        
        board[a - 1][b - 1] = 1;
        board[b - 1][a - 1] = 1;
    }
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) {
                    board[i][j] = 0;
                }
                board[i][j] = min(board[i][j], board[i][k] + board[k][j]);
            }
        }
    }
    canbe.resize(2);
    dfs(0, 0);

    sort(canbeResult.begin(), canbeResult.end());
    
    cout << canbeResult[0].first.second + 1<< " " << canbeResult[0].second + 1<< " " << canbeResult[0].first.first;
    
    return 0;
}
