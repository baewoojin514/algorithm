# 최소 신장 트리(MST, minimum spanning tree)

|algorithm|
|---|
|kruskal|

|problem|solved(python/c++)|
|---|---|
|[1368](https://www.acmicpc.net/problem/1368)|v/o|
|[16398](https://www.acmicpc.net/problem/16398)|v/o|
|[14621](https://www.acmicpc.net/problem/14621)|v/o|
|[4386](https://www.acmicpc.net/problem/4386)|v/o|
|[13905](https://www.acmicpc.net/problem/13905)|v/o|
|[13418](https://www.acmicpc.net/problem/13418)|v/o|
|[17490](https://www.acmicpc.net/problem/17490)|v/o|
|[2406](https://www.acmicpc.net/problem/2406)|v/v|

## 신장트리(spanning tree)
- 신장 트리란 하나의 그래프가 있을 때 모든 노드를 포함하면서 사이클이 존재하지 않는 부분 그래프를 의미한다.

## 크루스칼 알고리즘(kruskal algorithm)
- 가능한 한 최소의 비용으로 신장 트리를 찾아야 할 때가 있다.
- 최소 비용으로 만들 수 있는 신장 트리를 찾는 알고리즘을 최소 신장 트리 알고리즘이라고 한다.

~~~
 1.간선 데이터를 비용에 따라 오름차순으로 정렬한다.
 2.간선을 하나씩 확인하며 현재의 간선이 사이클을 발생시키는지 확인한다.
  - 사이클이 발생하지 않는 경우 최소 신장 트리에 포함시킨다.
  - 사이클이 발생하는 경우 최소 신장 트리에 포함시키지 않는다.
 3.모든 간선에 대하여 2번의 과정을 반복한다.
~~~

- c++ code
~~~
int find_parent(int X){
    if (parent[X] != X) {
        parent[X] = find_parent(parent[X]);
    }
    return parent[X];
}

void union_find(int a, int b){
    a = find_parent(a);
    b = find_parent(b);
    
    if (a > b) {
        parent[a] = b;
    }
    else{
        parent[b] = a;
    }
    return;
}
~~~

- python code
~~~
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
~~~
