#N과 M(7)(15656)
#dfs재귀로 해결한다.
#입력되는 N개의 수중 M개를 고르고 출력한다.
#재귀 함수의 limit == M이면 각 수열을 출력한다.
#skill.1 - 입력 받은 수의 리스트를 정렬한다.
#skill.2 - 중복이 가능하다.
#skill.3 - 수열은 사전 순이어야 하지만 중복이 가능하기 때문에 parameter는 limit만 사용해서 재귀 함수를 호출한다.

def dfs(limit):
    if limit == M:
        print(*temp)
        #*를 사용해서 리스트의 요소를 공백을 두고 출력할 수 있다.
        return
    for j in range(N):
        temp.append(num[j])
        dfs(limit + 1)
        temp.pop()


N, M = map(int, input().split())
num = [int(x) for x in input().split()]
num.sort()
temp = []
dfs(0)
