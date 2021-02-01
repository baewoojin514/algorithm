#네트워크 연결(1922)
#크루스칼 알고리즘을 사용하면 된다.
#node의 부모 node를 찾는 함수 그리고 두 node를 하나의 집합으로 묶어주는 함수 2개로 구현 가능하다.
#간선의 cost로 반드시 정렬해야 한다.
def find_parent(parent, X):
    if parent[X] != X:
        parent[X] = find_parent(parent, parent[X])
    return parent[X]

def union_parent(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)
    if a > b:
        parent[a] = b
    else:
        parent[b] = a


N = int(input())
M = int(input())

edges = []
for _ in range(M):
    a, b, c = map(int, input().split())
    edges.append([c, a, b])

parent = [0] * (N + 1)

for i in range(1, N + 1):
    parent[i] = i
edges.sort()
total = 0
for edge in edges:
    cost, a, b = edge
    if find_parent(parent, a) != find_parent(parent, b):
        union_parent(parent, a, b)
        total += cost

print(total)
