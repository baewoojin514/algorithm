#공유기 설치(2110)
#이진 탐색 문제이다.
#문제를 이해하는 것이 굉장히 중요하다.
#이진 탐색의 범위는 가장 가까운 집간의 거리부터 가장 먼 집간의 거리이다.
#skill.1 - gap을 mid 값으로 정하고 해당 gap으로 C개 이상의 공유기 설치가 가능한지 탐색한다.
#skill.2 - C개 이상 설치 가능하면 gap을 늘린다.
#skill.3 - C개 이상 설치 불가능하면 gap을 줄인다.

N, C = map(int, input().split())

house = []
for _ in range(N):
    a = int(input())
    house.append(a)

house.sort()

start = house[1] - house[0]
end = house[-1] - house[0]

result = 0

while start <= end:
    mid = (start + end) // 2
    value = house[0]
    canbe = 1
    for i in range(1, N):
        if house[i] >= value + mid:
            canbe += 1
            value = house[i]
    if canbe >= C:
        start = mid + 1
        result = mid
    else:
        end = mid - 1

print(result)

#공유기 설치(2110)
#이진 탐색 문제이다.
#문제를 이해하는 것이 굉장히 중요하다.
#이진 탐색의 범위는 가장 가까운 집간의 거리부터 가장 먼 집간의 거리이다.
#skill.1 - gap을 mid 값으로 정하고 해당 gap으로 C개 이상의 공유기 설치가 가능한지 탐색한다.
#skill.2 - C개 이상 설치 가능하면 gap을 늘린다.
#skill.3 - C개 이상 설치 불가능하면 gap을 줄인다.

N, C = map(int, input().split())

house = []
for _ in range(N):
    a = int(input())
    house.append(a)

house.sort()

start = 1
end = house[-1] - house[0]

result = 0

while start <= end:
    mid = (start + end) // 2
    value = house[0]
    canbe = 1
    for i in range(1, len(house)):
        if house[i] >= value + mid:
            canbe += 1
            value = house[i]
    if canbe >= C:
        start = mid + 1
        result = mid
    else:
        end = mid - 1

print(result)
