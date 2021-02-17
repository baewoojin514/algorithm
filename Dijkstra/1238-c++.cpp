//파티(1238)
//다익스트라 알고리즘을 사용해서 해결할 수 있다.
//skill.1 - 출발지에서 목적지로 가는 최단경로를 구하는 함수와 목적지에서 출발지로 다시 오는 최단경로를 구하는 함수를 구현한다.
//skill.2 - X로 가는 최단경로와 X에서 출발지로 다시 돌아오는 최단경로를 배열에 저장하고 그 값을 더한다.
//skill.3 - 2의 결과 배열의 최대값을 구한다.

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <queue>
#define MAX 10001
#define INF 1e9

using namespace std;

int dis1[1001];
int dis2[1001];
int result[1001];
vector<pair<int, int>> graph[MAX];
priority_queue<pair<int, int>> pq;

int N, M, X;
int maxValue = 0;

void toX(int start){
    pq.push({0, start});
    dis1[start] = 0;
    while (!pq.empty()) {
        int dist, cx;
        dist = -pq.top().first;
        cx = pq.top().second;
        
        pq.pop();
        
        if (dis1[cx] < dist) {
            continue;
        }
        for (int i = 0; i < graph[cx].size(); i++) {
            int cost = dist + graph[cx][i].second;
            if (cost < dis1[graph[cx][i].first]) {
                dis1[graph[cx][i].first] = cost;
                pq.push(make_pair(-cost, graph[cx][i].first));
            }
        }
    }
}

void fromX(int start){
    pq.push({0, start});
    dis2[start] = 0;
    while (!pq.empty()) {
        int dist, cx;
        dist = -pq.top().first;
        cx = pq.top().second;
        
        pq.pop();
        
        if (dis2[cx] < dist) {
            continue;
        }
        for (int i = 0; i < graph[cx].size(); i++) {
            int cost = dist + graph[cx][i].second;
            if (cost < dis2[graph[cx][i].first]) {
                dis2[graph[cx][i].first] = cost;
                pq.push(make_pair(-cost, graph[cx][i].first));
            }
        }
    }
}

int main(void){
    scanf("%d %d %d", &N, &M, &X);
    for (int i = 0; i < M; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        graph[a].push_back({b, c});
    }
    for (int i = 1; i < N + 1; i++) {
        //각자의 집에서 X까지 갈 수 있기 때문에 모든 경우에 대해 다익스트라 알고리즘을 사용해야 한다.
        fill(dis1, dis1 + 1001, INF);
        toX(i);
        result[i] += dis1[X];
    }
    fill(dis2, dis2 + 1001, INF);
    fromX(X);
    //X에서 다른 집으로 이동하는 것은 다익스트라 함수 fromX를 한번 호출해서 해결할 수 있다.
    for (int i = 1; i < N + 1; i++) {
        result[i] += dis2[i];
    }
    for (int i = 1; i < N + 1; i++) {
        if (result[i] != INF) {
            maxValue = max(maxValue, result[i]);
        }
    }
    printf("%d", maxValue);
    
    return 0;
}
