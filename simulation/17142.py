#연구소 3(17142)
#연구소 2와 유사한 시뮬레이션 문제이다.
#비활성화 바이러스가 활성화 바이러스로 변하여 퍼뜨리는 경우를 제외해야 한다.
#skill.1 - 처음에 바이러스를 순수하게 퍼뜨릴 수 있는 빈칸 즉 0의 개수를 count한다.
#skill.2 - 빈칸에 바이러스를 퍼뜨리는 경우를 count한다.
#skill.3 - 2개의 count가 동일할 경우 빈칸에 바이러스를 퍼뜨린 경우이다. 이경우 빈칸이 존재하지 않다면 그 시간을 최소값으로 갱신한다.

import collections
import itertools

N, M = map(int, input().split())

board = [[int(x) for x in input().split()]for _ in range(N)]
minTime = 2500

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

virusCount = 0
canbe = []
for i in range(N):
    for j in range(N):
        if board[i][j] == 0:
            virusCount += 1
        elif board[i][j] == 2:
            canbe.append([i, j])

virusCanbe = list(itertools.combinations(canbe, M))
for info in virusCanbe:
    virus = collections.deque()
    dist = [[int(-1) for _ in range(N)]for _ in range(N)]
    for i in info:
        virus.append((i[0], i[1]))
        board[i[0]][i[1]] = 0
        dist[i[0]][i[1]] = 0

    tempTime = 0
    tempCount = 0
    while virus:
        cx, cy = virus.popleft()
        for _ in range(4):
            nx = cx + dx[_]
            ny = cy + dy[_]
            if 0 <= nx < N and 0 <= ny < N:
                if board[nx][ny] != 1 and dist[nx][ny] == -1:
                    dist[nx][ny] = dist[cx][cy] + 1
                    if board[nx][ny] == 0:
                        tempCount += 1
                        tempTime = dist[nx][ny]
                    virus.append((nx, ny))
            #벽이 아니고 방문했던 곳이 아닌경우 무조건 거리를 늘리고 deque에 삽입한다.
            #하지만 빈칸인 경우 원래 빈칸의 수와 비교하기 위해 count를 += 1하고 tempTime을 갱신한다.
    if virusCount == tempCount:
        minTime = min(minTime, tempTime)
    for i in info:
        board[i[0]][i[1]] = 2
    #다음 경우를 위해 0으로 바꾸었던 바이러스를 다시 2로 바꾼다.

if minTime == 2500:
    print(-1)
else:
    print(minTime)
