#숨바꼭질3(13549)
#bfs로 문제를 해결할 수 있다.
#가장 빠른 시간을 찾아야 하기 때문에 deque에 append하는 순서가 중요하다.
#순간이동 즉 시간이 걸리지 않는 경우를 먼저 append한다.
#while문 초기에 현재 위치가 동생의 위치 인지 확인하고 동생을 찾았다면 시간을 출력하고 종료한다.
import collections
import sys

N, K = map(int, input().split())
q = collections.deque()
visited = [0] * 100001

visited[N] = 1
q.append((N, 0))
while q:
    cx, ct = q.popleft()
    if cx == K:
        print(ct)
        sys.exit()
    if 0 <= cx * 2 <= 100000:
        if visited[cx * 2] == 0:
            q.append((cx * 2, ct))
            visited[cx * 2] = 1
    if 0 <= cx - 1 <= 100000:
        if visited[cx - 1] == 0:
            q.append((cx - 1, ct + 1))
            visited[cx - 1] = 1
    if 0 <= cx + 1 <= 100000:
        if visited[cx + 1] == 0:
            q.append((cx + 1, ct + 1))
            visited[cx + 1] = 1

