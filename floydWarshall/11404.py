#플로이드(11404)
#플로이드 와샬 알고리즘을 사용한 최단 경로 알고리즘 문제이다.
#동일 도시간 경로가 여러개일 수도 있기 때문에 최소 값으로 계속 갱신해야 한다.
#마지막에 이중 for문으로 탐색하면서 그대로 INF일 경우 0을 출력하고 아닐 경우 최단 경로를 출력한다.


n = int(input())
m = int(input())

INF = 1e9

graph = [[INF for _ in range(n)]for _ in range(n)]

for _ in range(m):
    a, b, c = map(int, input().split())
    graph[a - 1][b - 1] = min(graph[a - 1][b - 1], c)

for i in range(n):
    for j in range(n):
        for k in range(n):
            if j != k:
                graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k])

for i in range(n):
    for j in range(n):
        if graph[i][j] == INF:
            print(0, end=' ')
        else:
            print(graph[i][j], end=' ')
    print()
