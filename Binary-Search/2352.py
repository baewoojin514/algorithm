#반도체 설계(2352)
#skill.1 - 반도체 선은 꼬일 수 없다. 즉 연결된 port 번호가 증가하는 형태여야 한다.
#skill.2 - port 번호의 최장 증가 수열을 LIS 알고리즘을 통해 구해야 한다.

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
