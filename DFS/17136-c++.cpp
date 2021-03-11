//색종이 붙이기(17136)
//dfs 재귀로 해결할 수 있다.

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#define MAX 10
#define INF 1e9
 
using namespace std;

vector<pair<int, int>> ones;
//1인 좌표 즉 색종이로 덮어야 하는 좌표들을 저장한다.

int result = INF;
int board[MAX][MAX];
int visited[MAX][MAX];
//1의 좌표의 방문여부를 표시하기 위함이다.
int paper[6] = {0, 5, 5, 5, 5, 5};
int totalOnes = 0;

bool inRange(int X, int Y){
    return X >= 0 && X < 10 && Y >= 0 && Y < 10;
}

void attachPaper(int X, int Y, int R, int num){
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < R; j++) {
            visited[X + i][Y + j] = num;
        }
    }
}

int checkRange(int cx, int cy){
    //현재 좌표에서 색종이를 붙일 수 있는 가장 큰 색종이 길이를 반환한다.
    int canBeRange = 0;
    for (int i = 4; i >= 0; i--) {
        if (!inRange(cx + i, cy + i)) {
            //현재 좌표에서 색종이를 붙였을 때 최대 범위를 넘어간다면 넘어간다.
            continue;
        }
        int tempRange = i;
        bool check = true;
        for (int j = 0; j < tempRange + 1; j++) {
            for (int k = 0; k < tempRange + 1; k++) {
                if (board[cx + j][cy + k] != 1 || visited[cx + j][cy + k] != 0) {
                    check = false;
                }
            }
        }
        if (check) {
            canBeRange = tempRange;
            break;
        }
    }
    return canBeRange + 1;
}

void dfs(int idx, int tempSum, int totalCnt){
    if (totalCnt > result) {
        return;
        //tempSum이 result보다 클 경우 더이상 탐색할 필요가 업식 때문에 prunning을 한다.
    }
    if (tempSum == totalOnes) {
        result = min(result, totalCnt);
        return;
    }
    if (visited[ones[idx].first][ones[idx].second] == 1) {
        dfs(idx + 1, tempSum, totalCnt);
        return;
    }
    int maxRange = checkRange(ones[idx].first, ones[idx].second);
    for (int i = maxRange; i > 0; i--) {
        if (paper[i] > 0) {
            //해당 길이의 종이를 사용할 수 있는 상태라면 종이를 한장 빼고 dfs 함수를 다시 호출한다.
            paper[i] -= 1;
            attachPaper(ones[idx].first, ones[idx].second, i, 1);
            dfs(idx + 1, tempSum + (i * i), totalCnt + 1);
            attachPaper(ones[idx].first, ones[idx].second, i, 0);
            paper[i] += 1;
            //뺀 종이를 다시 더해주고 visited를 다시 0으로 매꿔준다.
        }
    }
}

int main(void){
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) {
                totalOnes += 1;
                ones.push_back({i, j});
            }
        }
    }
    dfs(0, 0, 0);
    if (result == INF) {
        cout << -1;
    }
    else{
        cout << result;
    }
    return 0;
}
