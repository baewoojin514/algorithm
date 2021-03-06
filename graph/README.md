# 그래프(graph)

|algorithm|
|---|
|[MST](https://github.com/baewoojin514/algorithm/tree/master/MST)|
|[topology sort](https://github.com/baewoojin514/algorithm/tree/master/MST)|

|problem|solved(python/c++)|
|---|---|
|[14442](https://www.acmicpc.net/problem/14442)|v/v|
|[10711](https://www.acmicpc.net/problem/10711)|v/v|
|[17616](https://www.acmicpc.net/problem/17616)|v/v|

## 위상정렬(Topology sort)

- 위상 정렬은 순서가 정해져 있는 일련의 작업을 차례대로 수행해야 할 때 사용할 수 있는 알고리즘이다.
- 방향 그래프의 모든 노드를 '방향성에 거스르지 않도록 순서대로 나열하는 것'이다.

- 예시(선수과목에 기반한 학습 순서 설정)
~~~
1. 소프트웨어학과 커리큘럼에는 '자료구조' 과목을 수강한 뒤에 '알고리즘' 강의를 수강하는 것을 권장한다.
2. '자료구조' 및 '알고리즘'을 각각의 노드로 표현하고, '자료구조' 에서 '알고리즘'으로 이어질 수 있도록 방향성을 간선을 그릴 수 있다.
~~~

### 진입차수(degree)

- 진입차수란 특정한 노드로 들어오는 간선의 개수를 의미한다.
- 진입차수를 사용한 위상정렬 알고리즘의 순서
~~~
1. 진입차수가 0노드를 큐에 넣는다.
2. 큐가 빌 때까지 다음의 과정을 반복한다.
 - 큐에서 원소를 꺼내 해당 노드에서 출발하는 간선을 그래프에서 제거한다.
 - 샤롭게 진입차수가 0이된 노드를 큐에 넣는다.
~~~

## c++ code
