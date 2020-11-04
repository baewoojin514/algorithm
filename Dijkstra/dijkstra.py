#다익스트라 알고리즘
#시작점이 설정된 경우 사용하기 좋은 알고리즘이다.
#heapq를 사용해서 구현하면 시간 복잡도 면에서 매우 효율적이다.

import heapq

INF = int(1e9) #무한을 의미하는 값으로 10억을 설정한다.

n, m = map(int, input().split())

start = int(input())

graph = [[]for _ in range(n + 1)]
distance = [INF] * (n + 1)

for _ in range(m):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))
    #a 노드에서 b 노드로 가는 비용이 c이다.


def dijkstra(start):
    q = []
    heapq.heappush(q, (0, start))
    distance[start] = 0
    while q:
        dist, now = heapq.heappop(q)

        if distance[now] < dist:
            continue
        #현재 노드와 연결된 인접 노드들을 확인한다.
        for i in graph[now]:
            cost = dist + i[1]
            #현재 노드를 거쳐서 다른 노드로 가는 거리가 더 짧은 경우
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))


dijkstra(start)

for i in range(1, n + 1):
    if distance[i] == INF:
        print("can't go")
    else:
        print(distance[i])

