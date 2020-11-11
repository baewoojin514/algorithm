#solution1
#휴게소 세우기(1477)
#이진 탐색을 사용해서 풀어야 한다.
#휴게소가 없는 구간의 최대값을 right의 범위로 설정한다.
#mid 값으로 휴게소가 없는 구간을 나누고 그 몫을 더한다.
#skill.1 - 만약 해당 mid 값으로 휴게소를 M개 이상 지을 수 있다면 범위를 넓힌다(left = mid + 1).
#skill.2 - 만약 해당 mid 값으로 휴게소를 M개 이상 지을 수 없다면 범의를 좁힌다(right = mid - 1).

N, M, L = map(int, input().split())

service = [int(x) for x in input().split()]
service.append(0)
service.append(L)
#휴게소 0 ~ L까지 존재할 수 있기 때문에 0과 L을 append 한다.
service.sort()

left = 0
right = L - 1

while left <= right:
    mid = (left + right) // 2
    canbe = 0
    for i in range(len(service) - 1):
        canbe += (service[i + 1] - service[i] - 1) // mid
    if canbe > M:
        left = mid + 1
    else:
        right = mid - 1

print(left)

