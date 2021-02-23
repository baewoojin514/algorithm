#수식 최대화(programmes)
#*, +, -에 대해서 총 6개의 우선순위가 가능하다.
#dfs를 통해 모든 경우의 수를 만들고 limit이 3이 될때 마다 수식을 계산한다.
#skill.1 - idx를 조절해 가며 연산자일 경우 연산을 하고 연산자를 숫자로 치환한다.
#skill.2 - 리스트의 slicing을 활용하여 구현한다.
#skill.3 - 1의 과정을 종료할 때마다 최대값을 갱신한다.
import copy

canbe = ["*", "-", "+"]
#dfs연산을 위해 미리 가능한 연산자를 리스트로 정의한다.
answer = 0


def dfs(limit, temp, visited, info):
    global answer
    if limit == 3:
        exp = copy.deepcopy(info)
        #deepcopy를 통해 복사를 해야 오류가 발생하지 않는다.
        for i in temp:
            idx = 0
            while True:
                if idx >= len(exp):
                    #탐색해야 할 idx가 범위를 초과하면 break를 통해 빠져나온다.
                    break
                a = exp[idx]
                if a == i:
                    if a == '*':
                        b = exp[idx - 1] * exp[idx + 1]
                        exp[idx] = b
                    elif a == '+':
                        b = exp[idx - 1] + exp[idx + 1]
                        exp[idx] = b
                    elif a == '-':
                        b = exp[idx - 1] - exp[idx + 1]
                        exp[idx] = b
                    exp = exp[:idx - 1] + [exp[idx]] + exp[idx + 2:]
                    #리스트 처리시 del연산을 사용하면 에러가 발생할 가능성이 있다. 따라서 slicing을 통해 처리한다.
                else:
                    idx += 1
        answer = max(answer, abs(exp[0]))
    for i in range(3):
        if visited[i] == 0:
            visited[i] = 1
            temp.append(canbe[i])
            dfs(limit + 1, temp, visited, info)
            temp.pop()
            visited[i] = 0
            #가능한 모든 우선순위를 temp리스트에 저장한다.


def solution(expression):
    num = []
    operand = []

    startidx = 0
    for i in range(len(expression)):
        if expression[i] == '-' or expression[i] == '*' or expression[i] == '+':
            num.append(int(expression[startidx:i]))
            operand.append(str(expression[i]))
            startidx = i + 1
    num.append(int(expression[startidx:]))
    info = []
    #숫자가의 개수가 연산자의 개수보다 1개 더 많다.
    for i in range(len(operand)):
        info.append(num[i])
        info.append(operand[i])
    info.append(num[-1])
    temp = []
    visited = [0] * 3
    dfs(0, temp, visited, info)

    return answer
