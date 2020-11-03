#트리의 지름(1967)
#그래프 문제이다.
#케빈 베이컨의 6단계 법칙 처럼 연결된 노드들을 탐색을 하되 노드간 간선을 더한다.
#모든 노드를 시작점으로 삼고 위의 과정을 반복하며 최대값을 갱신 한다.
#더이상 이동할 수 없는 노드가 없을 경우 최대값을 갱신 하면 된다.
#그래프 문제지만 bfs 방식으로 구현한다.
#deque에는 노드 번호와 더해진 간선들의 cost 합을 넣는다.
#완전 탐색으로 구현하였으나 메모리 초과가 발생했다.

import collections

n = int(input())

graph = [[int(0)for _ in range(n)]for _ in range(n)]
for _ in range(n - 1):
    a, b, c = map(int, input().split())
    graph[a - 1][b - 1] = c
    graph[b - 1][a - 1] = c

result = 0
for i in range(n):
    tempMax = 0
    visited = [0] * n
    q = collections.deque()
    visited[i] = 1
    q.append((i, 0))
    while q:
        node, cost = q.popleft()
        for j in range(n):
            if graph[node][j] and visited[j] == 0:
                q.append((j, cost + graph[node][j]))
                visited[j] = 1
        result = max(result, cost)

print(result)

#트리의 지름(1967)
#추가적인 아이디어가 필요했다.
#2차원 리스트를 만들어 연결 노드와 cost를 저장한다.
#skill.1 - 루트 node에서 가장 먼 노드를 찾는다.
#skill.2 - 위의 결과 노드에서 가장 먼 노드를 찾고 그 거리를 출력한다.
#skill.3 - 트리의 특성을 응용한 문제이다.

import collections

n = int(input())

graph = [[]for _ in range(n)]
for _ in range(n - 1):
    a, b, c = map(int, input().split())
    graph[a - 1].append([c, b - 1])
    graph[b - 1].append([c, a - 1])
distance = [-1] * n

q = collections.deque()
q.append(0)
distance[0] = 0
while q:
    cx = q.popleft()
    for cost, nx in graph[cx]:
        if distance[nx] == -1:
            distance[nx] = distance[cx] + cost
            q.append(nx)

result = [-1] * n
rsx = distance.index(max(distance))
result[rsx] = 0

q = collections.deque()
q.append(rsx)
while q:
    cx = q.popleft()
    for cost, nx in graph[cx]:
        if result[nx] == -1:
            result[nx] = result[cx] + cost
            q.append(nx)

print(max(result))
