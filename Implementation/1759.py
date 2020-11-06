#암호 만들기(1759)
#itertools를 사용해서 L개를 뽑는 모든 경우의 수를 리스트를 만든다.
#암호가 될 수 있으려면 오름차순이기 때문에 sorting 시킨다.
#skill.1 - 모음 리스트를 집합으로 만든다.
#skill.2 - 후보와 리스트이 교집합이 1개 이상이고 차집합이 2개 이상인 경우에 join을 사용해서 바로 출력한다.

import itertools

L, C = map(int, input().split())
alpha = [str(x) for x in input().split()]
alpha.sort()

vowel = set("aeiou")
canbe = list(itertools.combinations(alpha, L))

for candidate in canbe:
    num1 = set(candidate).intersection(vowel)
    num2 = set(candidate).difference(vowel)

    if len(num1) >= 1 and len(num2) >= 2:
        print(''.join(candidate))

