#ACM Craft(1005)
#작업의 전후 관계를 graph 리스로 만든다.
#skill.1 - 위상정렬을 적용해서 해결할 수 있다.
#skill.2 - indgree가 0인 작업이 동시에 여러개 발생할 수도 있다.
#skill.3 - 선행작업이 여러개라면 그 중 시간이 가장 많이 걸리는 작업을 해결해야 후행 작업을 할 수 있다.

from collections import deque
import sys

input = sys.stdin.readline

T = int(input())

for _ in range(T):
    N, K = map(int, input().split())
    times = [int(x) for x in input().split()]
    graph = [[]for _ in range(N + 1)]
    indegree = [0] * (N + 1)
    result = [0] * (N + 1)

    for _ in range(K):
        a, b = map(int, input().split())
        graph[a].append(b)
        indegree[b] += 1

    W = int(input())
    q = deque()
    for i in range(1, N + 1):
        if indegree[i] == 0:
            q.append(i)
            result[i] = times[i - 1]
    while q:
        cx = q.popleft()

        for i in graph[cx]:
            indegree[i] -= 1
            if indegree[i] == 0:
                q.append(i)
            result[i] = max(result[i], result[cx] + times[i - 1])

    print(result[W])
