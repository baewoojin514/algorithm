#알고스팟(1261)
#bfs를 heapq를 사용해서 구현하면 다익스트라 알고리즘이다.
#bfs를 실행하다가 1을 만날 경우 벽을 빈방 즉 0으로 바꾸고 cnt += 1을 한다.
#while문 초기에 목적지에 도착했는지를 확인하고 도착했으면 cnt를 출력하고 종료한다.
#heapq를 사용하기 때문에 벽을 부수는 회수 cnt가 가장 작은 경우 부터 pop시킨다.
#미로 만들기와 거의 유사한 문제이다.

import heapq
import sys

M, N = map(int, input().split())

board = [[int(x)for x in input()]for _ in range(N)]
visited = [[int(0)for _ in range(M)]for _ in range(N)]

dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]

q = []
heapq.heappush(q, (0, 0, 0))
#cnt, 좌표 순서로 삽입한다.

visited[0][0] = 1

while q:
    cnt, cx, cy = heapq.heappop(q)
    if cx == N - 1 and cy == M - 1:
        print(cnt)
        sys.exit()
    for _ in range(4):
        nx = cx + dx[_]
        ny = cy + dy[_]
        if 0 <= nx < N and 0 <= ny < M:
            if visited[nx][ny] == 0:
                if board[nx][ny] == 0:
                    visited[nx][ny] = 1
                    heapq.heappush(q, (cnt, nx, ny))
                elif board[nx][ny] == 1:
                    visited[nx][ny] = 1
                    heapq.heappush(q, (cnt + 1, nx, ny))
