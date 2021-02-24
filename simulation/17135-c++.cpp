//캐슬 디펜스(17135)
//시뮬레이션 문제이다.
//dfs를 사용해서 궁수 3명을 배치하는 모든 경우의 수를 구한다.
//skill.1 - 궁수 배치 dfs를 실행한다.
//skill.2 - 궁수 3명에 대해 적군과의 모든 거리와 좌표를 vector에 저장한다.
//skill.3 - 좌표를 i, j => j, i 반대로 저장한 후 vector를 정렬한다.
//skill.4 - vector의 첫번째 요소 즈 적군을 제거하고 enemy 2차원 배열에 표시한다.
//skill.5 - enemy 2차월 배열에 1로 표시된 개수 즉 죽인 적군의 수를 count한다.
//skill.6 - 5번까지의 과정이 끝나면 적들이 한칸씩 내려옴으로 위의 과정들을 N번 반복할 수 있다.

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int N, M, D;
int board[15][15];
int visited[15];
vector<int> temp;
int result = 0;
vector<int> archer;

void castleDefence(){
    int tempResult = 0;
    int copyBoard[15][15];
    int enemyCount[15][15];
    memset(copyBoard, 0, sizeof(copyBoard));
    memset(enemyCount, 0, sizeof(enemyCount));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            copyBoard[i][j] = board[i][j];
        }
    }
    //copyBoard에 board를 복사한다.
    for (int i = 0; i < N; i++) {
        //적군이 board의 N행 까지 내려올 수 있기 때문에 모든 과정을 N번 반복한다.
        for (int j = 0; j < 3; j++) {
            int cx = N;
            int cy = archer[j];
            vector<pair<pair<int, int>, int>> canKill;
            for (int k1 = 0; k1 < N; k1++) {
                for (int k2 = 0; k2 < M; k2++) {
                    if (copyBoard[k1][k2] == 1) {
                        if (abs(cx - k1) + abs(cy - k2) <= D) {
                            canKill.push_back({{abs(cx - k1) + abs(cy - k2), k2}, k1});
                        }
                    }
                }
            }
            sort(canKill.begin(), canKill.end());
            if (canKill.size() != 0) {
                enemyCount[canKill[0].second][canKill[0].first.second] = 1;
                //죽일 수 있는 적이 있다면 죽이고 표시한다.
            }
            canKill.clear();
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (enemyCount[i][j] == 1) {
                    tempResult += 1;
                    copyBoard[i][j] = 0;
                    enemyCount[i][j] = 0;
                    //죽인 적군의 수를 count한다.
                }
            }
        }
        vector<pair<int, int>> future;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (copyBoard[i][j] == 1) {
                    copyBoard[i][j] = 0;
                    future.push_back({i + 1, j});
                    //future vector에 적군에 하단으로 이동할 좌표를 저장한다.
                }
            }
        }
        for (int i = 0; i < future.size(); i++) {
            if (future[i].first >= 0 && future[i].first < N && future[i].second >= 0 && future[i].second < M) {
                copyBoard[future[i].first][future[i].second] = 1;
            }
        }
        future.clear();
    }
    result = max(result, tempResult);
}

void dfs(){
    archer.resize(3);
    for (int i = 0; i < M; i++) {
        for (int j = i + 1; j < M; j++) {
            for (int k = j + 1; k < M; k++) {
                archer[0] = i;
                archer[1] = j;
                archer[2] = k;
                castleDefence();
            }
        }
    }
    //dfs보다 3중 for문을 통해 궁수의 배치를 조합한다.
    
}

int main(void){
    cin >> N >> M >> D;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
    dfs();
    cout << result;
    return 0;
}
