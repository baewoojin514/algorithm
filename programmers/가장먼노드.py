#가장 먼 노드(programmers)
#시작 노드가 1로 고정되어 있다.
#시작 노드에서 갈 수 있는 모든 노드를 bfs로 탐색하고 그 거리를 갱신한다.
#distance 리스트의 최대값 요소의 개수를 count 하고 반환한다.

from collections import deque


def solution(n, edge):
    graph = [[] for _ in range(n + 1)]
    for info in edge:
        graph[info[0]].append(info[1])
        graph[info[1]].append(info[0])
    q = deque()
    q.append(1)
    distance = [-1] * (n + 1)
    distance[1] = 0

    while q:
        cx = q.popleft()

        for i in graph[cx]:
            if distance[i] == -1:
                distance[i] = distance[cx] + 1
                q.append(i)

    return distance.count(max(distance))
