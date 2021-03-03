#합승 택시 요금
#다익스트라 알고리즘을 사용해서 해결할 수 있다.
#skill.1 - 시작 점에서 각자 따로 목적지로 가는 최단경로를 구하여 더한다.
#skill.2 - 합승하여 가는 목적지를 for 문을 통해 탐색하고 다익스트라 알고리즘을 실행한다.
#skill.3 - 2의 거리는 시작점 -> 합승 + 합승 -> 무지 + 합승 -> 어피치 이다.
#skill.4 - 시작점은 합승지가 될 수 없다.

import heapq

INF = 1e9


def dijkstra(start, graph):
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


N, S, A, B = 0, 0, 0, 0

def solution(n, s, a, b, fares):
    answer = 0
    global N, S, A, B
    N = n
    S = s
    A = a
    B = b
    #s는 시작점 a와 b는 각각 도착지이다.
    graph = [[]for _ in range(n + 1)]
    for edge in fares:
        graph[edge[0]].append([edge[1], edge[2]])
        graph[edge[1]].append([edge[0], edge[2]])
    temp1 = dijkstra(S, graph)
    result1 = temp1[A] + temp1[B]
    #각자 따로 목적지로 가는 경우이다.

    result2 = []

    for i in range(1, N + 1):
        if i != S:
            temp2 = dijkstra(S, graph)
            #합승지점은 i 까지이다.
            temp3 = dijkstra(i, graph)
            tmp = temp2[i] + temp3[A] + temp3[B]
            result2.append(tmp)
    if result1 < min(result2):
        answer = result1
    elif result1 > min(result2):
        answer = min(result2)
    elif result1 == min(result2):
        answer = result1

    return answer
