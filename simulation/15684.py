#사다리 조(15684)
#N x H 이차원 리스트를 정의해야 한다.
#dfs재귀 함수로 cnt를 parameter로 넘기고 최대 3개 까지 사다리를 놓을 수 있기 때문에 최대 3까지 가능하다.
#최소값을 cnt가 limit과 동일할 때 까지 갱신하고 INF로 초기값을 설정한다.
#결과 값이 INF이면 -1을 출력하고 아닐 경우 result를 출력한다.

import sys

input = sys.stdin.readline

def check():
    for i in range(N):
        compare = i
        for j in range(H):
            if board[j][compare]:
                compare += 1
            elif board[j][compare - 1]:
                compare -= 1
        if compare != i:
            return 0
    return 1
#행은 index순으로 증가하고 열을 +1 또는 -1하여야 한다.
#사다리 타기의 원리를 정확하게 이해해야 한다.


def ladderBuilder(cnt, idx, limit):
    global result
    if cnt == limit:
        if check():
            result = min(result, cnt)
        return
    for i in range(idx, H):
        for j in range(N - 1):
            #양 옆을 비교하기 위해서 N - 1까지만 확인한다.
            if board[i][j] == 1:
                continue
            elif j - 1 >= 0 and board[i][j - 1] == 1:
                continue
            elif j + 1 < N and board[i][j + 1] == 1:
                continue
            board[i][j] = 1
            ladderBuilder(cnt + 1, i, limit)
            board[i][j] = 0


N, M, H = map(int, input().split())

board = [[int(0)for _ in range(N)]for _ in range(H)]

for _ in range(M):
    X, Y = map(int, input().split())
    board[X - 1][Y - 1] = 1
#사다리를 1로 표현한다.
result = sys.maxsize
#min값으로 갱신하기 위한 최대값이다.
for i in range(4):
    ladderBuilder(0, 0, i)

if result >= 4:
    print(-1)
else:
    print(result)
