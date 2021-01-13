#N과 ㅡ(1)(15649)
#dfs재귀로 해결한다.
#1부터 N까지의 수중 N개를 고르고 출력한다.
#재귀 함수의 limit == M이면 각 수열을 출력한다.

def dfs(limit):
    if limit == M:
        print(*temp)
        #*를 사용해서 리스트의 요소를 공백을 두고 출력할 수 있다.

    for j in range(1, N + 1):
        if visited[j] == 0:
            visited[j] = 1
            temp.append(j)
            dfs(limit + 1)
            visited[j] = 0
            temp.pop()


N, M = map(int, input().split())

temp = []
visited = [0] * (N + 1)
dfs(0)
