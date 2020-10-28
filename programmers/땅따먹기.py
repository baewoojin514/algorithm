#땅따먹기(programmers)
#정수 삼각형과 유사한 dp 문제
#parameter로 들어온 이차원 리스트와 동일한 크기의 dp 리스트를 만든다.
#dp리스트의 첫번째 행을 입력으로 들어온 리스트로 채운다.
#다음행 부터 위의 행중 현재 열을 제외한 값중 가장 큰 값을 현재 행의 열에 존재하는 값과 더해서 채운다.
#위의 과정이 끝나면 마지막 행의 최대값을 반환한다.
#열의 최대 길이는 4로 고정되어 있다.

def solution(land):
    dp = [[int(0) for _ in range(4)]for _ in range(len(land))]
    dp[0] = land[0]

    for i in range(1, len(land)):
        for j in range(4):
            cv = land[i][j]
            tempMax = 0
            for k in range(4):
                if j != k:
                    tempMax = max(tempMax, dp[i - 1][k])
            dp[i][j] = cv + tempMax

    return max(dp[len(land) - 1])
