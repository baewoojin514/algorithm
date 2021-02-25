#수들의 합2(2003)
#투 포인터 알고리즘을 사용해서 해결할 수 있다.
#skill.1 - end 를 0으로 초기화 한다.
#skill.2 - 수들의 합이 M인 경우 count += 1을 한다.
#skill.3 - stx를 for 문으로 N - 1까지 순차적으로 탐색하는 것이 c++과 다르다.

N, M = map(int, input().split())
num = [int(x) for x in input().split()]

result = 0

edx = 0
partSum = 0

for stx in range(N):
    while partSum < M and edx < N:
        partSum += num[edx]
        edx += 1
    if partSum == M:
        result += 1
    partSum -= num[stx]

print(result)
