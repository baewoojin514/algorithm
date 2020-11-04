#최소비용 구하기(1916)
#dijkstra 알고리즘으로 해결가능하다.
#입력 정보중 시작점을 기준으로 dijkstra 함수를 실행하고 도착점을 출력한다.
#skill.1 - input sys.stdin.readline!!

import sys
import heapq
INF = sys.maxsize
input = sys.stdin.readline


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


N = int(input())
M = int(input())
graph = [[]for _ in range(N + 1)]
distance = [INF] * (N + 1)

for _ in range(M):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))

src, dest = map(int, input().split())
dijkstra(src)

print(distance[dest])

