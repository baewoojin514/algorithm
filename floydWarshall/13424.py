#비밀 모임(13424)
#플로이드 와샬 알고리즘을 사용한 최단 경로 알고리즘 문제이다.
#K개의 방에 대해서 K를 제외한 나머지 방까지 갈 수 있는 최단 거리의 총합이 가장 적은 경우의 방 번호를 출력한다.
INF = 1e9

T = int(input())

for _ in range(T):
    N, M = map(int, input().split())
    graph = [[INF for _ in range(N)]for _ in range(N)]

    for _ in range(M):
        a, b, c = map(int, input().split())
        graph[a - 1][b - 1] = min(graph[a - 1][b - 1], c)
        graph[b - 1][a - 1] = min(graph[b - 1][a - 1], c)
    K = int(input())

    friends = list(map(int, input().split()))

    for i in range(N):
        for j in range(N):
            for k in range(N):
                if j == k:
                    graph[j][k] = 0
                else:
                    graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k])

    result = -1
    for i in range(N):
        tempDistance = 0
        for j in friends:
            tempDistance += graph[i][j - 1]
        if INF > tempDistance:
            result = i
            INF = tempDistance

    print(result + 1)
    INF = 1e9
