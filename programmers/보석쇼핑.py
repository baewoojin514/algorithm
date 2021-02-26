#보석 쇼핑(programmes)
#투 포인터 알고리즘을 사용해서 해결할 수 있다.
#보석의 구매 여부를 확인하기 위해서 dict 자료구조를 사용한다.
#skill.1 - gems 리스트를 탐색하여 보석 종류의 수를 count한다.
#skill.2 - 모든 보석을 구매한 경우 구간의 길이와 stx, edx를 queue에 저장한다.

def solution(gems):
    temp = set(gems)
    #gems를 집합으로 변환한다.
    jewelry = {}
    N = len(temp)
    result = []
    edx = 0

    for stx in range(len(gems)):
        while len(jewelry) < N and edx < len(gems):
            if gems[edx] in jewelry.keys():
                #c++에서 처럼 무작정 += 1을 하면 key error가 발생한다.
                jewelry[gems[edx]] += 1
            else:
                jewelry[gems[edx]] = 1
            edx += 1
        if len(jewelry) == N:
            result.append([edx - stx + 1, stx, edx])
        if jewelry[gems[stx]] == 1:
            del jewelry[gems[stx]]
            #c++의 erase 처럼 del을 사용하여 dict의 요소를 제거할 수 있다.
        else:
            jewelry[gems[stx]] -= 1
    result.sort()
    a = result[0][1] + 1
    b = result[0][2]

    answer = []
    answer.append(a)
    answer.append(b)
    return answer
