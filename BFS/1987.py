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
