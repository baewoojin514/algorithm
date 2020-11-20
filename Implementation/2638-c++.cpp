//치즈(2638)
//0, 0에서 4방향으로 연결된 모든 좌표를 -1로 바꾼다.
//count 이차원 배열을 사용해서 치즈와 접촉한 공기의 수를 count한다.
//2개 이상의 공기와 접촉한 치즈를 0으로 바꾼다.
//while문 마지막에 치즈의 개수를 count하고 0이면 break문을 통해 빠져나간다.
//while문 동안 ++한 totalTime을 출력한다.
//skill.1 - memset은 배열을 초기화 할때 유용하게 사용할 수 있다.

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
//std::접두어를 생략하기 위해 iostream을 header로 선언한 후 사용한다.

int N;
int M;
int visited[100][100];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int totalTime = 0;
int check = 0;
int cheese[100][100];
int numcheck[100][100];

int main(void){
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> cheese[i][j];
        }
    }
    while (true) {
        totalTime += 1;
        memset(visited, 0, sizeof(visited));
        //python3 처럼 다시 배열을 선언 하지 않고 memset을 통해 값을 초기화 한다.
        queue<pair<int, int>> q;
        visited[0][0] = 1;
        cheese[0][0] = -1;
        q.push(make_pair(0, 0));
        while (!q.empty()) {
            int cx = q.front().first;
            int cy = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++) {
                int nx = cx + dx[k];
                int ny = cy + dy[k];
                if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                    if (visited[nx][ny] == 0 && cheese[nx][ny] == 0) {
                        q.push(make_pair(nx, ny));
                        visited[nx][ny] = 1;
                        cheese[nx][ny] = -1;
                    }
                }
            }
        }
        //공기를 -1로 바꾼다.
        memset(numcheck, 0, sizeof(numcheck));
        //python3 처럼 다시 배열을 선언 하지 않고 memset을 통해 값을 초기화 한다.
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (cheese[i][j] == 1) {
                    for (int k = 0; k < 4; k++) {
                        int ni = i + dx[k];
                        int nj = j + dy[k];
                        if (ni >= 0 && ni < N && nj >= 0 && nj < M) {
                            if (cheese[ni][nj] == -1) {
                                numcheck[i][j] += 1;
                            }
                        }
                    }
                }
            }
        }
        //치즈와 접촉한 공기를 count 한다.
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (numcheck[i][j] >= 2) {
                    cheese[i][j] = -1;
                }
            }
        }
        //공기와 2개 이상 접촉한 치즈를 공기로 바꾼다.
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (cheese[i][j] == -1) {
                    cheese[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (cheese[i][j] == 0) {
                    check += 1;
                }
            }
        }
        if (check == N*M) {
            break;
        }
        else{
            check = 0;
            continue;
        }
        //cheese가 모두 공기로 변했다면 시간을 출력하고 while문을 빠져 나온다.
    }
    printf("%d", totalTime);
    return 0;
}
