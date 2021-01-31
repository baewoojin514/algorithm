#N과 M(11)(15665)
#dfs재귀로 해결한다.
#입력되는 N 개의 수중 M개를 고르고 출력한다.
#재귀 함수의 limit == M이면 각 수열을 canbe 리스트에 append한다.
#skill.1 - 입력 받은 수의 리스트를 정렬한다.
#skill.2 - 수열 자체가 중복될 수 없고 내부 요소는 중복 가능하다 => 입력받은 수를 set을 통해 처리한다.
#skill.3 - parameter로 limit 만을 사용하고 visited 리스트를 사용하지 않는다.

def dfs(limit):
    if limit == M:
        tmp = ' '.join(map(str, temp))
        print(tmp)
        return
    for j in range(len(num)):
        temp[limit] = num[j]
        dfs(limit + 1)
        temp[limit] = 0


N, M = map(int, input().split())
num = [int(x) for x in input().split()]
num = list(set(num))
num.sort()

temp = [0] * M
canbe = []
dfs(0)
