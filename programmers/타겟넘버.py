#타겟 넘버(programmers)
#dfs 재귀 방식을 통해 현재 값에 다음 값을 더하거나 뺀 수를 재귀 함수의 parameter로 넘긴다.
#재귀 함수 처음에 입력으로 들어온 모든 숫자를 더하거나 뺏는지 확인하고 그 수가 target과 같은지 확인한다.
#skill.1 - 함수 내부에 또 다른 함수를 선언하고 nonlocal을 통해 함수 외부에 있는 변수에 접근 가능하다.
#skill.2 - 함수 사용시 늘 변수 범위에 신경을 써야 한다.

def solution(numbers, target):
    answer = 0
    depth = len(numbers)

    def targetsearch(index, cNum):
        if index == depth:
            if cNum == target:
                nonlocal answer
                answer += 1
        else:
            targetsearch(index + 1, cNum + numbers[index])
            targetsearch(index + 1, cNum - numbers[index])

    targetsearch(0, 0)
    return answer
