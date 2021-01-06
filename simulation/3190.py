#(3190)
#시뮬레이션 문제이다.
#뱀을 deque로 구현한다.
#다음칸에 사과가 있다면 꼬리는 움직이지 않는다.
#다음칸에 사과가 없다면 꼬리를 움직인다. 즉 꼬리가 있던 칸을 popleft를 통해 비워준다.
#다음 이동할 칸이 이차원 list 범위를 넘어가거나 뱀의 몸체일 경우 시간을 출력하고 종료한다.

#뱀은 S 땅은 L 사과는 A로 구분한다.
import collections
import sys


def change(dir, num):
    if dir == 'D':
        num = (num + 1) % 4
    elif dir == 'L':
        num = (num - 1) % 4
    return num


N = int(input())

board = [[str('L') for _ in range(N)]for _ in range(N)]
board[0][0] = 'S'
K = int(input())

for _ in range(K):
    A, B = map(int, input().split())
    board[A - 1][B - 1] = 'A'

L = int(input())
direction = []
for _ in range(L):
    X, C = input().split()
    direction.append([X, C])

snake = collections.deque()
move = [[0, 1], [1, 0], [0, -1], [-1, 0]]
#방향은 오른쪽, 아래, 왼쪽, 위 순서이다.

snake.append((0, 0, 0))

totalTime = 0
while snake:
    totalTime += 1
    cx, cy, cdir = snake.pop()
    nx = cx + move[cdir][0]
    ny = cy + move[cdir][1]
    snake.append((cx, cy, cdir))
    if 0 <= nx < N and 0 <= ny < N:
        if board[nx][ny] == 'L':
            snake.append((nx, ny, cdir))
            board[nx][ny] = 'S'
            ox, oy, odir = snake.popleft()
            board[ox][oy] = 'L'
        elif board[nx][ny] == 'A':
            snake.append((nx, ny, cdir))
            board[nx][ny] = 'S'
        elif board[nx][ny] == 'S':
            print(totalTime)
            sys.exit()
        for info in direction:
            if int(info[0]) == totalTime:
                dirInfo = info[1]
                newDir = change(dirInfo, cdir)
                newInfo1, newInfo2, newInfo3 = snake.pop()
                snake.append((newInfo1, newInfo2, newDir))
    else:
        print(totalTime)
        sys.exit()
