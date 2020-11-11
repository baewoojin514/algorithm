#치즈(2638) - resolved
#공기와 치즈 내부의 공간을 구분해야 한다.
#0,0은 무조건 공기이기 때문에 bfs를 통해서 -1로 모두 바꿔준다.
#이중 for문을 사용해서 -1이 2개 이상으로 접촉해 있는 치즈를 0으로 바꾼다.
#0의 개수를 count 하고 격자의 개수와 같다면 count를 출력하고 종료한다.
import collections
import sys

N, M = map(int, input().split())

cheese = [[int(x)for x in input().split()]for _ in range(N)]

dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]

time = 0
while True:
    time += 1
    q = collections.deque()
    visited = [[int(0)for _ in range(M)]for _ in range(N)]
    visited[0][0] = 1
    cheese[0][0] = -1
    q.append((0, 0))
    while q:
        cx, cy = q.popleft()
        for _ in range(4):
            nx = cx + dx[_]
            ny = cy + dy[_]
            if 0 <= nx < N and 0 <= ny < M:
                if visited[nx][ny] == 0 and cheese[nx][ny] == 0:
                    q.append((nx, ny))
                    visited[nx][ny] = 1
                    cheese[nx][ny] = -1
    count = [[int(0)for _ in range(M)]for _ in range(N)]
    for i in range(N):
        for j in range(M):
            if cheese[i][j] == 1:
                for k in range(4):
                    ni = i + dx[k]
                    nj = j + dy[k]
                    if 0 <= ni < N and 0 <= nj < M:
                        if cheese[ni][nj] == -1:
                            count[i][j] += 1
    for i in range(N):
        for j in range(M):
            if count[i][j] >= 2:
                cheese[i][j] = -1
    check = 0
    for i in range(N):
        for j in range(M):
            if cheese[i][j] == 0:
                check += 1
            elif cheese[i][j] == -1:
                cheese[i][j] = 0
                check += 1
    if check == N * M:
        print(time)
        sys.exit()
