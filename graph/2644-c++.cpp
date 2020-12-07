//촌수계산(2644)
//python3와 같은 방식으로 구현한다.
//그래프를 bfs로 구현한다.
//그래프 간선 정보를 vector에 저장한다.
//while문 초기에 dest index가 -1인지 확인하고 맞다면 -1을 출력한다.
//while문 초기에 dest가 맞는지 확인하고 맞다면 visited[dest]를 출력한다.

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int n;
int m;
int src;
int dest;

int visited[101];

queue<int> q;
vector<int> graph[101];
//vector를 배열 형태로 선언했다.

int main(void){
    cin >> n;
    cin >> src >> dest;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
        
    }
    src -= 1;
    dest -= 1;
    memset(visited, -1, sizeof(visited));
    //visited를 -1로 초기화 한다.
    visited[src] = 0;
    q.push(src);
    
    while (!q.empty()) {
        int cx = q.front();
        q.pop();
        if (cx == dest) {
            cout << visited[dest];
            break;
        }
        for (int i = 0; i < graph[cx].size(); i++) {
            int nx = graph[cx][i];
            if (visited[nx] == -1) {
                visited[nx] = visited[cx] + 1;
                q.push(nx);
            }
        }
    }
    if (visited[dest] == -1) {
        cout << -1;
    }
    return 0;
}

