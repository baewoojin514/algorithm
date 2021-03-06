# 투포인터 알고리즘(Two Pointer algorithm)

|problem|solved(python/c++)|
|---|---|
|[1806](https://www.acmicpc.net/problem/1806)|o/o|
|[2003](https://www.acmicpc.net/problem/2003)|o/o|


- 투 포인터는 1차원 배열에서 두 개의 포인터를 조작해서 원하는 결과를 얻는 알고리즘이다.
- 두 개의 포인터를 사용해서 기존의 방식보다 시간 복잡도를 개선할 수 있다.

## 시간 복잡도(time complexity)

~~~
1. 두 개의 포인터가 1차원 배열 위를 움직인다.
2. end 포인터가 배열의 마지막 index에 도달하면 종료된다.
3. worst case는 start 와 end 포인터 모두 배열의 마지막 index에 도달하는 경우로 시간 복잡도는 O(2*n)이다.
4. 따라서 투 포인터 알고리즘의 시간 복잡도는 O(n)이 된다.
~~~

## algorithm.1 - 수열 중 부분 합이 M인 경우의 수 

~~~
1. N개의 수열 중 부분 합이 M 인 경우의 수를 구한다.
2. start index stx와 end index edx를 0으로 초기화한다.
3. sum 즉 부분 합이 M 이상이면 범위를 좁혀야 할 필요가 있다. 따라서 stx를 하나 증가시킨다.
4. sum 즉 부분 합이 M 미만이면 범위를 넓여야 할 필요가 있다. 따라서 edx를 하나 증가시킨다.
5. sum 즉 부분 합이 M 이면 경우의 수 += 1을 한다.  
~~~

### c++ code

```c
while (edx <= N) {
        if (sum == M) {
            //sum 이 M 과 같다면 result += 1을 한다.
            result += 1;
            edx += 1;
            sum += num[edx];
            sum -= num[stx];
            stx += 1;
        }
        else if (sum > M) {
            //sum이 M 이상이면 범위를 좁혀야 할 필요가 있다 따라서 start를 증가시킨다.
            sum -= num[stx];
            stx += 1;
        }
        else if (sum < M){
            //sum이 M 미만이면 범위를 넓혀야 할 필요가 있다. 따라서 end를 증가시킨다.
            edx += 1;
            sum += num[edx];
        }
    }
```

### python code

```c
for stx in range(N):
    while partSum < M and edx < N:
        partSum += num[edx]
        edx += 1
    if partSum == M:
        result += 1
    partSum -= num[stx]
```


