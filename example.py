import collections
import sys

def find(X, Y):
    global K
    visited1[X][Y] = 1
    cost = 0
    q1.append((X, Y))
    while q1:
        compare = len(q1)
        customer = []
        cost += 1
        if cost >= K:
            return 0
        for i in range(compare):
            cx, cy = q1.popleft()
            for j in range(4):
                nx, ny = cx + dx[j], cy + dy[j]
                if 0 <= nx < N and 0 <= ny < N:
                    if visited1[nx][ny] == 0 and board[nx][ny] != -1:
                        if board[nx][ny] > 0:
                            customer.append([nx, ny])
                        visited1[nx][ny] = 1
                        q1.append((nx, ny))
        if customer:
            break
    if not customer:
        return 0
    K -= cost
    customer = sorted(customer)

    rsx = customer[0][0]
    rsy = customer[0][1]
    res = ride(rsx, rsy, board[rsx][rsy])
    if res == 0:
        return 0
    tempcost, nsx, nsy = res
    K += tempcost
    board[rsx][rsy] = 0
    return nsx, nsy


def ride(X, Y, custnum):
    visited2[X][Y] = 0
    q2.append((X, Y))

    while q2:
        cx, cy = q2.popleft()
        if visited2[cx][cy] >= K:
            return 0
        for i in range(4):
            nx, ny = cx + dx[i], cy + dy[i]
            if 0 <= nx < N and 0 <= ny < N:
                if visited2[nx][ny] == -1 and board[nx][ny] != -1:
                    q2.append((nx, ny))
                    visited2[nx][ny] = visited2[cx][cy] + 1
                    if nx == end[custnum][0] and ny == end[custnum][1]:
                        return visited2[nx][ny], nx, ny
    return 0


N, M, K = map(int, input().split())
board = [[int(x) for x in input().split()]for y in range(N)]
dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]
X, Y = map(int, input().split())

for i in range(N):
    for j in range(N):
        if board[i][j] == 1:
            board[i][j] = -1
end = [[]for x in range(M + 1)]
for i in range(M):
    a, b, c, d = map(int, input().split())
    board[a - 1][b - 1] = i + 1
    end[i + 1] = [c - 1, d - 1]

X -= 1
Y -= 1

for i in range(M):
    q1 = collections.deque()
    q2 = collections.deque()
    visited1 = [[0 for _ in range(N)]for _ in range(N)]
    visited2 = [[-1 for _ in range(N)]for _ in range(N)]

    if board[X][Y] > 0:
        res = ride(X, Y, board[X][Y])
        if res == 0:
            print(-1)
            sys.exit()
        fuel, nx, ny = res
        if fuel > K:
            print(-1)
            sys.exit()
        K += fuel
        board[X][Y] = 0
        X = nx
        Y = ny
        continue

    res = find(X, Y)
    if res == 0:
        print(-1)
        sys.exit()
    else:
        X, Y = res

print(K)
