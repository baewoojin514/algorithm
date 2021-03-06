#문제집(1766)
#풀어야 할 문제의 전후 관계를 graph 리스트로 만든다.
#최대한 쉬운 문제 즉 index가 작은 문제를 풀어야한다.
#skill.1 - heapq를 사용해서 index가 가장 작은 node를 pop한다.
#skill.2 - 위상정렬을 적용해서 해결할 수 있다.

import heapq
import sys

input = sys.stdin.readline

N, M = map(int, input().split())
indegree = [0] * (N + 1)
graph = [[]for _ in range(N + 1)]

q = []

for _ in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)
    indegree[b] += 1

for i in range(1, N + 1):
    if indegree[i] == 0:
        heapq.heappush(q, (i))
result = []

while q:
    cx = heapq.heappop(q)
    result.append(cx)

    for i in graph[cx]:
        indegree[i] -= 1
        if indegree[i] == 0:
            heapq.heappush(q, (i))

for i in result:
    print(i, end=" ")
