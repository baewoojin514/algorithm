#택배 배송(5972)
#다익스트라 알고리즘으로 해결 가능하다.
#skill.1 - 소에게 최소한의 여물을 주면서 이동해야 한다.
#skill.2 - 우선순위 큐에 이동하면서 소비하는 여물을 저장해 다익스트라 알고리즘을 적용한다.
#skill.3 - dis 리스의 N 요소를 출력한다.

import heapq
import sys

input = sys.stdin.readline
INF = 1e9

N, M = map(int, input().split())
dis = [INF] * (N + 1)
graph = [[] for _ in range(N + 1)]

for _ in range(M):
    a, b, c = map(int, input().split())
    graph[a].append([b, c])
    graph[b].append([a, c])

q = []
heapq.heappush(q, (0, 1))
dis[1] = 0

while q:
    dist, cx = heapq.heappop(q)

    if dis[cx] < dist:
        continue
    for i in graph[cx]:
        cost = dist + i[1]
        if cost < dis[i[0]]:
            dis[i[0]] = cost
            heapq.heappush(q, (cost, i[0]))

print(dis[N])
