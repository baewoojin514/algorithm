#중제한(1939)
#정보들을 입력 받음과 동시에 중량의 max와 min값을 갱신한다.
#max부터 min 사이의 범위로 다리들을 모두 건너 출발지로 부터 목적지로 갈 수 있는지를 검사한다.
#graph를 bfs방식으로 접근해서 문제를 해결한다.
#단순 완전탐색으로 구현하니 시간초과가 발생했다.
#이분 탐색을 사용하여 해결하여야 한다.
#이분 탐색의 범위는 minValue 부터 maxValue 까지이다.

import collections

N, M = map(int, input().split())

graph = [[]for _ in range(N)]

maxValue = 0
minValue = 1000000001
result = 0

for _ in range(M):
    A, B, C = map(int, input().split())
    graph[A - 1].append([B - 1, C])
    graph[B - 1].append([A - 1, C])
    maxValue = max(maxValue, C)
    minValue = min(minValue, C)

src, dest = map(int, input().split())

src -= 1
dest -= 1

for weight in range(minValue, maxValue + 1):
    visited = [0] * N
    visited[src] = 1
    q = collections.deque()
    q.append(src)
    while q:
        cx = q.popleft()
        for nx, nw in graph[cx]:
            if visited[nx] == 0 and nw >= weight:
                visited[nx] = 1
                q.append(nx)
    if visited[dest] == 1:
        result = max(result, weight)

print(result)

#중제한(1939)
#정보들을 입력 받음과 동시에 중량의 max와 min값을 갱신한다.
#max부터 min 사이의 범위로 다리들을 모두 건너 출발지로 부터 목적지로 갈 수 있는지를 검사한다.
#graph를 bfs방식으로 접근해서 문제를 해결한다.
#단순 완전탐색으로 구현하니 시간초과가 발생했다.
#이분 탐색을 사용하여 해결하여야 한다.
#이분 탐색의 범위는 minValue 부터 maxValue 까지이다.
#이분 탐색으로 pypy3로 컴파일할 경우 시간초과 문제가 발생하지 않았다.

import collections

def binarySearch(weight):
    visited = [0] * N
    visited[src] = 1
    q = collections.deque()
    q.append(src)
    while q:
        cx = q.popleft()
        for nx, nw in graph[cx]:
            if visited[nx] == 0 and nw >= weight:
                visited[nx] = 1
                q.append(nx)
    if visited[dest] == 1:
        return 1
    return 0


N, M = map(int, input().split())

graph = [[]for _ in range(N)]

maxValue = 0
minValue = 1000000001
result = 0

for _ in range(M):
    A, B, C = map(int, input().split())
    graph[A - 1].append([B - 1, C])
    graph[B - 1].append([A - 1, C])
    maxValue = max(maxValue, C)
    minValue = min(minValue, C)

src, dest = map(int, input().split())

src -= 1
dest -= 1

while minValue <= maxValue:
    mid = (minValue + maxValue) // 2
    if binarySearch(mid):
        result = max(result, mid)
        minValue = mid + 1
    else:
        maxValue = mid - 1

print(result)
