#케빈 베이컨의 6단계 법칙(1389)
#네트워크와 유사한 문제이다.
#입력으로 들어오는 관계들을 2차원 리스트에 0과 1로 표현한다.
#네트워크 문제처럼 사람마다 지인들을 통해 연결될 수 있는 사람들의 수를 구하고 그 수에서 1을 빼면 케빈 베이컨의 수이다.
#사람들의 수만큼 위의 과정을 반복하고 최소값을 계속해서 갱신한다.
#케빈 베이컨 수가 같으면 번호가 작은 사람이 답이다.
#그래프 이론으로 접근 가능한 문제이지만 bfs로 구현하는 것이 더 효과적이다.

import collections

N, M = map(int, input().split())
bacon = [[int(0)for _ in range(N)]for _ in range(N)]
for _ in range(M):
    a, b = map(int, input().split())
    bacon[a - 1][b - 1] = 1
    bacon[b - 1][a - 1] = 1
minValue = 100
result = 0
for i in range(N):
    baconNum = 0
    visited = [0] * N
    q = collections.deque()
    visited[i] = 1
    q.append((i, 0))
    while q:
        people, tempNum = q.popleft()
        for j in range(N):
            if bacon[people][j] == 1 and visited[j] == 0:
                q.append((j, tempNum + 1))
                visited[j] = 1
                baconNum += tempNum + 1
    if minValue > baconNum:
        result = i + 1
        minValue = baconNum
print(result)

