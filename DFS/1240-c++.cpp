#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string.h>
#define MAX 1001

using namespace std;

int N, M;
int graph[MAX][MAX];
int visited[MAX];
vector<int> result;

void dfs(int src, int dest, int tempSum){
    if (src == dest) {
        result.push_back(tempSum);
        return;
    }
    
    for (int i = 1; i < N + 1; i++) {
        if (!visited[i] && graph[src][i]) {
            visited[i] = 1;
            tempSum += graph[src][i];
            dfs(i, dest, tempSum);
            visited[i] = 0;
            tempSum -= graph[src][i];
        }
    }
}

int main(void)
{
    cin >> N >> M;
    for (int i = 0; i < N - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = c;
        graph[b][a] = c;
    }
    for (int i = 0; i < M; i++) {
        int src, dest;
        cin >> src >> dest;
        memset(visited, 0, sizeof(visited));
        
        visited[src] = 1;
        dfs(src, dest, 0);
    }
    
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << "\n";
    }
    return 0;
}
