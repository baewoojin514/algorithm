#말이 되고픈 원숭이(1600)
#K번 말 처럼 이동할 수 있다.
#말 처럼 이동하는 능력을 사용한 회수가 K보다 작은 경우 먼저 말 처럼 이동한 정보를 deque에 append한다.
#skill.1 - 같은 좌표라 할지라도 말의 능력을 사용한 경우의 수를 구분해야 한다.
#skill.2 - visited 리스트를 3차원으로 만든다 => 같은 회수에 대해서는 먼저 도착한 경우가 선점한다.
#skill.3 - 목표 지점에 도착한 경우 이동한 회수를 출력한다.
#skill.4 - deque에 삽입해야 할 정보는 좌표, 말의 능력을 사용한 회수, 이동한 회수 이다.

import collections

minTime = 40000

K = int(input())
W, H = map(int, input().split())

board = [[int(x) for x in input().split()]for _ in range(H)]
visited = [[[0] * (K + 1) for _ in range(W)]for _ in range(H)]

dx = [0, 1, 0, -1]
dy = [-1, 0, 1, 0]
hdx = [-2, -1, 1, 2, 2, 1, -1, -2]
hdy = [-1, -2, -2, -1, 1, 2, 2, 1]
#말의 능력을 사용할 수 있는 dx dy 값이다.

monkey = collections.deque()
monkey.append((0, 0, 0, 0))
#좌표, 사용한 말의 능력 개수, 이동한 회수
visited[0][0][0] = 1

while monkey:
    cx, cy, horsePower, cnt = monkey.popleft()
    if cx == H - 1 and cy == W - 1:
        minTime = min(minTime, cnt)

    if horsePower < K:
        for i in range(8):
            nx = cx + hdx[i]
            ny = cy + hdy[i]
            if 0 <= nx < H and 0 <= ny < W:
                if board[nx][ny] == 0 and visited[nx][ny][horsePower + 1] == 0:
                    visited[nx][ny][horsePower + 1] = 1
                    monkey.append((nx, ny, horsePower + 1, cnt + 1))
    for i in range(4):
        nx = cx + dx[i]
        ny = cy + dy[i]
        if 0 <= nx < H and 0 <= ny < W:
            if board[nx][ny] == 0 and visited[nx][ny][horsePower] == 0:
                visited[nx][ny][horsePower] = 1
                monkey.append((nx, ny, horsePower, cnt + 1))

if minTime == 40000:
    print(-1)
else:
    print(minTime)
