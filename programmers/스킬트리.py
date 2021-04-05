#스킬트리(programmers)\
#구현 문제이다.

def solution(skill, skill_trees):
    s = set()
    answer = 0
    for i in range(len(skill)):
        s.add(skill[i])
    for info in skill_trees:
        temp = ""
        for i in range(len(info)):
            if info[i] in s:
                temp += info[i]
        n = len(temp)
        compare = skill[:n]
        if compare == temp:
            answer += 1

    return answer
