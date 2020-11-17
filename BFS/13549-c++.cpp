//숨바꼭질 3(13549)
//deque를 사용해서 문제를 해결한다.
//visited 배열을 사용해야 한다.
//bfs방식으로 python3와 동일한 알고리즘으로 구현한다.
//while문 초기에 동생을 찾았는지를 확인하고 찾았다면 시간을 출력한다.

#include <iostream>
#include <queue>

using namespace std;

int N;
int K;
int visited[100000];
//배열의 모든 요소는 0으로 초기화 되어 있다.

int main(void){
    cin >> N >> K;
    queue<pair<int, int>> q;
    q.push(make_pair(N, 0));
    //q에 현재 위치 N과 초기화된 시간을 push 한다.
    visited[N] = 1;
    
    while (!q.empty()) {
        int cx = q.front().first;
        int ct = q.front().second;
        q.pop();
        if (cx == K) {
            printf("%d", ct);
            break;
        }
        if (cx * 2 >= 0 && cx * 2 <= 100000) {
            if(visited[cx * 2] == 0) {
                q.push(make_pair(cx * 2, ct));
                visited[cx * 2] = 1;
            }
        }
        //순간이동은 시간이 걸리지 않음으로 먼저 queue에 삽입해야 한다.
        if (cx - 1 >= 0 && cx - 1 <= 100000) {
            if(visited[cx - 1] == 0) {
                q.push(make_pair(cx - 1, ct + 1));
                visited[cx - 1] = 1;
            }
        }
        if (cx + 1 >= 0 && cx + 1 <= 100000) {
            if(visited[cx + 1] == 0) {
                q.push(make_pair(cx + 1, ct + 1));
                visited[cx + 1] = 1;
            }
        }
    }
    return 0;
}
