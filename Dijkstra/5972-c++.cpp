//택배 배송(5972)
//다익스트라 알고리즘으로 해결 가능하다.
//skill.1 - 소에게 최소한의 여물을 주면서 이동해야 한다.
//skill.2 - 우선순위 큐에 이동하면서 소비하는 여물을 저장해 다익스트라 알고리즘을 적용한다.
//skill.3 - dis 배열의 N 요소를 출력한다.

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <queue>
#define MAX 50001
#define INF 1e9
//대문자 알파벳의 개수는 26개이다.

using namespace std;

int dis[MAX];
vector<pair<int, int>> graph[MAX];
int N, M;
priority_queue<pair<int, int>> pq;

int main(void){
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
        //길은 양방향이다.
    }
    fill(dis, dis + MAX, INF);
    pq.push({0, 1});
    dis[1] = 0;
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
            if (cost < dis[graph[cx][i].first]) {
                dis[graph[cx][i].first] = cost;
                pq.push(make_pair(-cost, graph[cx][i].first));
            }
        }
    }
    printf("%d", dis[N]);
    return 0;
}
