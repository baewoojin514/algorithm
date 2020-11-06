#이분 그래프(1707)
#이분 그래프는 노드가 2 그룹으로 나뉠 수 있고 같은 그룹에 속한 노드들은 서로 연결되어 있지 않은 그래프를 의미한다.
#visited list와 노드에 입힐 색을 구분하는 color list를
#skill.1 - 인접한 node 끼리는 같은 색을 가질 수 없다.
#skill.2 - 인접한 node가 동일한 색을 가졌다면 이분 그래프가 아니다.
#skill.3 - node의 색은 1, 2로 구분한다.

import collections
import sys
input = sys.stdin.readline

K = int(input())

for _ in range(K):
    V, E = map(int, input().split())
    graph = [[]for _ in range(V + 1)]

    for _ in range(E):
        a, b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)
    visited = [0] * (V + 1)
    color = [0] * (V + 1)
    q = collections.deque()

    check = True
    for i in range(1, V + 1):
        if visited[i] == 0:
            visited[i] = 1
            color[i] = 1
            q.append(i)
            while q:
                cx = q.popleft()
                for nx in graph[cx]:
                    if visited[nx] == 0:
                        visited[nx] = 1
                        q.append(nx)
                        color[nx] = 3 - color[cx]
                    else:
                        if color[nx] == color[cx]:
                            check = False

    print("YES" if check else "NO")
