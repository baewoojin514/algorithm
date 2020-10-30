#순위(programmers)
#입력으로 들어온 권투 선수의 명수 만큼 win lose 2차원 리스트를 만든다.
#입력 정보에 따라 win lost각각의 선수가 이기고 진 선수 번호를 append한다.
#for문으로 lose테이블을 돌면서 자기 자신에게 진 선수의 win table에 자신의 win table 정보를 추가한다.
#위의 과정에서 기존에 있는 정보에 새로운 정보를 추가할 때 list의 extend method를 사용한다.

def solution(n, results):
    answer = 0
    win = [[]for _ in range(n)]
    lose = [[]for _ in range(n)]
    for info in results:
        win[info[1]-1].append(info[0]-1)
        lose[info[0]-1].append(info[1]-1)
    for i in range(n):
        for j in lose[i]:
            win[j].extend(win[i])
        for j in win[i]:
            lose[j].extend(lose[i])
    for i in range(n):
        if len(set(win[i])) + len(set(lose[i])) == n - 1:
            answer += 1
    return answer
#순위(programmers)
#리스트로 접근하면 시간 초과가 발생한다.
#집합이나 딕셔너리 등의 자료형을 사용해 구현하는 것이 더 이상적이다.
#기존의 풀이에 자료형만 집합으로 바꾸어서 구현한다.
#skill.1 - set 또한 2차원 리스트 처럼 사용할 수 있다.
#skill.2 - set append -> add extend -> update
#자신을 이긴 사람과 자신이 이긴 사람의 수를 합한 것이 전체에서 1을 뺀 값과 같다면 answer += 1을 한다.

def solution(n, results):
    answer = 0
    win = {}
    lose = {}
    for i in range(n):
        win[i] = set()
        lose[i] = set()
    for info in results:
        win[info[1]-1].add(info[0]-1)
        lose[info[0]-1].add(info[1]-1)
    for i in range(n):
        for j in lose[i]:
            win[j].update(win[i])
        for j in win[i]:
            lose[j].update(lose[i])
    for i in range(n):
        if len(win[i]) + len(lose[i]) == n - 1:
            answer += 1
    return answer

