#N과 M(2)(15650)
#dfs재귀로 해결한다.
#1부터 N까지의 수중 N개를 고르고 출력한다(오름차순).
#재귀 함수의 limit == M이면 각 수열을 출력한다.
#skill.1 - 모든 수열은 오름차순이어야 한다.
#skill.2 - 재귀 함수에서 다음수를 list에 append 시킬 때 현재 들어 있는 수보다 큰 수만 append 할 수 있다

def dfs(index, limit):
    if limit == M:
        print(*temp)
        #*를 사용해서 리스트의 요소를 공백을 두고 출력할 수 있다.

    for j in range(index, N + 1):
        #parameter에 index를 추가하여 기존의 수보다 큰 수를 재귀적으로 리스트에 추가한다.
        if visited[j] == 0:
            visited[j] = 1
            temp.append(j)
            dfs(j + 1, limit + 1)
            visited[j] = 0
            temp.pop()


N, M = map(int, input().split())

temp = []
visited = [0] * (N + 1)
dfs(1, 0)
