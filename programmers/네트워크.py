#네트워크(programmers)
#bfs로 구현 가능하다.
#빙산 문제 처럼 연결된 덩어리의 개수를 구하면 된다.
#입력으로 들어온 컴퓨터의 만큼 visited 1차원 리스트를 만든다.
#입력으로 들어온 2차원 리스트의 index가 0부터 시작하기 때문에 컴퓨터 번호도 0부터 시작이다.
#deque에서 꺼낸 값을 기준으로 computer 리스트에 해당 행에 1이 있으면 그 열의 index를 bfs deque에 추가하면 된다.

import collections


def solution(n, computers):
    answer = 0
    visited = [0] * n

    for i in range(n):
        if visited[i] == 0:
            q = collections.deque()
            visited[i] = 1
            q.append(i)
            while q:
                current = q.popleft()
                for j in range(n):
                    if computers[current][j] and visited[j] == 0:
                        q.append(j)
                        visited[j] = 1
            answer += 1

    return answer
