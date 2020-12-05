//사다리 조작(15864)
//python3와 같은 방식으로 구현한다.
//simulation 스타일의 문제이다.
//사다리 타기의 원리 즉 열(index)의 변화 방식을 이해해야 한다.
//현재 사다리가 유효 한지 검사하는 함수와 사다리를 놓는 함수 2개를 구현한다.

#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int N;
int M;
int H;

int X;
int Y;

const int INF = 1e9;
int result = INF;
//python3와는 다르게 max값을 위처럼 사용해서 min값을 계산할 수 있다.

int board[30][10];

bool check(){
    int compare = 0;
    for (int i = 0; i < N; i++) {
        compare = i;
        for (int j = 0; j < H; j++) {
            if (board[j][compare]) {
                compare += 1;
            }
            else if (board[j][compare - 1]){
                compare -= 1;
            }
        }
        if (compare != i) {
            return false;
        }
    }
    return true;
}

void ladderBuilder(int cnt, int idx){
    if (cnt > 3) {
        return;
    }
    //python3와는 다르게 cnt가 3보다 큰 경우 그냥 return해서 처리한다.
    //limit처리를 제거하니 시간 초과 문제가 해결되었다.
    if (check()) {
        result = min(result, cnt);
        return;
    }
    for (int i = idx; i < H; i++) {
        for (int j = 0; j < N - 1; j++) {
            if (board[i][j] == 1) {
                continue;
            }
            else if (j - 1 >= 0 && board[i][j - 1] == 1){
                continue;
            }
            else if (j + 1 < N && board[i][j + 1] == 1){
                continue;
            }
            board[i][j] = 1;
            ladderBuilder(cnt + 1, i);
            board[i][j] = 0;
        }
    }
    
}

int main(void){
    cin >> N >> M >> H;
    
    for (int i = 0; i < M; i++) {
        cin >> X >> Y;
        board[X - 1][Y - 1] = 1;
    }
    ladderBuilder(0, 0);
    if (result >= 4) {
        cout << -1;
    }
    else{
        cout << result;
    }
    return 0;
}
