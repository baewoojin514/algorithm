#해킹(10282)
#최초 감염된 컴퓨터로부터 연결된 컴퓨터들을 count 하고 cost들을 더한다.
#컴퓨터 x가 a,b,c에 동시에 의존한다고 가정하면 가장 적은 시간이 걸리는 컴퓨터에 의해 먼저 감염이 된다.
#skill.1 - 다익스트라 알고리즘을 사용하여 최단 시간을 구한다.
#skill.2 - distance 리스트를 visited처럼 사용하여 이미 최단시간으로 갱신된 컴퓨터는 continue로 넘어간다.
#skill.3 - distance 리스트에서 INF를 제외한 가장 큰 값이 최대한 많은 컴퓨터를 감염시킨 최단 시간이고 그 요소의 개수가 감염된 컴퓨터의 개수이다.

import sys
import heapq
INF = 1e9
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    n, d, c = map(int, input().split())
    graph = [[] for _ in range(n + 1)]
    for _ in range(d):
        a, b, s = map(int, input().split())
        graph[b].append([a, s])
    q = []
    distance = [INF] * (n + 1)
    distance[c] = 0
    heapq.heappush(q, (0, c))
    while q:
        tempTime, cx = heapq.heappop(q)

        if distance[cx] < tempTime:
            continue
        for i in graph[cx]:
            cost = tempTime + i[1]
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))

    count = 0
    maxValue = 0
    for i in range(1, n + 1):
        if distance[i] != INF:
            count += 1
            maxValue = max(maxValue, distance[i])
    print(str(count) + ' ' + str(maxValue))
