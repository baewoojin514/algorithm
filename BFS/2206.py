#벽 부수고 이동하기(2206)
#벽을 하나까지 부수고 이동할 수 있다.
#skill.1 - 벽을 부수고 이동한 경우 visited[][][1] 에 거리를 갱신한다.
#skill.2 - 벽을 부수지 않고 이동한 경우 visited[][][0] 에 거리를 갱한다.

from collections import deque
import sys

N, M = map(int, input().split())
board = [[int(x) for x in input()]for _ in range(N)]

dx = [0, 1, 0, -1]
dy = [-1, 0, 1, 0]

visited = [[[-1] * 2 for _ in range(M)]for _ in range(N)]

crack = deque()
crack.append((0, 0, 0))
visited[0][0][0] = 1
#시작하는 칸과 끝나는 칸도 경로에 포함된다.

while crack:
    cx, cy, flags = crack.popleft()

    for _ in range(4):
        nx = cx + dx[_]
        ny = cy + dy[_]
        if 0 <= nx < N and 0 <= ny < M:
            if board[nx][ny] == 0 and visited[nx][ny][flags] == -1:
                visited[nx][ny][flags] = visited[cx][cy][flags] + 1
                #벽을 부수지 않는 경우는 flags 0 visited 를 이동한 거리로 갱신한다.
                crack.append((nx, ny, flags))
            elif board[nx][ny] == 1 and visited[nx][ny][1] == -1 and flags == 0:
                #벽을 부수지 않은 경우 벽을 만났을 때 flags 를 벽을 부순 의미의 1로 바꾼다.
                visited[nx][ny][1] = visited[cx][cy][flags] + 1
                crack.append((nx, ny, 1))

canbe1 = visited[N - 1][M - 1][0]
canbe2 = visited[N - 1][M - 1][1]

if canbe1 == -1 and canbe2 != -1:
    print(canbe2)
elif canbe1 != -1 and canbe2 == -1:
    print(canbe1)
else:
    print(min(canbe1, canbe2))
