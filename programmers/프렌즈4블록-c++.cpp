//프렌즈4블록(programmers)
//구현 문재이다.
//skill.1 - [cx + 1][cy + 1], [cx + 1][cy], [cx][cy + 1] 과 [cx][cy] 이 동일한 경우를 visted 에 check 한다.
//skill.2 - visited 가 1인 경우 copy_board 의 요소를 'B'로 바꾼다(B는 프렌즈가 존재하지 않다는 의미이다).
//skill.3 - 제거할 프렌즈를 찾는 함수, 모든 프렌즈를 밑으로 이동 시키는 함수를 구현한다.

#include <string>
#include <vector>
#include <cstring>
#define MAX 30

using namespace std;

int M, N;
vector<string> copy_board;
int visited[MAX][MAX];
int dx[3] = {1, 1, 0};
int dy[3] = {0, 1, 1};

bool inRange(int X, int Y){
    return X >= 0 && X < M && Y >= 0 && Y < N;
}

void checkFriends(){
    for (int i = 0; i < M - 1; i++) {
        for (int j = 0; j < N - 1; j++) {
            if (copy_board[i][j] != '*') {
                bool flags = true;
                char c = copy_board[i][j];
                for (int k = 0; k < 3; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (copy_board[nx][ny] != c) {
                        flags = false;
                    }
                }
                if (flags) {
                    visited[i][j] = 1;
                    for (int k = 0; k < 3; k++) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        visited[nx][ny] = 1;
                    }
                }
            }
        }
    }
    return;
}

int removeFriedns(){
    int cnt = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j] == 1) {
                cnt += 1;
                copy_board[i][j] = '*';
            }
        }
    }
    return cnt;
}

void moveFriends(){
    for (int i = M - 2; i >= 0; i--) {
        for (int j = 0; j < N; j++) {
            if (copy_board[i][j] != '*') {
                int cx = i;
                while (true) {
                    cx += 1;
                    if (copy_board[cx][j] != '*') {
                        break;
                    }
                    if (!inRange(cx, j)) {
                        break;
                    }
                }
                cx -= 1;
                if (cx != i) {
                    copy_board[cx][j] = copy_board[i][j];
                    copy_board[i][j] = '*';
                }
            }
        }
    }
    return;
}

int solution(int m, int n, vector<string> board) {
    M = m; N = n;
    int answer = 0;
    copy_board = board;
    while (true) {
        memset(visited, 0, sizeof(visited));
        checkFriends();
        int cnt = removeFriedns();
        if (cnt == 0) {
            break;
        }
        answer += cnt;
        moveFriends();
    }
    return answer;
}
