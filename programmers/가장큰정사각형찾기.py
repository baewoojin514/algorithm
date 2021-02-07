#가장 큰 정사각형(programmers)
#dp문제이다.
#1 ~ row - 1, 1 ~ column - 1 까지의 행과 열에 대해 (i, j - 1), (i - 1, j - 1), (i - 1, j)의 요소를 확인해야 한다.
#skill.1 - (i, j - 1), (i - 1, j - 1), (i - 1, j)의 최소값을 (i, j)에 더한다.
#skill.2 - 하나라도 0이면 즉 정사각형을 만들 수 없다면 값은 그대로이다.
#skill.3 - dp 이차원 리스트의 최대값을 제곱하면 된다.
#skill.4 - board의 최대값을 구하고 제곱을 하여 반환한다.

def solution(board):
    answer = 0
    for i in range(1, len(board)):
        for j in range(1, len(board[0])):
            if board[i][j]:
                board[i][j] = min(board[i - 1][j], board[i - 1][j - 1], board[i][j - 1]) + 1

    for i in range(len(board)):
        for j in range(len(board[0])):
            answer = max(answer, board[i][j])

    return answer**2
