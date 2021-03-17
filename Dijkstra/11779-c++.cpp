//최소비용 구하기2(11779)
//다익스트라 알고리즘으로 해결할 수 있다.
//skill.1 - 주어진 정보를 간선 vector에 저장한다.
//skill.2 - 다익스트라 알고리즘을 통해 특정 노드에 최단거리로 도달하기 위해 거쳐야 하는 노드를 저장한다.
//skill.3 - 도착지점 부터 시작 지점 까지 역순으로 저장하고 다시 역순으로 출력한다.

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>

#define MAX 1001
#define INF 1e9
//무한을 의미하는 값으로 10억을 설정한다.

using namespace std;

int n, m;
int dist[MAX];
int route[MAX];
vector<pair<int, int>> graph[MAX];
int src, dest;
vector<int> result;

void dijkstra(int start){
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    dist[start] = 0;
    
    while (!pq.empty()) {
        int dis, cx;
        dis = -pq.top().first;
        cx = pq.top().second;
        
        pq.pop();
        
        if (dist[cx] < dis) {
            continue;
        }
        for (int i = 0; i < graph[cx].size(); i++) {
            int cost = dis + graph[cx][i].second;
            if (dist[graph[cx][i].first] > cost) {
                dist[graph[cx][i].first] = cost;
                pq.push(make_pair(-cost, graph[cx][i].first));
                route[graph[cx][i].first] = cx;
            }
        }
    }
}

int main(void){
    cin >> n;
    cin >> m;
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));
    }
    cin >> src >> dest;
    
    dijkstra(src);
    cout << dist[dest] << endl;
    result.push_back(dest);
    int cx = dest;
    while (true) {
        int px = route[cx];
        if (px == src) {
            result.push_back(px);
            break;
        }
        result.push_back(px);
        cx = px;
    }
    cout << result.size() << endl;
    for (int i = result.size() - 1; i >= 0; i--) {
        cout << result[i] << " ";
    }
    return 0;
}
