#녹색 옷 입은 애가 젤다지?(4485)
#bfs로 해결 가능하다.
#skill.1 - 루피가 최소가 되게 이동해야 한다. 즉 이동한 좌표의 요소값이 최소가 되게 이동해야 한다.
#skill.2 - heapq를 사용해서 다익스트라 알고리즘으로 해결할 수 있다.
#skill.3 - [N - 1][N - 1]에 도착하면 이동하면서 잃은 루피의 총합을 출력한다.

import heapq
import sys

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
testcase = 1

while True:
    N = int(input())

    if N == 0:
        sys.exit()
    board = [[int(x) for x in input().split()]for _ in range(N)]
    visited = [[int(0) for _ in range(N)]for _ in range(N)]
    q = []
    heapq.heappush(q, (board[0][0], 0, 0))
    #rupee, x, y 순으로 저장한다.
    visited[0][0] = 1

    while q:
        rupee, cx, cy = heapq.heappop(q)
        if cx == N - 1 and cy == N - 1:
            print("Problem " + str(testcase) + ": " + str(rupee))
            testcase += 1
        for _ in range(4):
            nx = cx + dx[_]
            ny = cy + dy[_]
            if 0 <= nx < N and 0 <= ny < N:
                if visited[nx][ny] == 0:
                    visited[nx][ny] = 1
                    heapq.heappush(q, (rupee + board[nx][ny], nx, ny))
