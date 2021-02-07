#가장 큰 정사각형(1915)
#dp문제이다.
#1 ~ n - 1, 1 ~ m - 1 까지의 행과 열에 대해 (i, j - 1), (i - 1, j - 1), (i - 1, j)의 요소를 확인해야 한다.
#skill.1 - (i, j - 1), (i - 1, j - 1), (i - 1, j)의 최소값을 (i, j)에 더한다.
#skill.2 - 하나라도 0이면 즉 정사각형을 만들 수 없다면 값은 그대로이다.
#skill.3 - dp 이차원 리스트의 최대값을 제곱하면 된다.

n, m = map(int, input().split())
board = [[int(x) for x in input()]for _ in range(n)]

for i in range(1, n):
    for j in range(1, m):
        if board[i][j]:
            #i, j의 요소가 1이상 이어야 정사각형을 만들 수 있다.
            board[i][j] = min(board[i][j - 1], board[i - 1][j - 1], board[i - 1][j]) + 1

maxValue = 0

for i in range(n):
    for j in range(m):
        maxValue = max(maxValue, board[i][j])

print(maxValue**2)
