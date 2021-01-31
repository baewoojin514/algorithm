#다리만들기(2146)
#bfs와 dfs로 해결 가능하다.
#skill.1 - 먼저 bfs를 통해 같은 섬간 동일한 번호를 붙인다(1부터 시작한다).
#skill.2 - 섬을 확장하는 함수를 만든다 => 섬을 확장하다가 현재 섬과 다른 번호를 만나면 ++한 distance로 최단 거리를 갱신한다.
#skill.3 - 한 섬에서 다른 섬으로 이동하기 때문에 섬이 아닌 좌표인 경우 deque에 append 하고 섬이면서 현재 섬과 다른 섬일 경우 다리 길이의 최소 값을 갱신한다.

from collections import deque

def expanision(islandNum):
    global minDistance
    visited = [[int(0) for _ in range(N)]for _ in range(N)]
    bridge = deque()
    for i in range(N):
        for j in range(N):
            if island[i][j] == islandNum:
                visited[i][j] = 1
                bridge.append((i, j))

    distance = 0
    while bridge:
        qsize = len(bridge)
        for _ in range(qsize):
            cx, cy = bridge.popleft()
            for i in range(4):
                nx = cx + dx[i]
                ny = cy + dy[i]
                if 0 <= nx < N and 0 <= ny < N:
                    if visited[nx][ny] == 0:
                        if board[nx][ny] == 0:
                            visited[nx][ny] = 1
                            bridge.append((nx, ny))
                        elif board[nx][ny] == 1 and island[nx][ny] != islandNum:
                            minDistance = min(minDistance, distance)
        distance += 1
        #확장 후 다리의 거리를 늘린다.


dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

minDistance = 10000

N = int(input())
board = [[int(x) for x in input().split()]for _ in range(N)]
island = [[int(0) for _ in range(N)]for _ in range(N)]
visited = [[int(0) for _ in range(N)]for _ in range(N)]

cnt = 0
for i in range(N):
    for j in range(N):
        if board[i][j] == 1 and visited[i][j] == 0:
            cnt += 1
            num = deque()
            num.append((i, j))
            visited[i][j] = 1
            island[i][j] = cnt

            while num:
                cx, cy = num.popleft()
                for _ in range(4):
                    nx = cx + dx[_]
                    ny = cy + dy[_]
                    if 0 <= nx < N and 0 <= ny < N:
                        if board[nx][ny] == 1 and visited[nx][ny] == 0:
                            visited[nx][ny] = 1
                            island[nx][ny] = cnt
                            num.append((nx, ny))

for i in range(1, cnt + 1):
    expanision(i)

print(minDistance)
