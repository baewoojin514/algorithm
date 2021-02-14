#가장 긴 증가하는 부분 수열(11053)
#최장 증가 수열은 LIS 알고리즘을 사용하여 구할 수 있다.
#LIS 알고리즘은 binary search로 구현이 가능하다.

import bisect

N = int(input())
info = [int(x) for x in input().split()]
num = []

for i in info:
    idx = bisect.bisect_left(num, i)

    if idx == len(num):
        num.append(i)
    else:
        num[idx] = i

print(len(num))
