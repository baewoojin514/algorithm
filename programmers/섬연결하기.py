#섬 연결하기(programmers)
#MST를 위해 크루스칼 알고리즘을 사용한다.
#MST는 기본적으로 greedy 알고리즘이다.


def find_parent(parent, X):
    if parent[X] != X:
        parent[X] = find_parent(parent, parent[X])
    return parent[X]


def union_find(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)
    if a > b:
        parent[a] = b
    else:
        parent[b] = a


def solution(n, costs):
    edges = []
    parent = [0] * (n + 1)
    for info in costs:
        edges.append([info[2], info[0], info[1]])
    for i in range(1, n + 1):
        parent[i] = i

    edges.sort()
    answer = 0

    for edge in edges:
        cost, a, b = edge
        if find_parent(parent, a) != find_parent(parent, b):
            union_find(parent, a, b)
            answer += cost

    return answer
