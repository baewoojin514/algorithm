#파이프 옮기기1(17070)
#dfs 재귀를 통해 문제를 푼다.
#3종류의 pipe를 0, 1, 2 parameter로 dfs 재귀 함수에 넘긴다.
#각 파이프 마다 갈 수 있는 다음 경로를 미리 다차원 리스트에 정의한다.
#재귀 함수 시작마다 N, N이 파이프로 차 있는지를 확인후 차있다면 count += 1을 한다.
#test case는 통과 하였으나 모든 경우의 수를 다차원 리스트로 처리하니 시간 초과가 발생하였다.

def pipeMover(pipeNum, cx, cy):
    #pipeNum은 현재 파이프의 상태이다.
    global count
    for i in canbe[pipeNum]:
        nx = cx + pipe[i][0]
        ny = cy + pipe[i][1]
        if 0 <= nx < N and 0 <= ny < N:
            if nx == N - 1 and ny == N - 1:
                count += 1
                return
            else:
                if i == 2:
                    if board[nx][ny] == 0 and board[nx][ny - 1] == 0 and board[nx - 1][ny] == 0:
                        pipeMover(2, nx, ny)
                else:
                    if board[nx][ny] == 0:
                        pipeMover(i, nx, ny)


N = int(input())

board = [[int(x)for x in input().split()]for _ in range(N)]

canbe = [[0, 2], [1, 2], [0, 1, 2]]
#각 파이프 마다 다음에 회전 시켜서 움직일 수 있는 파이프의 종류이다.

pipe = [[0, 1], [1, 0], [1, 1]]
#다음에 놓일 파이프가 차지할 다음 공간의 좌표이다.
count = 0

pipeMover(0, 0, 1)
print(count)

#파이프 옮기기1(17070)
#dfs 재귀 방식을 동일하게 사용하나 파라미터 간소화로 시간 복잡도를 줄였다.

def pipeMover(pipeNum, cx, cy):
    #pipeNum은 현재 파이프의 상태이다.
    global count
    if cx == N - 1 and cy == N - 1:
        count += 1
        return
    if pipeNum == 0:
        if 0 <= cx < N and 0 <= cy + 1 < N:
            if board[cx][cy + 1] == 0:
                pipeMover(0, cx, cy + 1)
        if 0 <= cx + 1 < N and 0 <= cy + 1 < N:
            if board[cx + 1][cy + 1] == board[cx + 1][cy] == board[cx][cy + 1] == 0:
                pipeMover(2, cx + 1, cy + 1)
    elif pipeNum == 1:
        if 0 <= cx + 1 < N and 0 <= cy < N:
            if board[cx + 1][cy] == 0:
                pipeMover(1, cx + 1, cy)
        if 0 <= cx + 1 < N and 0 <= cy + 1 < N:
            if board[cx + 1][cy + 1] == board[cx + 1][cy] == board[cx][cy + 1] == 0:
                pipeMover(2, cx + 1, cy + 1)
    elif pipeNum == 2:
        if 0 <= cx < N and 0 <= cy + 1 < N:
            if board[cx][cy + 1] == 0:
                pipeMover(0, cx, cy + 1)
        if 0 <= cx + 1 < N and 0 <= cy < N:
            if board[cx + 1][cy] == 0:
                pipeMover(1, cx + 1, cy)
        if 0 <= cx + 1 < N and 0 <= cy + 1 < N:
            if board[cx + 1][cy + 1] == board[cx + 1][cy] == board[cx][cy + 1] == 0:
                pipeMover(2, cx + 1, cy + 1)


N = int(input())
board = [[int(x)for x in input().split()]for _ in range(N)]
count = 0

pipeMover(0, 0, 1)
#이동할 수 있는 파이프의 경우의 수를 잘 보면 전에 이동하였던 곳으로는 다시 이동할 수 없다.
#따라서 방문 여부를 확인할 필요가 없다.
#함수에 넘기는 파라미터를 최소화 시킨다.

print(count)
