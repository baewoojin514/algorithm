#알파벳(1987)
#dfs 재귀로 문제를 해결할 수 있다.
#말이 이동할 수 있는 거리의 최대값을 저장한 전역 변수로 선언한다.
#말이 더이상 이동할 수 없는 경우 현재까지 온 거리가 가능한 최대값이기 때문에 최대값을 갱신한다.
#pypy3로 통과 했지만 알파벳을 int형으로 변환해서 visited 리스트 처럼 사용하면 시간 복잡도가 개선될 것으로 보인다.

def alphafinder(X, Y, canbe):
    global result
    check = 0
    for i in range(4):
        nx, ny = X + dx[i], Y + dy[i]
        if 0 <= nx < R and 0 <= ny < C and not board[nx][ny] in canbe:
            alphafinder(nx, ny, canbe + board[nx][ny])
        else:
            check += 1
    if check == 4:
        result = max(result, len(canbe))
        return


R, C = map(int, input().split())
board = [[str(x) for x in input()]for _ in range(R)]

dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]

result = 0
alphafinder(0, 0, board[0][0])

print(result)
