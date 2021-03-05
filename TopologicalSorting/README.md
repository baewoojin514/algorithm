# 위상정렬(Topological Sorting)

|problem|
|---|
|[14567](https://www.acmicpc.net/problem/14567)|

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
