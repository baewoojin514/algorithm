#아기상어(16236)
#시뮬레이션 문제이다.
#상어의 현재 위치에서 bfs방식으로 탐색을 하고 현재 자신의 크기보다 작은 물고기들을 eat리스트에 담는다.
#담긴 물고기가 여러개라면 행, 열을 기준으로 정렬한다.
#먹은 물고기의 개수가 현재의 크기와 같아 지면 크기를 1증가 시키고 먹은 물고기의 개수를 0으로 초기화 한다.
#함수를 사용하지 않고 while문 하나로 문제를 해결한다.
#먹을 수 있는 물고기와 걸리는 시간을 찾는 방식을 스타트 택시와 유사하게 구현하였다.

import collections

N = int(input())

fish = [[int(x)for x in input().split()]for _ in range(N)]
visited = [[int(0)for _ in range(N)]for _ in range(N)]
shark = collections.deque()

for i in range(N):
    for j in range(N):
        if fish[i][j] == 9:
            shark.append((i, j, 0))
totalTime = 0
fishsize = 2
tempEat = 0

visited[shark[0][0]][shark[0][1]] = 1
fish[shark[0][0]][shark[0][1]] = 0

dx = [-1, 0, 1, 0]
dy = [0, -1, 0, 1]
while shark:
    eat = []
    for _ in range(len(shark)):
        cx, cy, ct = shark.popleft()
        for i in range(4):
            nx = cx + dx[i]
            ny = cy + dy[i]
            if 0 <= nx < N and 0 <= ny < N:
                if visited[nx][ny] == 0:
                    if 0 < fish[nx][ny] < fishsize:
                        eat.append([nx, ny, ct + 1])
                        visited[nx][ny] = 1
                        #물고기가 있고 상어의 크기보다 작다면 eat list에 넣는다.
                    elif fish[nx][ny] == 0 or fish[nx][ny] == fishsize:
                        shark.append((nx, ny, ct + 1))
                        visited[nx][ny] = 1
                        #빈칸이거나 상어와 같은 크기의 물고기의 경우 이동할 수 있다.
    if eat:
        nsx, nsy, nt = min(eat)
        tempEat += 1
        if tempEat == fishsize:
            fishsize += 1
            tempEat = 0
        fish[nsx][nsy] = 0
        shark.clear()
        #deque를 반드시 초기화 한다.
        shark.append((nsx, nsy, 0))
        totalTime += nt
        visited = [[int(0) for _ in range(N)] for _ in range(N)]
        visited[nsx][nsy] = 1

print(totalTime)
