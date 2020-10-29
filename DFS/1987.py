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

#알파벳(1987) - python3 version
#현재 위치에서 갈 수 있는 지점을 선택하기 위해 사용하는 문자열을 알파벳 리스트로 바꾼다.
#입력으로 들어오는 모든 알파벳은 모두 대문자이기 때문에 정수로 바꿀 수 있다.
#python3에서 시간 초과 문제가 발생했다.
#bfs로 구현해서 시간 초과 문제를 해결해야 한다.

def alphafinder(x, y, canbe):
    global result
    check = False
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < R and 0 <= ny < C:
            if canbe[ord(board[nx][ny])-64] == 0:
                canbe[ord(board[nx][ny]) - 64] = 1
                alphafinder(nx, ny, canbe)
                canbe[ord(board[nx][ny]) - 64] = 0
                check = True
    if not check:
        result = max(result, canbe.count(1))


R, C = map(int, input().split())
board = [[str(x) for x in input()]for _ in range(R)]

dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]

canbe = [0] * 27
result = 0
canbe[ord(board[0][0])-64] = 1
alphafinder(0, 0, canbe)

print(result)

#알파벳(1987) - python3 version
#탐색, 제거, 삽입, 포함여부에 O(1)의 시간 복잡도를 가진 집합 set을 사용해서 시간 복잡도를 해결했다.

R, C = map(int, input().split())
board = [[str(x) for x in input()]for _ in range(R)]

dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]
result = 0

q = set([(0, 0, board[0][0])])
while q:
    cx, cy, canbe = q.pop()
    for i in range(4):
        nx = cx + dx[i]
        ny = cy + dy[i]
        if 0 <= nx < R and 0 <= ny < C:
            if not board[nx][ny] in canbe:
                q.add((nx, ny, canbe + board[nx][ny]))
            result = max(result, len(canbe))
print(result)

