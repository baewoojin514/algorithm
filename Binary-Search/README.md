# Binary-Search

|algorithm|
|---|
|LIS|

|problem|solved(python/c++)|
|---|---|
|[13397](https://www.acmicpc.net/problem/13397)|v/o|
|[1654](https://www.acmicpc.net/problem/1654)|v/v|
|[2470](https://www.acmicpc.net/problem/2470)|v/v|
|[1300](https://www.acmicpc.net/problem/1300)|v/v|


### algorithm.1 - LIS(최장 증가 부분 수열 : Longest Increasing Subsequence)

- 원소가 n개인 배열의 일부 원소를 골라내서 만든 부분 수열 중, 각 원소가 이전 원소보다 크다는 조건을 만족하고, 그 길이가 최대인 부분 수열을 최장 증가 부분 수열이라고 한다.

#### c++ code

```c
int main(void){
    cin >> N;
    
    int a;
    for (int i = 0; i < N; i++) {
        cin >> a;
        
        int idx = lower_bound(num.begin(), num.end(), a) - num.begin();
        
        if (idx == num.size()) {
            num.push_back(a);
        }//vector의 후방에 숫자를 삽입한다.
        else{
            num[idx] = a;
        }//vector의 알맞은 위치에 숫자를 삽입한다.
    }
    
    cout << num.size();
    return 0;
}
```

~~~
if (idx == num.size()) {
    num.push_back(a);
}
숫자가 삽입되어야 할 위치가 vector의 후방이라면 push_back을 통해 삽입한다.

else{
    num[idx] = a;
}
숫자가 삽입되어야 할 위치가 vector의 중간이라면 해당 위치의 요소를 바꿔준다.

~~~

#### python code

```c
for i in info:
    idx = bisect.bisect_left(num, i)

    if idx == len(num):
        num.append(i)
    else:
        num[idx] = i
}
```
~~~
if idx == len(num):
    num.append(i)
숫자가 삽입되어야 할 위치가 list의 후방이라면 append을 통해 삽입한다.

else:
    num[idx] = i
숫자가 삽입되어야 할 위치가 list의 중간이라면 해당 위치의 요소를 바꿔준다.

~~~
