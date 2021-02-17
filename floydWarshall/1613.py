#역사(1613)
#플로이드 워셜 알고리즘을 사용해서 해결할 수 있다.
#역사의 전후 관계를 최단 경로의 시작, 도착 지점으로 치환할 수 있다.
#skill.1 - 주어진 역사 전후관계에 대해서 플로이드 워셜 알고리즘을 적용한다.
#skill.2 - s개의 전후관계에 대해서 순서에 따라 1, -1을 출력하고, INF일 경우 0을 출력한다.

import sys

input = sys.stdin.readline

n, k = map(int, input().split())
graph = [[int(0) for _ in range(n + 1)]for _ in range(n + 1)]

for _ in range(k):
    a, b = map(int, input().split())
    graph[a][b] = 1

for k in range(1, n + 1):
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            if graph[i][k] and graph[k][j]:
                graph[i][j] = 1
s = int(input())

for _ in range(s):
    a, b = map(int, input().split())
    if graph[a][b]:
        print(-1)
    elif graph[b][a]:
        print(1)
    else:
        print(0)
