#N과 M(3)(15651)
#dfs재귀로 해결한다.
#1부터 N까지의 수중 N개를 고르고 출력한다.
#재귀 함수의 limit == M이면 각 수열을 출력한다.
#skill.1 - 중복이 허용된다.
#skill.2 - visited 리스트를

def dfs(limit):
    if limit == M:
        print(*temp)
        #*를 사용해서 리스트의 요소를 공백을 두고 출력할 수 있다.
        return

    for j in range(1, N + 1):
        # parameter에 index를 추가하여 기존의 수보다 큰 수를 재귀적으로 리스트에 추가한다.
        temp.append(j)
        dfs(limit + 1)
        temp.pop()


N, M = map(int, input().split())
temp = []
dfs(0)
