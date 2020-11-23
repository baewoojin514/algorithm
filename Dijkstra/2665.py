#미로만들기(2665)
#bfs를 heapq를 사용해서 구현하면 다익스트라 알고리즘으로 분류할 수 있다.
#bfs수행중 검은 방이면 cnt + 1을 하고 heapq에 삽입한다.
#하얀 방이면 cnt를 삽입한다.
#while문 초기에 현재 목적지에 도착 했는지를 검사하고 도착하였다면 cnt를 출력하고 프로그램을 종료한다.

import heapq
import sys

n = int(input())
board = [[int(x) for x in input()]for _ in range(n)]
visited = [[int(0)for _ in range(n)]for _ in range(n)]

dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]

q = []
heapq.heappush(q, (0, 0, 0))
#q에는 cnt, cx, cy순으로 정보가 담겨있다.
visited[0][0] = 1

while q:
    cnt, cx, cy = heapq.heappop(q)
    if cx == n - 1 and cy == n - 1:
        print(cnt)
        sys.exit()
    for _ in range(4):
        nx = cx + dx[_]
        ny = cy + dy[_]
        if 0 <= nx < n and 0 <= ny < n:
            if visited[nx][ny] == 0:
                if board[nx][ny] == 0:
                    board[nx][ny] = 1
                    #검은 방이면 흰 방으로 바꾸어 준다.
                    visited[nx][ny] = 1
                    heapq.heappush(q, (cnt + 1, nx, ny))
                elif board[nx][ny] == 1:
                    visited[nx][ny] = 1
                    heapq.heappush(q, (cnt, nx, ny))

