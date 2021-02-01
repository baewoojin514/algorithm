#최소 스패닝 트리(1197)
#크루스칼 알고리즘을 사용한다.
#간선 즉 cost를 기준으 정렬 하면서 node의 부모가 같은 경우 즉 cycle을 탐지한다.
#cycle이 형성되지 않을 경우 그 cost를 더해준다.
#두 node를 합쳐주는 함수와 두 node의 부모 노드를 탐색하는 2가지 함수가 필요하다.
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


V, E = map(int, input().split())
edges = []

for i in range(E):
    A, B, C = map(int, input().split())
    temp = [C, A, B]
    edges.append(temp)

parent = [0] * (V + 1)

for i in range(1, V + 1):
    parent[i] = i
edges.sort()
totoal = 0
for edge in edges:
    cost, a, b = edge
    if find_parent(parent, a) != find_parent(parent, b):
        union_find(parent, a, b)
        totoal += cost

print(totoal)
