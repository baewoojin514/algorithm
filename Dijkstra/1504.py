#특정한 최단 경로(1504)
#기본적으로 dijkstra 알고리즘을 사용한다.
#하지만 1번 노드에서 N번 노드까지 갈 때 반드시 거쳐야 하는 노드 v1, v2가 있다.
#skill.1 - 1 -> v1 -> v2 -> N
#skill.2 - 1 -> v2 -> v1 -> N
#위와 같은 두개의 경우의 수가 있다.
#dijkstra 함수만 잘 정의하면 쉽게 해결 가능하다.
#python3에서 시간 초과가 발생하였으나 input sys.stdin.readline으로 재정의 해서 해결했다.

import sys
import heapq
INF = sys.maxsize
input = sys.stdin.readline

def dijkstra(start):
    q = []
    heapq.heappush(q, (0, start))
    distance = [INF] * (N + 1)
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
    return distance


N, E = map(int, input().split())

graph = [[]for _ in range(N + 1)]
for _ in range(E):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))
    graph[b].append((a, c))
    #양방향 그래프

v1, v2 = map(int, input().split())

res1 = dijkstra(1)
res2 = dijkstra(v1)
res3 = dijkstra(v2)
#경우의 수를 따져야 하기 때문에 dijkstra 함수 내부에 distance 리스트가 초기화 되고 또 반환되어야 한다.

#case.1 - 1 -> v1 -> v2 -> N
#case.2 - 1 -> v2 -> v1 -> N

result1 = res1[v1] + res2[v2] + res3[N]
result2 = res1[v2] + res2[v2] + res2[N]

if result1 >= INF and result2 >= INF:
    print(-1)
else:
    print(min(result1, result2))

