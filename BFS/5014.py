#스타트링크(5014)
#bfs로 구현 가능한 문제이다.
#deque에서 pop시킨 현재 위치에서 위층으로 간 경우 그리고 아래층으로 간 경우 두 경우를 다시 deque에 넣는다.
#while문 처음에 현재 층이 목표 층인지 확인 후 맞다면 최소값을 갱신 시킨다.
#시뮬레이션 에서 dx dy 리스트를 사용하는 것처럼 최고층과 최저층 조건을 잘 설정해야 한다.
#어느 순간 더이상 이동할 수 없는 경우가 나올 것임으로 deque가 empty 상태로 되기 전까지 수행한다.
#deque에 현재 층과 버튼을 누른 회수를 저장한다.
#무한 루프에 걸리지 않도록 아파트의 최고층수를 사용해서 visited 1차원 리스트를 사용한다.

import collections

F, S, G, U, D = map(int, input().split())

q = collections.deque()
q.append((S, 0))
result = []
visited = [0] * (F + 1)

while q:
    floor, num = q.popleft()
    if floor == G:
        result.append(num)
    if floor + U >= 1 and floor + U <= F:
        if not visited[floor + U]:
            q.append((floor + U, num + 1))
            visited[floor + U] = 1
    if floor - D >= 1 and floor - D <= F:
        if not visited[floor - D]:
            q.append((floor - D, num + 1))
            visited[floor - D] = 1

if not result:
    print('use the stairs')
else:
    print(min(result))
