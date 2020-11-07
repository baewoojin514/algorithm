#리모컨(1107)
#완전 탐색 문제이다.
#greedy 방식으로 접근하려 했으나 완전 탐색으로 구현하는 것이 오류를 최소화할 수 있다.
#버튼을 누르는 회수는 현재 채널 번호에서 100을 뺀 절대값이다(+ or -).
#위의 수에 채널 번호의 자리수를 더하면 된다(1000 -> 4) => 1을 누르고 0을 3번 눌렀다.
#skill.1 - 100번 에서 시작임으로 100번 에서 + -로만 움직이는 경우
#skill.2 - 임의의 번호로 이동해서 + -로 움직이는 경우
#위의 두 경우에 대해서 최소값을 구해야 한다.

N = int(input())
M = int(input())

broken = []
if M > 0:
    broken = input().split()
#고장난 숫자 버튼 리스트

minValue = abs(100 - N)

for canbe in range(1000001):
    check = True
    canbe = str(canbe)
    for i in range(len(canbe)):
        if canbe[i] in broken:
            check = False
            break
    if check:
        minValue = min(minValue, abs(int(canbe) - N) + len(canbe))
        #다른 채널에서 목표 채널로 이동하기 위해서는 + -를 두 채널 수의 절대 값 차이 만큼 누르고 다른 채널의 자리수 만큼 버튼을 눌러야 한다.

print(minValue)
