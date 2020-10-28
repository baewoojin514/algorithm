#삼각달팽이(programmers)
#주어진 n으로 n x n 이차원 리스트를 만든다.
#이중 for 문으로 모든 행위 첫번째 요소를 각각 1 ~ n로 만든다.
#시작점은 n-1, 0에서 가능한 3가지 방향 (0, 1) (-1, -1), (1, 0)으로 바꿔 가며 이전의 값에 1씩 더해준다.
#한 방향으로 반복해야 할 dfs회수는 1씩 줄어든다.
#굳이 dfs 재귀 함수를 사용하지 않아도 단순 for 문으로 알맞은 값을 채울 수 있다.
#방향을 변환시 (현재 방향 + 1) % 3 연산을 사용할 수 있다.
#시작점만 잘 변환시켜 주면 문제 없이 구현 가능하다.

dx = [0, -1, 1]
dy = [1, -1, 0]


def solution(n):
    answer = []
    for i in range(n):
        answer.append([0] * (i + 1))
    for i in range(n):
        answer[i][0] = i + 1
    stx = n - 1
    sty = 0
    direction = 0
    for i in range(n - 1, 0, -1):
        cx, cy = stx, sty
        rsx, rsy = stx, sty
        for _ in range(i):
            nx = cx + dx[direction]
            ny = cy + dy[direction]
            answer[nx][ny] = answer[cx][cy] + 1
            cx = nx
            cy = ny
        stx = rsx + i * dx[direction]
        sty = rsy + i * dy[direction]
        direction = (direction + 1) % 3
    result = []
    for i in range(n):
        for j in range(len(answer[i])):
            result.append(answer[i][j])

    return result
