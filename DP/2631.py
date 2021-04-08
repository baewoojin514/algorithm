#줄세우기(2631)
#LIS 알고리즘으로 해결할 수 있다.
#skill.1 - 가장 긴 부분 증가수열의 길이를 찾는다.
#skill.2 - 1의 결과를 제외한 학생들만 움직이면 최소의 움직임으로 오름차순 정렬을 할 수 있다.

import bisect

student = []
N = int(input())

for _ in range(N):
    a = int(input())
    idx = bisect.bisect_left(student, a)

    if idx == len(student):
        student.append(a)
    else:
        student[idx] = a

print(N - len(student))
