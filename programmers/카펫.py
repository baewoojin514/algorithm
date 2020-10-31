#카펫(programmers)
#노란색 격자의 개수를 기준으로 경우의 수를 만들어야 한다.
#1부터 2증가하면서 약수의 조합으로 만든다 => y = 6  --> 1, 6 2, 3 3, 2 6, 1
#단 가로가 세로 보다 길어야 함으로 리스트에 가로가 세로 보다 크다면 저장한다.
#가능한 리스트를 (가로 길이 + 2) + (세로 x 2) == brown인 것을 임시 리스트에 저장한다
#저장된 리스트의 요소들에 각각 2를 더한 후 return
#핵심은 가로와 세로의 길이가 같을 수 있다는 것이다.

def solution(brown, yellow):
    answer = []
    compare = []
    for i in range(yellow, 0, -1):
        temp = []
        if yellow % i == 0 and i >= yellow // i:
            temp.append(i)
            temp.append(yellow//i)
            compare.append(temp)
    for i in compare:
        if (i[0] + 2)*2 + (i[1] * 2) == brown:
            answer.append(i[0]+2)
            answer.append(i[1]+2)

    return answer
