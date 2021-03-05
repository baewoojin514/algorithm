#선수과목(Prerequisite)
#위상정렬을 사용해서 해결한다.

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
result = [0] * N
for i in range(1, N + 1):
    if indegree[i] == 0:
        q.append((1, i))
        result[i - 1] = 1
        #학기와 과목 번호를 append한다.

while q:
    year, cx = q.popleft()

    for i in graph[cx]:
        indegree[i] -= 1
        if indegree[i] == 0:
            q.append((year + 1, i))
            result[i - 1] = year + 1
for i in result:
    print(i, end=" ")
