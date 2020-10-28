#스타트 택시(19238)
#시뮬레이션 문제
#승객을 태우러 가는 시작점 자체가 승객이 서있는 곳일 수 있다는 점을 간과 해서 error 발생!
#승객 정보를 dictionary로 관, 가까운 승객을 heapq를 사용해서 시간 복잡도 최소화 가능
#승객을 다 태우지 못했을 경우를 대비해 numcheck을 사용한다.
#중간에 연료가 떨어질 경우 -1출력후 바로 종료한다.
#pypy3로는 문제 없이 결과를 출력하나 python3로 결과 출력 가능 하도록 개선이 필요하다.

import collections
import sys

N, M, K = map(int, input().split())
board = [[int(x) for x in input().split()]for y in range(N)]
dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]
X, Y = map(int, input().split())
for i in range(N):
    for j in range(N):
        if board[i][j] == 1:
            board[i][j] = -1
destination = [[]for x in range(M + 1)]
for i in range(M):
    a, b, c, d = map(int, input().split())
    board[a - 1][b - 1] = i + 1
    destination[i + 1] = [c - 1, d - 1]
Fuel1 = True
Fuel2 = True
numcheck = M
q1 = collections.deque()
q2 = collections.deque()
X -= 1
Y -= 1
result = []
for _ in range(M):
    visited = [[int(0) for x in range(N)] for y in range(N)]
    q1.append((X, Y, 0))
    visited[X][Y] = 1
    customer = []
    while q1:
        cx, cy, tempcost = q1.popleft()
        if board[cx][cy] > 0:
            customer.append([cx, cy, tempcost])
        for i in range(4):
            nx, ny = cx + dx[i], cy + dy[i]
            if 0 <= nx < N and 0 <= ny < N:
                if visited[nx][ny] == 0:
                    if board[nx][ny] != -1:
                        if board[nx][ny] > 0:
                            customer.append([nx, ny, tempcost + 1])
                            q1.append((nx, ny, tempcost + 1))
                            visited[nx][ny] = 1
                        q1.append((nx, ny, tempcost + 1))
                        visited[nx][ny] = 1
    if not customer:
        print(-1)
        sys.exit()
    customer = sorted(customer, key = lambda x : (x[2], x[0], x[1]))
    if customer[0][2] >= K:
        print(-1)
        sys.exit()
    cost1 = customer[0][2]
    togo = board[customer[0][0]][customer[0][1]]
    rsx, rsy = customer[0][0], customer[0][1]
    edx, edy = destination[togo][0], destination[togo][1]
    board[customer[0][0]][customer[0][1]] = 0
    K -= cost1
    dest = []
    visited = [[int(0) for x in range(N)] for y in range(N)]
    q2.append((rsx, rsy, 0))
    visited[rsx][rsy] = 1
    while q2:
        cx, cy, tempcost = q2.popleft()
        for i in range(4):
            nx, ny = cx + dx[i], cy + dy[i]
            if 0 <= nx < N and 0 <= ny < N:
                if visited[nx][ny] == 0:
                    if board[nx][ny] != -1:
                        visited[nx][ny] = 1
                        q2.append((nx, ny, tempcost + 1))
                        if nx == edx and ny == edy:
                            dest.append(nx)
                            dest.append(ny)
                            dest.append(tempcost + 1)
    if not dest:
        print(-1)
        sys.exit()
    if dest[2] > K:
        print(-1)
        sys.exit()
    K -= dest[2]
    K += 2 * dest[2]
    X = dest[0]
    Y = dest[1]
    q1.clear()
    q2.clear()
    numcheck -= 1

if numcheck > 0:
    print(-1)
else:
    print(K)
