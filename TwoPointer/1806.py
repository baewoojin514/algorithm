#부분합(1806)
#수들의 합2 와 유사한 문제이다.
#skill.1 - 2003문제와 비슷한 문제이지만 부분 합이 S 이상인 경우 stx - edx + 1로 최소값을 갱신한다.
#skill.2 - result가 초기화된 값인 INF인 경우 0을 출력하고 아니면 result를 그대로 출력한다.
import sys

input = sys.stdin.readline

N, S = map(int, input().split())
num = [int(x) for x in input().split()]

edx = 0
partSum = 0

result = 1e9

for stx in range(N):
    while partSum < S and edx < N:
        partSum += num[edx]
        edx += 1
    if partSum >= S:
        result = min(result, edx - stx)

    partSum -= num[stx]
if result == 1e9:
    result = 0
print(result)
