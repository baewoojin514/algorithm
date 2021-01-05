#기타레슨(2343)
#이분 탐색으로 해결한다.
#가능한 블루레이의 크기는 동영상 크기의 최대 ~ 모든 동영상의 크기의 합이다.
#이분 탐색 방식으로 탐색 하면서 해당 블루레이 크기로 만들 수 있는 블루레이 개수를 count한다.
#개수가 M보다 적거나 같다면 블루레이 크기를 줄이고 반대의 경우라면 블루레이의 크기를 늘린다.
#skill.1 - 블루레이는 모든 동영상을 포함할 수 있는 크기여서 1개가 가능하다.
#skill.2 - 블루레이가 최소 한개 이상 존재하기 위해서는 동영상중 최대 크기를 가진 값이어야 한다.

N, M = map(int, input().split())

video = list(map(int, input().split()))
#입력을 받는다.
start = max(video)
end = sum(video)

result = 0
while start <= end:
    mid = (start + end) // 2

    temp = 0
    count = 1
    for i in video:
        temp += i
        if temp > mid:
            count += 1
            temp = i

    if count <= M:
        end = mid - 1
        result = mid
    else:
        start = mid + 1

print(result):
