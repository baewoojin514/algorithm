//가장 먼 노드(programmers)
//시작 노드가 1로 고정되어 있다.
//시작 노드에서 갈 수 있는 모든 노드를 bfs로 탐색하고 그 거리를 갱신한다.
//distance 배열의 최대값 요소의 개수를 count 하고 반환한다.

#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

# define MAX 20001

using namespace std;

int dis[MAX];
vector<int> graph[MAX];

int solution(int n, vector<vector<int>> edge) {
    for (int i = 0; i < edge.size(); i++) {
        int a, b;
        a = edge[i][0];
        b = edge[i][1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    memset(dis, -1, sizeof(dis));
    queue<int> q;
    q.push(1);
    dis[1] = 0;
    
    while (!q.empty()) {
        int cx;
        cx = q.front();
        q.pop();
        
        for (int i = 0; i < graph[cx].size(); i++) {
            if (dis[graph[cx][i]] == -1) {
                dis[graph[cx][i]] = dis[cx] + 1;
                q.push(graph[cx][i]);
            }
        }
    }
    int maxValue = 0;
    for (int i = 1; i < n + 1; i++) {
        maxValue = max(maxValue, dis[i]);
    }
    
    int answer = 0;
    for (int i = 1; i < n + 1; i++) {
        if (dis[i] == maxValue) {
            answer += 1;
        }
    }
    return answer;
}
