# 동적 계획법(DP : Dynamic Programming)

|algorithm|
|---|
|LIS|

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
