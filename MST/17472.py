#다리 만들기2(17472)
#bfs와 dfs로 해결 가능하다.
#MST를 사용해야 한다 => union_find, find_parent
#skill.1 - 먼저 bfs를 통해 같은 섬간 동일한 번호를 붙인다(1 부터 시작).
#skill.2 - 다리를 놓을 수 있는 좌표를 판별하고 4방향에 대해서 dfs를 실행한다.
#skill.3 - 다른 섬을 만나면 시작 섬의 번호, 도착 섬의 번호, 다리의 길이를 이차원 graph 리스트에 저장한다.
#skill.4 - graph 정보를 가지고 MST 알고리즘을 적용해 답을 도출한다.

from collections import deque
import sys

input = sys.stdin.readline


def inside(X, Y):
    return 0 <= X < N and 0 <= Y < M


def find_parent(parent, X):
    if parent[X] != X:
        parent[X] = find_parent(parent, parent[X])
    return parent[X]


def union_parent(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)
    if a > b:
        parent[a] = b
    else:
        parent[b] = a


dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

N, M = map(int, input().split())
board = [[int(x) for x in input().split()]for _ in range(N)]
visited = [[int(0) for _ in range(M)]for _ in range(N)]
island = [[int(0) for _ in range(M)]for _ in range(N)]

cnt = 0
for i in range(N):
    for j in range(M):
        if board[i][j] == 1 and visited[i][j] == 0:
            cnt += 1
            q = deque()
            visited[i][j] = 1
            island[i][j] = cnt
            q.append((i, j))

            while q:
                cx, cy = q.popleft()
                for _ in range(4):
                    nx = cx + dx[_]
                    ny = cy + dy[_]
                    if inside(nx, ny):
                        if board[nx][ny] == 1 and visited[nx][ny] == 0:
                            visited[nx][ny] = 1
                            island[nx][ny] = cnt
                            q.append((nx, ny))


graph = []
for i in range(N):
    for j in range(M):
        if island[i][j]:
            for k in range(4):
                nx = i + dx[k]
                ny = j + dy[k]
                tempDitance = 0
                while inside(nx, ny) and not island[nx][ny]:
                    nx += dx[k]
                    ny += dy[k]
                    tempDitance += 1
                    if inside(nx, ny) and island[nx][ny] != island[i][j] and island[nx][ny]:
                        if tempDitance >= 2:
                            graph.append([tempDitance, island[i][j], island[nx][ny]])

parent = [0] * (cnt + 1)

for i in range(1, cnt + 1):
    parent[i] = i

graph.sort()
total = 0
checkNum = 0

for edge in graph:
    cost, a, b = edge
    if find_parent(parent, a) != find_parent(parent, b):
        union_parent(parent, a, b)
        total += cost
        checkNum += 1

if checkNum != cnt - 1:
    print(-1)
else:
    print(total)
