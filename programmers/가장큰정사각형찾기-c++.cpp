//가장 큰 정사각형(programmers)
//dp문제이다.
//1 ~ row - 1, 1 ~ column - 1 까지의 행과 열에 대해 (i, j - 1), (i - 1, j - 1), (i - 1, j)의 요소를 확인해야 한다.
//skill.1 - (i, j - 1), (i - 1, j - 1), (i - 1, j)의 최소값에 1을 더하여 (i, j)에 할당한다.
//skill.2 - 하나라도 0이면 즉 정사각형을 만들 수 없다면 값은 그대로이다.
//skill.3 - board의 최대값을 구하고 제곱을 하여 반환한다.

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    for (int i = 1; i < board.size(); i++) {
        for (int j = 1; j < board[i].size(); j++) {
            if (board[i][j]) {
                board[i][j] = min(min(board[i - 1][j], board[i - 1][j - 1]), board[i][j - 1]);
            }
        }
    }
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            answer = max(answer, board[i][j]);
        }
    }
    return pow(answer, 2);
}
