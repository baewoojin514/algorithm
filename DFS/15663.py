#N과 M(8)(15663)
#dfs재귀로 해결한다.
#입력되는 N 개의 수중 M개를 고르고 출력한다.
#재귀 함수의 limit == M이면 각 수열을 출력한다.
#skill.1 - 입력 받은 수의 리스트를 정렬한다.
#skill.2 - 수열 자체가 중복되면 안된다.
#skill.3 - parameter 로 limit 만을 사용하되 canbe 리스트의 요소와 중복이 되는지 확인 후 append한다.

def dfs(limit):
    if limit == M:
        tmp = ' '.join(map(str, temp))
        if tmp not in canbe:
            canbe.append(tmp)
        return
    for j in range(N):
        if visited[j] == 0:
            temp.append(num[j])
            visited[j] = 1
            dfs(limit + 1)
            temp.pop()
            visited[j] = 0


N, M = map(int, input().split())
num = [int(x) for x in input().split()]
visited = [0] * N
num.sort()
temp = []
canbe = []
dfs(0)
for i in canbe:
    print(i)
