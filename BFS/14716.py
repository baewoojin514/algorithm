#현수막(14716)
#글자는 1 글자가 아닌부분은 0 이다.
#1로 연결된 덩어리의 개수를 구해야 한다.
#8개의 방향으로 연결된 1이 글자 하나이다.
#bfs로 문제를 해결한다.
import collections

M, N = map(int, input().split())

banner = [[int(x)for x in input().split()]for _ in range(M)]

dx = [-1, 0, 1, 0, 1, 1, -1, -1]
dy = [0, -1, 0, 1, 1, -1, 1, -1]

visited = [[int(0)for _ in range(N)]for _ in range(M)]

count = 0
for i in range(M):
    for j in range(N):
        if banner[i][j] == 1 and visited[i][j] == 0:
            visited[i][j] = 1
            q = collections.deque()
            q.append((i, j))
            while q:
                cx, cy = q.popleft()
                for _ in range(8):
                    nx = cx + dx[_]
                    ny = cy + dy[_]
                    if 0 <= nx < M and 0 <= ny <N:
                        if visited[nx][ny] == 0 and banner[nx][ny] == 1:
                            visited[nx][ny] = 1
                            q.append((nx, ny))
            count += 1
print(count)
