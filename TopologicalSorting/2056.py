#작업(2056)
#위상정렬과 dynamic programming 으로 해결할 수 있다.
#위상정렬로 탐색하면서 작업 시간을 더해간다.
#ACM craft와 유사한 문제이다.

from collections import deque

N = int(input())

info = [[int(x) for x in input().split()]for _ in range(N)]

indegree = [0] * (N + 1)
times = [0] * (N + 1)
result = [0] * (N + 1)

graph = [[]for _ in range(N + 1)]

for i in range(N):
    temp = info[i]
    times[i + 1] = temp[0]
    newRange = temp[1]
    if newRange == 0:
        continue
    for tmp in temp[2 : ]:
        graph[tmp].append(i + 1)
        indegree[i + 1] += 1

q = deque()
for i in range(1, N + 1):
    if indegree[i] == 0:
        q.append(i)
        result[i] = times[i]

while q:
    cx = q.popleft()

    for i in graph[cx]:
        indegree[i] -= 1
        if indegree[i] == 0:
            q.append(i)
        result[i] = max(result[i], result[cx] + times[i])
        #선행작업들 중 가장 시간이 오래걸리는 작업을 완료해야 다음 작업이 가능하다.

print(max(result))
