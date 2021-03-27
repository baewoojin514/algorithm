//Baaaaaaaaaduk2 (Easy)(16988)
//dfs로 해결할 수 있다.
//skill.1 - dfs를 통해 현재 0인 좌표중 2개를 선택하여 1로 바꾼다.
//skill.2 - 2중 반복문을 통해 2인 경우 4방향을 탐색하며 bfs를 통해 vector에 저장한다.
//skill.3 - 2의 과정의 결과인 vector 좌표들의 4방향을 탐색하며 0이 없는 경우 tempResult 에 vector의 size를 더한다.

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#define MAX 20

using namespace std;

int N, M;
int board[MAX][MAX];
int result = 0;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int check[MAX][MAX];

vector<int> visited;
vector<pair<int, int>> canbe;
vector<pair<int, int>> temp;

bool inRange(int X, int Y){
    return X >= 0 && X < N && Y >= 0 && Y < M;
}

void make_visit(int num){
    for (int i = 0; i < 2; i++) {
        board[temp[i].first][temp[i].second] = num;
    }
    return;
}

void canKill(){
    int tempResult = 0;
    memset(check, 0, sizeof(check));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 2 && !check[i][j]) {
                check[i][j] = 1;
                queue<pair<int, int>> q;
                q.push(make_pair(i, j));
                vector<pair<int, int>> tmp;
                tmp.push_back(make_pair(i, j));
                
                while (!q.empty()) {
                    int cx, cy;
                    cx = q.front().first;
                    cy = q.front().second;
                    q.pop();
                    
                    for (int k = 0; k < 4; k++) {
                        int nx = cx + dx[k];
                        int ny = cy + dy[k];
                        if (inRange(nx, ny) && board[nx][ny] == 2) {
                            if (!check[nx][ny]) {
                                q.push(make_pair(nx, ny));
                                check[nx][ny] = 1;
                                tmp.push_back(make_pair(nx, ny));
                            }
                        }
                    }
                }
                bool flags = true;
                for (int i = 0; i < tmp.size(); i++) {
                    int cx = tmp[i].first;
                    int cy = tmp[i].second;
                    for (int j = 0; j < 4; j++) {
                        int nx = cx + dx[j];
                        int ny = cy + dy[j];
                        if (inRange(nx, ny)) {
                            if (board[nx][ny] == 0) {
                                //2인 바둑돌은 주위에 1로만 둘러쌓여야 한다.
                                flags = false;
                                break;
                            }
                        }
                    }
                }
                if (flags) {
                    tempResult += tmp.size();
                    //주위가 모두 1로 둘러쌓인 경우 모든 바둑돌을 죽일 수 있다.
                }
            }
        }
    }
    result = max(result, tempResult);
}

void dfs(int cnt){
    if (cnt == 2) {
        make_visit(1);
        canKill();
        make_visit(0);
        return;
    }
    for (int i = 0; i < canbe.size(); i++) {
        if (!visited[i]) {
            temp.push_back(make_pair(canbe[i].first, canbe[i].second));
            visited[i] = 1;
            dfs(cnt + 1);
            temp.pop_back();
            visited[i] = 0;
        }
    }
}

int main(void){
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (!board[i][j]) {
                canbe.push_back(make_pair(i, j));
            }
        }
    }
    visited.resize(canbe.size());
    dfs(0);
    
    cout << result;
    
    return 0;
}
