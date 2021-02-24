#민준이와 마산 그리고 건우(18223)
#다익스트라 알고리즘으로 해결 가능하다.
#민준이가 마산으로 가는 최단경로(a), 민준 -> 건우 + 건우 -> 마산 최단경로(b)를 비교한다.
#skill.1 - b < a라면 save him을 출력한다.
#skill.2 - a > b라면 good bye를 출력한다.

import heapq
import sys

INF = 1e9
input = sys.stdin.readline


def dijkstra(start, dist):
    q = []
    heapq.heappush(q, (0, start))
    dist[start] = 0

    while q:
        dis, cx = heapq.heappop(q)

        if dist[cx] < dis:
            continue
        for i in graph[cx]:
            cost = dis + i[1]
            if dist[i[0]] > cost:
                dist[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))
    return dist


V, E, P = map(int, input().split())
graph = [[]for _ in range(V + 1)]

for _ in range(E):
    a, b, c = map(int, input().split())
    graph[a].append([b, c])
    graph[b].append([a, c])

dist1 = [INF] * (V + 1)
temp1 = dijkstra(1, dist1)
route1 = temp1[V]
route2 = temp1[P]

dist2 = [INF] * (V + 1)
temp2 = dijkstra(P, dist2)
route3 = dist2[V]

if route1 >= route2 + route3:
    #바로 마산으로 가는 최단 경로가 건우를 만나고 마산으로 가는 최단경로 이상이라면 건우에게 도움을 줄 수 있다.
    print("SAVE HIM")
else:
    print("GOOD BYE")
