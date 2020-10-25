#컨베이어 벨트 위의 로봇(20055)
#시뮬레이션 문제
#로봇의 움직임은 1차원 리스트로 관리
#컨베이어 벨트는 1차원 리스트로 관리 => 순서상 리스트의 마지막 요소를 리스트의 선두에 추가하면
#컨베이어 벨트가 회전하는 것을 구현 가능하다.
#떨어지는 위치의 로봇이 떨어지는 경우는 컨베이어 벨트 회전 시 그리고 컨베이어 벨트위의 로봇들이 움직인 직후 이다.

N, K = map(int, input().split())

info = [int(x) for x in input().split()]
belt = info

time = 0
robot = [0] * N
while True:
    time += 1
    belt.insert(0, belt.pop())
    for i in range(N - 2, -1, -1):
        robot[i + 1] = robot[i]
        robot[i] = 0
    robot[N - 1] = 0

    for i in range(N - 2, -1, -1):
        if robot[i] != 0:
            if robot[i + 1] == 0 and belt[i + 1] > 0:
                robot[i + 1] = robot[i]
                robot[i] = 0
                belt[i + 1] -= 1
            else:
                robot[i] = robot[i]

    robot[N - 1] = 0
    if belt[0] > 0 and robot[0] == 0:
        belt[0] -= 1
        robot[0] = time
    if belt.count(0) >= K:
        break

print(time)
