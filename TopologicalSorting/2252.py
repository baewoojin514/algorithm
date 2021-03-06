#줄세우기(2252)
#신장의 전후 관계를 graph 리스트로 만든다.
#skill.1 - 위상정렬을 적용해서 해결할 수 있다.
#skill.2 - indegree가 0인 경우 우선순위 큐를 사용해서 random하게 pop한다.

from collections import deque
import sys

input = sys.stdin.readline

N, M = map(int, input().split())
indegree = [0] * (N + 1)
graph = [[]for _ in range(N + 1)]

for _ in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)
    indegree[b] += 1

q = deque()
for i in range(1, N + 1):
    if indegree[i] == 0:
        q.append(i)

result = []
while q:
    cx = q.popleft()
    result.append(cx)

    for i in graph[cx]:
        indegree[i] -= 1
        if indegree[i] == 0:
            q.append(i)

for order in result:
    print(order, end=" ")
