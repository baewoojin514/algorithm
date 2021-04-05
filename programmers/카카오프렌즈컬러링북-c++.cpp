//카카오프렌즈 컬러링북(programmers)
//bfs로 해결할 수 있다.

#include <vector>
#include <queue>
#include <cstring>
#define MAX 100

using namespace std;

int M, N;
int visited[MAX][MAX];
int areaNum;
int maxArea;
int copy_picture[MAX][MAX];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool inRange(int X, int Y){
    return X >= 0 && X < M && Y >= 0 && Y < N;
}

int BFS(int X, int Y){
    queue<pair<int, int>> q;
    visited[X][Y] = 1;
    int compare = copy_picture[X][Y];
    int tempCnt = 1;
    q.push(make_pair(X, Y));
    while (!q.empty()) {
        int cx, cy;
        cx = q.front().first;
        cy = q.front().second;
        
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx, ny;
            nx = cx + dx[i];
            ny = cy + dy[i];
            if (inRange(nx, ny) && visited[nx][ny] == 0) {
                if (copy_picture[nx][ny] == compare) {
                    tempCnt += 1;
                    visited[nx][ny] = 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    return tempCnt;
    //영역의 넓이를 반환한다.
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    memset(visited, 0, sizeof(visited));
    memset(copy_picture, 0, sizeof(copy_picture));
    areaNum = 0;
    maxArea = 0;
    M = m;
    N = n;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            copy_picture[i][j] = picture[i][j];
            if (picture[i][j] == 0) {
                visited[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (copy_picture[i][j] > 0 && visited[i][j] == 0) {
                areaNum += 1;
                int temp = BFS(i, j);
                maxArea = max(maxArea, temp);
            }
        }
    }
    vector<int> answer(2);
    answer[0] = areaNum;
    answer[1] = maxArea;
    return answer;
}
