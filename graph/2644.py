#촌수계산(2644)
#그래프를 bfs방식으로 구현한다.
#visited 리스트의 dest index가 1인지 확인하고 0 이라면 -1을 출력한다.
#while문 초기에 dest인지 확인하고 맞다면 +=1 한 cnt를 출력하고 종료한다.

import sys
import collections

n = int(input())
src, dest = map(int, input().split())
m = int(input())

graph = [[]for _ in range(n)]

for _ in range(m):
    a, b = map(int, input().split())
    graph[a - 1].append(b - 1)
    graph[b - 1].append(a - 1)
src -= 1
dest -= 1

visited = [-1] * n
q = collections.deque()

visited[src] = 0
q.append(src)

while q:
    cx = q.popleft()
    if cx == dest:
        print(visited[dest])
        sys.exit()
    for nx in graph[cx]:
        if visited[nx] == -1:
            visited[nx] = visited[cx] + 1
            q.append(nx)

if visited[dest] == -1:
    print(-1)

