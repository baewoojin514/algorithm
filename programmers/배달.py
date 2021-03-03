#배달(programmers)
#다익스트라 알고리즘으로 해결할 수 있다.
#skill.1 - 1번 마을을 시작점으로 다익스트라 알고리즘을 실행한다.
#skill.2 - distance리스트중 K 이하인 요소를 count한다.

import heapq

INF = 1e9

def dijkstra(start, graph, N):
    q = []
    heapq.heappush(q, (0, start))
    distance = [INF] * (N + 1)
    distance[start] = 0

    while q:
        dist, cx = heapq.heappop(q)

        if distance[cx] < dist:
            continue
        for i in graph[cx]:
            cost = dist + i[1]
            if distance[i[0]] > cost:
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))
    return distance



def solution(N, road, K):
    answer = 0
    graph = [[] for _ in range(N + 1)]
    for edge in road:
        graph[edge[0]].append([edge[1], edge[2]])
        graph[edge[1]].append([edge[0], edge[2]])
    temp = dijkstra(1, graph, N)
    for i in range(1, N + 1):
        if temp[i] <= K:
            answer += 1

    return answer
