#N과 M(10)(15664)
#dfs재귀로 해결한다.
#입력되는 N 개의 수중 M개를 고르고 출력한다.
#재귀 함수의 limit == M이면 각 수열을 출력한다.
#skill.1 - 입력 받은 수의 리스트를 정렬한다.
#skill.2 - 수열과 수열의 요소가 중복될 수 없다.
#skill.3 - set 즉 집합을 사용해서 삽입시 중복을 방지한다.
#skill.4 - 수열은 비내림차순 이어야 하기 때문 j + 1 로 재귀 함수를 호출해야 한다.

def dfs(index, limit):
    if limit == M:
        tmp = ' '.join(map(str, temp))
        if tmp not in canbe:
            canbe.append(tmp)
        return
    for j in range(index, N):
        if visited[j] == 0:
            temp.append(num[j])
            visited[j] = 1
            dfs(j + 1, limit + 1)
            temp.pop()
            visited[j] = 0


N, M = map(int, input().split())
num = [int(x) for x in input().split()]
visited = [0] * N
num.sort()
temp = []
canbe = []
dfs(0, 0)
for i in canbe:
    print(i)
