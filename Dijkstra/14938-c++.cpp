//서강그라운드(14938)
//다익스트라 알고리즘을 사용해서 해결할 수 있다.
//skill.1 - 모든 지점을 시작점으로 다익스트라 실행한다.
//skill.2 - while문 내부에서 거리가 M 이하인지를 판단하고 M 이상이면 continue로 넘어간다.
//skill.3 - 모든 지점을 시작점으로 최단경로를 찾고 최단 경로가 M 이하이면 해당 노드들의 아이템 개수를 더해준다.
//skill.4 - 모든 시작점에 대해 획득 가능한 아이템 개수를 최대값으로 갱신한다.

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <queue>
#define MAX 101
#define INF 1e9

using namespace std;

vector<pair<int, int>> graph[MAX];
priority_queue<pair<int, int>> pq;
int dis[101];
int item[101];
int n, m, r;
int maxValue = 0;

void dijkstra(int start){
    pq.push({0, start});
    dis[start] = 0;
    while (!pq.empty()) {
        int dist, cx;
        dist = -pq.top().first;
        cx = pq.top().second;
        
        pq.pop();
        
        if (dis[cx] < dist) {
            continue;
        }
        for (int i = 0; i < graph[cx].size(); i++) {
            int cost = dist + graph[cx][i].second;
            if (cost > m) {
                //만약 cost가 수색범위 m을 초과하였다면 continue로 넘어간다.
                continue;
            }
            if (cost < dis[graph[cx][i].first]) {
                dis[graph[cx][i].first] = cost;
                pq.push(make_pair(-cost, graph[cx][i].first));
            }
        }
    }
    
}

int main(void){
    cin >> n >> m >> r;
    for (int i = 1; i < n + 1; i++) {
        cin >> item[i];
    }
    //각 지점에 위치한 item의 개수를 입력 받는다.
    for (int i = 0; i < r; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
        //그래프가 양방향임을 명심해야 한다!!
    }
    for (int i = 1; i < n + 1; i++) {
        fill(dis, dis + 101, INF);
        //dist배열을 초기화한다.
        dijkstra(i);
        int temp = 0;
        for (int j = 1; j < n + 1; j++) {
            if (dis[j] <= m) {
                temp += item[j];
            }
        }
        maxValue = max(maxValue, temp);
    }
    cout << maxValue;
    
    return 0;
}
