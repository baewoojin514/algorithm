#N과 M(4)(15652)
#dfs재귀로 해결한다.
#1부터 N까지의 수중 N개를 고르고 출력한다.
#재귀 함수의 limit == M이면 각 수열을 출력한다.
#skill.1 - 중복이 허용된다.
#skill.2 - 수열은 비내림차순 즉 다음 수는 현재 수 이상의 수만 추가될 수 있다.
#skill.3 - visited 리스트를 사용해 중복 체크하지 않고 index를 parameter로 사용해 dfs함수를 호출한다.

def dfs(index, limit):
    if limit == M:
        print(*temp)
        #*를 사용해서 리스트의 요소를 공백을 두고 출력할 수 있다.
        return

    for j in range(index, N + 1):
        temp.append(j)
        dfs(j, limit + 1)
        #비내림차순은 현재 수 이상의 수이면 된다. 따라서 parameter로 j로 호출한다.
        temp.pop()


N, M = map(int, input().split())
temp = []
dfs(1, 0)
