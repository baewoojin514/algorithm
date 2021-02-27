#동굴 탐험(programmers)
#bfs를 통해 해결할 수 있다.
#order 즉 선.후 행 관계를 afer, before로 관리한다.

from collections import deque


def solution(n, path, order):
    graph = [[] for _ in range(n)]
    visited = [0] * n
    answer = True
    for info in path:
        graph[info[0]].append(info[1])
        graph[info[1]].append(info[0])

    before = [-1] * n
    #index node 전에 반드시 방문해야 하는 node를 요소로 저장한다.
    after = [-1] * n
    #index node 후에 반드시 방문해야 하는 node를 요소로 저장한다.

    for info in order:
        after[info[0]] = info[1]
        before[info[1]] = info[0]
    if before[0] != -1:
        answer = False
    #0은 시작 노드로 절대 before 노드가 존재할 수 없다.

    temp = set()

    visited[0] = 1
    q = deque()
    q.append(0)
    #시작점은 늘 0이다.

    while q:
        cx = q.popleft()

        if after[cx] != -1:
            before[after[cx]] = -1

        if after[cx] in temp:
            temp.remove(after[cx])
            q.append(after[cx])
            visited[after[cx]] = 1
        #만약 현재 노드에서 가야할 노드가 before 노드를 방문하지 않아 대기 집합에 있다면 deque에 넣어준다.

        for i in graph[cx]:
            if visited[i] == 1:
                continue
            #효울성을 위해 이미 방문한 노드이면 넘어간다.
            if before[i] != -1:
                temp.add(i)
            #before 노드가 존재한다면 deque에 넣지 않고 대기 집합에 삽입한다.
            else:
                q.append(i)
                visited[int(i)] = 1

    for i in range(n):
        if visited[i] == 0:
            answer = False
            break

    return answer
