#N과 M(12)(15666)
#dfs재귀로 해결한다.
#입력되는 N 개의 수중 M개를 고르고 출력한다.
#재귀 함수의 limit == M이면 각 수열을 canbe 리스트에 append한다.
#skill.1 - 입력 받은 수의 리스트를 정렬한다.
#skill.2 - 수열 자체가 중복될 수 없고 내부 요소는 중복 가능하다 => 입력받은 수를 set을 통해 처리한다.
#skill.3 - 수열이 비내림차순 이어야 하기 때문 parameter로 limit에 과 index를 사용하고 visited 리스트를 사용하지 않는다.

def dfs(index, limit):
    if limit == M:
        tmp = ' '.join(map(str, temp))
        print(tmp)
        return
    for j in range(index, len(num)):
        temp[limit] = num[j]
        dfs(j, limit + 1)
        temp[limit] = 0


N, M = map(int, input().split())
num = [int(x) for x in input().split()]
num = list(set(num))
num.sort()

temp = [0] * M
canbe = []
dfs(0, 0)
