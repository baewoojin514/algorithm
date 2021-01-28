#연구소 2(17141)
#연구소 3와 유사한 시뮬레이션 문제이다.
#바이러스는 2에 놓을 수 있다.
#바이러스를 놓을 수 있는 위치 중 M개을 선택한다(combination).
#skill.1 - 바이러스를 퍼뜨릴수 있는 빈칸의 수를 구한다(현재 빈칸 + 가능한 바이러스 위치 - M).
#skill.2 - bfs를 통해 바이러스를 확산 시키고 빈칸에 바이러스를 퍼뜨리는 경우를 sum 한다.
#skill.3 - 1 과 2 가 동일한 값이면 바이러스를 모든 빈칸에 퍼뜨린 경우이기 때문에 최소 시간을 갱신한다.

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
            board[i][j] = 0
            virusCount += 1
virusCount -= M

virusCanbe = list(itertools.combinations(canbe, M))
for info in virusCanbe:
    virus = collections.deque()
    dist = [[int(-1) for _ in range(N)] for _ in range(N)]
    for i in info:
        virus.append((i[0], i[1]))
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
                    tempCount += 1
                    tempTime = dist[nx][ny]
                    virus.append((nx, ny))

    if virusCount == tempCount:
        minTime = min(minTime, tempTime)

if minTime == 2500:
    print(-1)
else:
    print(minTime)
