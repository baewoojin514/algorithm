#서강그라운드(14938)
#다익스트라 알고리즘을 사용해서 해결할 수 있다.
#skill.1 - 모든 지점을 시작점으로 다익스트라 실행한다.
#skill.2 - 모든 지점을 시작점으로 최단경로를 찾고 최단 경로가 M 이하이면 해당 노드들의 아이템 개수를 더해준다.
#skill.3 - 모든 시작점에 대해 획득 가능한 아이템 개수를 최대값으로 갱신한다.

import heapq


def dijkstra(start):
    q = []
    heapq.heappush(q, (0, start))
    dis[start] = 0
    while q:
        dist, cx = heapq.heappop(q)

        if dis[cx] < dist:
            continue
        for i in graph[cx]:
            cost = dist + i[1]

            if cost < dis[i[0]]:
                dis[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))


INF = 1e9

n, m, r = map(int, input().split())
item = [int(x) for x in input().split()]

graph = [[] for _ in range(n + 1)]

for _ in range(r):
    a, b, l = map(int, input().split())
    graph[a].append([b, l])
    graph[b].append([a, l])

maxValue = 0

for i in range(1, n + 1):
    dis = [INF] * (n + 1)
    dijkstra(i)
    temp = 0
    for j in range(1, n + 1):
        if dis[j] <= m:
            #거리가 m이하인 지점의 아이템을 모두 더한다.
            temp += item[j - 1]
    maxValue = max(maxValue, temp)

print(maxValue)
