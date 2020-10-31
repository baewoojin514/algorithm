#최대값과 최소값(programmers)
#입력으로 들어오는 문자열을 리스트로 임시변환한다.
#모두 정수형으로 처리하고 min, max를 사용해서 최대값 그리고 최소값을 찾는다.
#위에서 찾은 두 값을 문자열 형태로 다시 연결하고 반환한다.

def solution(s):
    answer = ''

    info = list(s.split())
    temp = []
    for i in info:
        temp.append(int(i))
    A = max(temp)
    B = min(temp)

    answer += str(B)
    answer += " "
    answer += str(A)

    return answer
