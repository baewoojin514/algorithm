//미로만들기(2665)
//우선순위 큐를 사용해서 구현한다.
//이중 pair를 사용해서 구현한다(cnt, cx, cy)
//priority queue(python3 -> heapq)의 사용법을 익힐 수 있는 문제이다.
//기본적인 logic은 python3와 동일하다.

#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdio>

using namespace std;

int board[51][51];
int visited[51][51];

int n;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

priority_queue<pair<pair<int, int>, int>> q;
//이중 pair를 사용해서 우선순위 큐를 구현한다.

int main(void){
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%1d", &board[i][j]);
            //python3의 input, input().split()의 차이를 고려한다.
            //cin, scanf
        }
    }
    q.push({{0, 0}, 0});
    //cnt, cx, cy
    visited[0][0] = 1;
    while (!q.empty()) {
        int cnt = -q.top().first.first;
        //cnt를 음수로 지정하면 무조건 첫 번째 원소부터 비교하기 때문에 에러 없이 우선순위 큐를 사용할 수 있다.
        int cx = q.top().first.second;
        int cy = q.top().second;
        q.pop();
        if (cx == n - 1 && cy == n - 1) {
            cout << cnt;
            break;
        }
        else{
            for (int k = 0; k < 4; k++) {
                int nx = cx + dx[k];
                int ny = cy + dy[k];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                    if (visited[nx][ny] == 0) {
                        if (board[nx][ny] == 0) {
                            board[nx][ny] = 1;
                            visited[nx][ny] = 1;
                            q.push({{-(cnt + 1), nx}, ny});
                        }
                        else if (board[nx][ny] == 1){
                            visited[nx][ny] = 1;
                            q.push({{-cnt, nx}, ny});
                        }
                    }
                }
            }
        }
    }
    return 0;
}
