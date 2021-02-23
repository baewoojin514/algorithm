//민준이와 마산 그리고 건우(18223)
//다익스트라 알고리즘으로 해결 가능하다.
//민준이가 마산으로 가는 최단경로(a), 민준 -> 건우 + 건우 -> 마산 최단경로(b)를 비교한다.
//skill.1 - b < a라면 save him을 출력한다.
//skill.2 - a > b라면 good bye를 출력한다.

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>

#define MAX 5001
#define INF 1e9
//무한을 의미하는 값으로 10억을 설정한다.

using namespace std;

int V, E, P;
int dist[MAX];
vector<pair<int, int>> graph[MAX];

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
            }
        }
    }
}

int main(void){
    cin >> V >> E >> P;
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
        //경로는 양방향이다.
    }
    fill(dist, dist + MAX, INF);
    dijkstra(1);
    int route1 = dist[V];
    //마산으로 바로 가는 경우의 최단 경로이다.
    int route2 = dist[P];
    //건우한테 가는 경로의 부분 최단 경로이다.
    fill(dist, dist + MAX, INF);
    dijkstra(P);
    int temp = dist[V];
    if (route1 >= route2 + temp) {
        //두 경로가 같은 경우도 건우를 경유할 수 있는 case이다.
        cout << "SAVE HIM" << "\n";
    }
    else{
        cout << "GOOD BYE" << "\n";
    }
    
    return 0;
}
