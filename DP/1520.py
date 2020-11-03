#내리막 길(1520)
#재귀 함수로 해결한다.
#상, 하, 좌, 우를 탐색하면서 board를 벗어나지 않고 현재 위치 보다 작은 값의 위치로 이동한다.
#재귀 함수를 종료하는 조건은 다음 위치 즉 nx, ny가 M - 1, N - 1일 경우 count += 1 이다.
#완전 탐색으로 구현하면 정답은 낼 수 있으나 시간 초과가 발생한다.
#알고리즘 분류처럼 dp방식을 사용해야 한다.

def wayFinder(cx, cy, visited):
    global count
    for i in range(4):
        nx, ny = cx + dx[i], cy + dy[i]
        if 0 <= nx < M and 0 <= ny < N:
            if visited[nx][ny] == 0:
                if board[nx][ny] < board[cx][cy]:
                    if nx == M - 1 and ny == N - 1:
                        count += 1
                    visited[nx][ny] = 1
                    wayFinder(nx, ny, visited)
                    visited[nx][ny] = 0


M, N = map(int, input().split())
dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]

board = [[int(x) for x in input().split()]for _ in range(M)]
visited = [[int(0)for _ in range(N)]for _ in range(M)]
visited[0][0] = 1
count = 0
wayFinder(0, 0, visited)

print(count)

