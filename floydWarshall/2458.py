#키 순서(2458)
#플로이드 워셜 알고리즘을 사용해서 해결할 수 있다.
#skill.1 - 키가 큰 학생을 1 작은 학생을 -1로 가정하고 플로이드 워셜 알고리즘을 적용한다.
#skill.2 - 각 행에 대해 0이 아닌 경우의 수를 모두 더하여 N - 1인 경우 신장의 대소 관계가 확실하여 순서를 매길 수 있는 경우이다.
import sys

input = sys.stdin.readline

N, M = map(int, input().split())
result = 0
graph = [[int(0) for _ in range(N + 1)]for _ in range(N + 1)]

for _ in range(M):
    a, b = map(int, input().split())
    graph[a][b] = 1
    graph[b][a] = -1

for k in range(1, N + 1):
    for i in range(1, N + 1):
        for j in range(1, N + 1):
            if graph[i][k] == 1 and graph[k][j] == 1:
                graph[i][j] = 1
            elif graph[i][k] == -1 and graph[k][j] == -1:
                graph[i][j] = -1
for i in range(1, N + 1):
    temp = 0
    for j in range(1, N + 1):
        if graph[i][j] != 0:
            temp += 1
    if temp == N - 1:
        #0이 아닌 요소의 개수가 N - 1인 경우 키의 순서를 확실히 알 수 있는 경우이다.
        result += 1

print(result)
