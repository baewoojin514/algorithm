#N과 M(6)(15655)
#dfs재귀로 해결한다.
#입력되는 N개의  수 중 M개를 고르고 출력한다.
#재귀 함수의 limit == M이면 각 수열을 출력한다.
#skill.1 - 입력 받은 수의 리스트를 정렬해야 한다.
#skill.2 - 각 수열은 오름차순 이어야 한다.
#skill.3 - 오름차순 정렬을 위해 index를 parameter를 사용해서 호출해야 한다.

def dfs(index, limit):
    if limit == M:
        print(*temp)
        #*를 사용해서 리스트의 요소를 공백을 두고 출력할 수 있다.
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
dfs(0, 0)
