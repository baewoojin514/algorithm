#경주로 건설(programmers)
#bfs를 통해 해결 가능하다.
#cx의 방향과 nx의 방향을 비교하여 방향성을 확인하는 함수가 필요한다.
#visited 리스트에 방문여부를 cost로 표시한다.

from collections import deque

dx = [0, 1, 0, -1]
dy = [-1, 0, 1, 0]
#좌, 하, 우, 상 순서이다.


def cango(oldD, newD):
    if oldD == newD:
        #같은 방향이면 1 return
        return 1
    elif (oldD + 2) % 4 == newD:
        #수평한 방향이면 1 return
        return 1
    else:
        #수직 방향이면 -1 return
        return -1

answer = 1e9

def solution(board):
    global answer
    N = len(board)
    visited = [[-1] * N for _ in range(N)]
    q = deque()
    q.append((0, 0, 0, 1))
    #cost, x, y, 방향 순서이다.
    #0, 0에서는 하단 또는 우측으로 출발할 수 있다.
    visited[0][0] = 0
    while q:
        cost, cx, cy, cdir = q.popleft()
        if cx == N - 1 and cy == N - 1:
            answer = min(answer, cost)

        for i in range(4):
            nx = cx + dx[i]
            ny = cy + dy[i]
            if 0 <= nx < N and 0 <= ny < N and board[nx][ny] == 0:
                if visited[nx][ny] == -1:
                    check = cango(cdir, i)
                    if check == 1:
                        # 경주로 건설이 가능하고 같은 방향인 경
                        visited[nx][ny] = cost + 100
                        q.append((cost + 100, nx, ny, i))
                    else:
                        visited[nx][ny] = cost + 600
                        q.append((cost + 600, nx, ny, i))
                else:
                    # 이미 방문한 경우 최단 경로를 갱신하여야 한다.
                    check = cango(cdir, i)
                    if check == 1:
                        # 경주로 건설이 가능하고 같은 방향인 경우우
                        if visited[nx][ny] > cost + 100:
                            visited[nx][ny] = cost + 100
                            q.append((cost + 100, nx, ny, i))
                    else:
                        if visited[nx][ny] > cost + 600:
                            visited[nx][ny] = cost + 600
                            q.append((cost + 600, nx, ny, i))
    #하단 방향과 우측 방향의 경우에 대해서 최소값을 구한다.
    visited = [[-1] * N for _ in range(N)]
    q = deque()
    q.append((0, 0, 0, 2))
    visited[0][0] = 0
    while q:
        cost, cx, cy, cdir = q.popleft()
        if cx == N - 1 and cy == N - 1:
            answer = min(answer, cost)

        for i in range(4):
            nx = cx + dx[i]
            ny = cy + dy[i]
            if 0 <= nx < N and 0 <= ny < N and board[nx][ny] == 0:
                if visited[nx][ny] == -1:
                    check = cango(cdir, i)
                    if check == 1:
                        # 경주로 건설이 가능하고 같은 방향인 경
                        visited[nx][ny] = cost + 100
                        q.append((cost + 100, nx, ny, i))
                    else:
                        visited[nx][ny] = cost + 600
                        q.append((cost + 600, nx, ny, i))
                else:
                    # 이미 방문한 경우 최단 경로를 갱신하여야 한다.
                    check = cango(cdir, i)
                    if check == 1:
                        # 경주로 건설이 가능하고 같은 방향인 경우우
                        if visited[nx][ny] > cost + 100:
                            visited[nx][ny] = cost + 100
                            q.append((cost + 100, nx, ny, i))
                    else:
                        if visited[nx][ny] > cost + 600:
                            visited[nx][ny] = cost + 600
                            q.append((cost + 600, nx, ny, i))
    return answer
