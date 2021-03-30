# 동적 계획법(DP : Dynamic Programming)

|algorithm|
|---|
|LIS|

|problem|solved(python/c++)|
|---|---|
|[4095](https://www.acmicpc.net/problem/4095)|v/o|
|[9251](https://www.acmicpc.net/problem/9251)|v/v|
|[5557](https://www.acmicpc.net/problem/5557)|v/v|
|[2631](https://www.acmicpc.net/problem/2631)|v/v|
|[2228](https://www.acmicpc.net/problem/2228)|v/v|
|[2758](https://www.acmicpc.net/problem/2758)|v/v|
|[17485](https://www.acmicpc.net/problem/17485)|v/v|
|[15724](https://www.acmicpc.net/problem/15724)|v/v|
|[2073](https://www.acmicpc.net/problem/2073)|v/v|
|[18427](https://www.acmicpc.net/problem/18427)|v/v|
|[11049](https://www.acmicpc.net/problem/11049)|v/v|
|[14728](https://www.acmicpc.net/problem/14728)|v/v|
|[17845](https://www.acmicpc.net/problem/17845)|v/v|
|[14226](https://www.acmicpc.net/problem/14226)|v/v|
|[5582](https://www.acmicpc.net/problem/5582)|v/v|
|[2229](https://www.acmicpc.net/problem/2229)|v/v|
|[14925](https://www.acmicpc.net/problem/14925)|v/o|

## 동적 계획법

- 전체 문제를 작은 문제로 단순화한 다음 점화식으로 만들어 재귀적인 구조로 활용해서 전체 문제를 해결하는 방식이다.

~~~
1. 전체 문제를 작은 문제로 단순화한다. -> 부분 문제를 정의한다.
2. 재귀적인 구조를 활용할 수 있는 점화식을 만든다. -> 점화식을 만든다.
3. 작은 문제를 해결한 방법으로 전체 문제를 해결한다. -> 문제를 해결한다.
~~~

### algorithm.1 - LIS(최장 증가 부분 수열 : Longest Increasing Subsequence)

- 원소가 n개인 배열의 일부 원소를 골라내서 만든 부분 수열 중, 각 원소가 이전 원소보다 크다는 조건을 만족하고, 그 길이가 최대인 부분 수열을 최장 증가 부분 수열이라고 한다.
- DP로 LIS algorithm을 구현할 시 O(n^2)의 시간복잡도가 발생한다, 하지만 [Binary-Search](https://github.com/baewoojin514/algorithm/tree/master/Binary-Search)로 구현시 O(n*logn)의 시간 복잡도가 발생해 훨씬 효율적이다.

#### c++ code

```c
for (int i = 0; i < N; i++) {
        DP[i] = 1;
        for (int j = 0; j < i; j++) {
            if (num[j] < num[i]) {
                DP[i] = max(DP[i], DP[j] + 1);
            }
        }
    }
```
