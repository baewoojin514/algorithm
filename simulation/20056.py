#마법사 상어와 파이어볼(20056)
#시뮬레이션 문
#질량,속력,방향 순서
#원형 큐 처럼 행과 열이 연결 되어 있다 => mod연산 사용!!
#fireball의 정보들을 저장한 degue로 1, 2단계를 모두 해결 한다.
#한 격자에 2개 이상의 fireball이 존재하는 경우를 위해서 질량, 방향, 속력을 2차원 리스트로 만들고 값들을
#순차적으로 더해준다.
#count가 2이상인 경우 모든 방향이 짝수 또는 홀수인 경우를 따져서 fireball deque에 저장한다.

import collections
import sys

N, M, K = map(int, input().split())

fireball = collections.deque()
for _ in range(M):
    a, b, c, d, e = map(int, input().split())
    fireball.append((a - 1, b - 1, c, d, e))
dx = [-1, -1, 0, 1, 1, 1, 0, -1]
dy = [0, 1, 1, 1, 0, -1, -1, -1]
time = 0
while True:
    time += 1
    count = [[int(0) for _ in range(N)]for _ in range(N)]
    weight = [[int(0) for _ in range(N)]for _ in range(N)]
    velocity = [[int(0) for _ in range(N)]for _ in range(N)]
    even = [[int(0) for _ in range(N)]for _ in range(N)]
    odd = [[int(0) for _ in range(N)] for _ in range(N)]
    direction = [[int(0) for _ in range(N)] for _ in range(N)]

    iter = len(fireball)
    for i in range(iter):
        info = fireball.popleft()
        cx, cy = info[0], info[1]
        m, v, d = info[2], info[3], info[4]
        if m > 0:
            nx = (cx + (dx[d] * v)) % N
            ny = (cy + (dy[d] * v)) % N
            count[nx][ny] += 1
            weight[nx][ny] += m
            velocity[nx][ny] += v
            direction[nx][ny] += d
            if d % 2 == 0:
                even[nx][ny] += 1
            else:
                odd[nx][ny] += 1
    for i in range(N):
        for j in range(N):
            if 1 <= count[i][j] < 2:
                fireball.append((i, j, weight[i][j], velocity[i][j], direction[i][j]))
            elif count[i][j] >= 2:
                if weight[i][j] // 5 > 0:
                    if even[i][j] == count[i][j] or odd[i][j] == count[i][j]:
                        fireball.append((i, j, weight[i][j] // 5, velocity[i][j] // count[i][j], 0))
                        fireball.append((i, j, weight[i][j] // 5, velocity[i][j] // count[i][j], 2))
                        fireball.append((i, j, weight[i][j] // 5, velocity[i][j] // count[i][j], 4))
                        fireball.append((i, j, weight[i][j] // 5, velocity[i][j] // count[i][j], 6))
                    else:
                        fireball.append((i, j, weight[i][j] // 5, velocity[i][j] // count[i][j], 1))
                        fireball.append((i, j, weight[i][j] // 5, velocity[i][j] // count[i][j], 3))
                        fireball.append((i, j, weight[i][j] // 5, velocity[i][j] // count[i][j], 5))
                        fireball.append((i, j, weight[i][j] // 5, velocity[i][j] // count[i][j], 7))
    sum = 0
    if time == K:
        for i in fireball:
            sum += i[2]
        print(sum)
        sys.exit()
