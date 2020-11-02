#짝지어 제거하기(programmers).
#인접한 두개의 리스트 요소가 같은 것들이 있는지 탐색한다.
#만약 인접한 동일한 요소가 존재하지 않는다면 while문으 빠져나온다.
#list의 del을 사용해서 index로 삭제하는 방식으로 구현했다.
#코드의 정확성은 확실했지만 효율성이 떨어지는 코드였다.
#deque나 stack 같은 다른 자료형을 사용해야 한다.
#stack version

def solution(s):
    remove = list(reversed(s))
    compare = [remove.pop()]
    while remove:
        c = remove.pop()
        if len(compare) == 0 or compare[-1] != c:
            compare.append(c)
        else:
            compare.pop()
    if len(compare) == 0:
        return 1
    return 0

#짝지어 제거하기(programmers)
#deque version
#deque를 사용한 것이 stack 보다 시간 복잡도 측면에서 훨씬 효과적이었다(양방향성)
import collections


def solution(s):
    remove = list(reversed(s))
    q1 = collections.deque(remove)
    q2 = collections.deque()
    q2.append(q1.popleft())
    while q1:
        c = q1.popleft()
        if len(q2) == 0 or q2[-1] != c:
            q2.append(c)
        else:
            q2.pop()
    if len(q2) == 0:
        return 1
    return 0
