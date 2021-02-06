#정수 삼각형(programmers)
#행의 양쪽 끝 값일 경우 바로 위 행의 값을 더해주면 된다.
#중간에 낀 값인 경우 위 행의 오른쪽과 왼쪽의 값중 큰 값을 더해주면 된다.

def solution(triangle):
    for i in range(1, len(triangle)):
        for j in range(len(triangle[i])):
            if j == 0:
                triangle[i][j] = triangle[i][j] + triangle[i - 1][j]
            elif j == len(triangle[i]) - 1:
                triangle[i][j] = triangle[i][j] + triangle[i - 1][j - 1]
            else:
                triangle[i][j] = triangle[i][j] + max(triangle[i - 1][j - 1], triangle[i - 1][j])

    return max(triangle[-1])
