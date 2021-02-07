#위장(programmers)
#python의 dict 자료구조를 활용하면 된다.
#skill.1 - 각 의상의 종류를 조합하는 경우의 수를 구하면 된다.
#skill.2 - 각 의상의 종류를 착용하지 않는 경우가 가능하다.
#skill.3 - 아무것도 착용하지 않는 것은 불가능 하기 때문에 *(의상의 종류 + 1) - 1(아무것도 착용하지 않은 경우)를 계산한다.

def solution(clothes):
    canbe = {}
    for info in clothes:
        if info[1] in canbe:
            canbe[info[1]] += 1
        else:
            canbe[info[1]] = 1

    answer = 1
    for i in canbe.values():
        #dict의 value를 조회할 수 있다.
        #dict의 key는 .keys()로 조회할 수 있다.
        answer *= (i + 1)
    return answer - 1
