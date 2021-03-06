# 위상정렬(Topological Sorting)

|problem|solved(python/c++)|
|---|---|
|[14567](https://www.acmicpc.net/problem/14567)|o/o|
|[2252](https://www.acmicpc.net/problem/2252)|v/v|
|[1766](https://www.acmicpc.net/problem/1766)|o/o|
|[1005](https://www.acmicpc.net/problem/1005)|v/v|
|[2623](https://www.acmicpc.net/problem/2623)|v/v|

## 위상정렬

 - 위상정렬은 순서가 정해져있는 작업을 차례로 수행해야 할 때 그 순서를 결정해주기 위해 사용하는 알고리즘이다.
 - 위상정렬은 여러개의 답이 존재할 수 있다.
 - 사이클이 발생하지 않는 방향 그래프(DAG : Directed Acyclic Graph)에만 적용 가능하다. 
 - 알고리즘 동작순서
 ~~~
 1. 진입차수가 0인 노드를 queue에 삽입한다.
 2. queue에서 노드를 꺼내 연결된 간선을 제거한다.
 3. 간선 제거 후 진입차수(indegree)가 0이 된 정점을 queue에 삽입한다.
 4. queue가 빌 때까지 2 ~ 3의 과정을 반복한다.
 ~~~
 
 - 예외상황(execption)
 ~~~
 1. 모든 노드를 방문하기 전에 queue가 empty하다면 cycle이 존재하는 것이다.
 2. queue에 두개 이상의 노드가 담기면 즉 한번에 indegree가 0인 노드가 여러개 발생하면 위상정렬의 결과가 애매해진다.
 ~~~ 
 
 ### python code
 
 ```c
 import collections

N, M = map(int, input().split())

indegree = [0] * (N + 1)

graph = [[] for i in range(N + 1)]
for i in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)
    indegree[b] += 1


result = []
q = collections.deque()

for i in range(1, N + 1):
    if indegree[i] == 0:
        q.append(i)
while q:
    now = q.popleft()
    result.append(now)

    for j in graph[now]:
        indegree[j] -= 1
        if indegree[j] == 0:
            q.append(j)

for i in result:
    print(i, end=' ')
```

### c++ code

```c
while (!q.empty()) {
    int cx;
    cx = q.front();
        
    q.pop_front();
        
    for (int i = 0; i < graph[cx].size(); i++) {
        indegree[graph[cx][i]] -= 1;
        if (indegree[graph[cx][i]] == 0) {
            q.push_back(graph[cx][i]);
        }
    }
}
```
