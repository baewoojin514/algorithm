#트리의 지름(1167)
#트리의 임의의 두 노드 사이의 거리 중 가장 큰 것이 트리의 지름이다.
#skill.1 - 임의의 노드에서 가장 거리가 큰 노드를 찾는다.
#skill.2 - 1에서 찾은 노드에서 가장 거리가 큰 노드를 찾는다.
#skill.3 - 1,2 노드 간 거리를 구한다.

from collections import deque

V = int(input())

graph = [[] for _ in range(V + 1)]

for _ in range(1, V + 1):
    temp = [int(x) for x in input().split()]
    list_len = len(temp)

    for i in range(1, list_len // 2):
        a = temp[2*i - 1]
        b = temp[2*i]
        graph[temp[0]].append([a, b])
        graph[a].append([temp[0], b])

distance1 = [-1] * (V + 1)
q1 = deque()
q1.append(1)
distance1[1] = 0

while q1:
    cx = q1.popleft()
    for nx, cost in graph[cx]:
        if distance1[nx] == -1:
            distance1[nx] = distance1[cx] + cost
            q1.append(nx)


rsx = distance1.index(max(distance1))

distance2 = [-1] * (V + 1)
q2 = deque()
q2.append(rsx)
distance2[rsx] = 0

while q2:
    cx = q2.popleft()
    for nx, cost in graph[cx]:
        if distance2[nx] == -1:
            distance2[nx] = distance2[cx] + cost
            q2.append(nx)

print(max(distance2))
