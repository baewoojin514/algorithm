#전력난(6497)
#MST 알고리즘으로 해결 가능하다.
#skill.1 - 간선 정보를 입력 받으며 모든 cost를 더한다.
#skill.2 - MST의 cost를 더하고 1에서 계산된 cost에서 차감한다.

import sys
input = sys.stdin.readline


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


while True:
    m, n = map(int, input().split())
    if m == 0 and n == 0:
        break
    edges = []

    totalCost = 0
    for _ in range(n):
        a, b, c = map(int, input().split())
        totalCost += c
        edges.append([c, a, b])

    parent = [0] * (m + 1)
    for i in range(m + 1):
        parent[i] = i

    edges.sort()
    total = 0
    for edge in edges:
        c = edge[0]
        a = edge[1]
        b = edge[2]
        if find_parent(parent, a) != find_parent(parent, b):
            union_find(parent, a, b)
            total += c

    print(totalCost - total)
