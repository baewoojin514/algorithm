# 다익스트라(Dijkstra)

|algorithm|
|---|
|dijkstra|

## 다익스트라 최단 경로 알고리즘

- 특정한 노드에서 출발하여 다른 노드로 가는 각각의 최단 경로를 구해주는 알고리즘이다.
- 알고리즘 동작 순서
~~~
 1.출발 노드를 설정한다.
 2.최단 거리 테이블을 초기화한다.
 3.방문하지 않은 노드 중에서 최단 거리가 가장 짧은 노드를 선택한다(현재 최단 거리가 가장 짧은 노드를 확인한다는 점에서 greedy algorithm으로 볼 수 있다).
 4.해당 노드를 거쳐 다른 노드로 가는 비용을 계산하여 최단 거리를 테이블을 갱신한다.
 5.위 과정에서 3 과 4 번을 반복한다.
~~~

## 최적화된 다익스트라 알고리즘

### 시간 복잡도
- 다익스트라 알고리즘 구현시 사용하는 자료구조에 따라 시간 복잡도가 다르다. 
- 힙(heap) 자료구조를 사용하게 되면 시간 복잡도를 O(V^2) 에서 O(ElogV) 까지 줄일 수 있다(V는 정점의 수 E는 간선의 수이다).

### 힙(heap)
- 힙 자료구조는 우선순위 큐(priority queue)를 구현하기 위해 사용하는 자료구조이다.
- 우선순위 큐는 우선순위가 가장 높은 데이터를 가장 먼저 삭제하는 자료구조이다.

|자료구조|추출되는 데이터|
|---|---|
|스택(stack)|가장 나중에 삽입된 데이터|
|큐(queue)|가장 먼저 삽입된 데이터|
|우선순위 큐(priority queue)|가장 우선순위가 높은 데이터|

|우선순위 큐 구현 방식|삽입 시간|삭제 시간|
|---|---|---|
|리스트|O(1)|O(N)|
|힙(heap|O(logN)|O(logN)|

- python을 사용해서 우선순위 큐를 구현한다고 가정한다.
~~~
 1.리스트를 사용하면 N개의 데이터를 모두 넣고 다시 꺼내는 과정에서 O(N^2)의 시간 복잡도가 발생한다.
 2.힙을 사용하면 N개의 데이터를 모두 널고 다시 꺼내는 과정에서 O(NlogN)의 시간 복잡도가 발생한다.
~~~

## python code

'''
import heapq

INF = int(1e9)

n, m = map(int, input().split())

start = int(input())

graph = [[]for _ in range(n + 1)]
distance = [INF] * (n + 1)

for _ in range(m):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))


def dijkstra(start):
    q = []
    heapq.heappush(q, (0, start))
    distance[start] = 0
    while q:
        dist, now = heapq.heappop(q)

        if distance[now] < dist:
            continue
        for i in graph[now]:
            cost = dist + i[1]
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))


dijkstra(start)

for i in range(1, n + 1):
    if distance[i] == INF:
        print("can't go")
    else:
        print(distance[i])
'''

## c++ code
'''
//다익스트라 알고리즘
//시작점이 설정된 경우 사용하기 좋은 알고리즘이다.
//우선순위 큐를 사용해서 구현하면 시간 복잡도 면에서 매우 효율적이다.
//노드의 개수는 최대 100,000개라고 가정한다.

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>

#define MAX 100001
#define INF 1e9
//무한을 의미하는 값으로 10억을 설정한다.

using namespace std;

vector<pair<int, int>> graph[MAX];
int N, M;
int start;
priority_queue<pair<int, int>> pq;

int dis[MAX];

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
        //현재 노드가 이미 최단경로로 갱신되어 있다면 넘어간다.
        for (int i = 0; i < graph[cx].size(); i++) {
            int cost = dist + graph[cx][i].second;
            if (cost < dis[graph[cx][i].first]) {
                //현재 노드를 거쳐 다른 노드로 이동하는 거리가 더 짧은 경우 최단 경로로 갱신하고 우선순위 큐에 삽입한다.
                dis[graph[cx][i].first] = cost;
                pq.push(make_pair(-cost, graph[cx][i].first));
            }
        }
    }
}

int main(void){
    
    cin >> N >> M;
    cin >> start;
    
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    fill(dis, dis + 100001, INF);
    //distance 배열을 무한으로 초기화한다.
    dijkstra(start);

    for (int i = 1; i <= N; i++) {
        if (dis[i] ==  INF) {
            cout << "INFINITY" << '\n';
        }
        else{
            cout << dis[i] << '\n';
        }
    }
    
    return 0;
}
'''

