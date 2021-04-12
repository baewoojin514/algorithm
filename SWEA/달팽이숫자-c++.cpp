#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#define MAX 10

using namespace std;

int board[MAX][MAX];
int num;
int stx;
int sty;
int cnt;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int cdir;

void dfs(){
    for (int i = 0; i < cnt; i++) {
        num += 1;
        stx += dx[cdir];
        sty += dy[cdir];
        board[stx][sty] = num;
    }
    return;
}

int main(void)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        memset(board, 0, sizeof(board));
        int N;
        cin >> N;
        num = 1;
        stx = 0; sty = 0;
        board[stx][sty] = num;
        for (int i = 0; i < N - 1; i++) {
            num += 1;
            stx += dx[0];
            sty += dy[0];
            board[stx][sty] = num;
        }
        cnt = N - 1;
        cdir = 1;
        for (int i = 0; i <= 2 * (N - 1) - 1; i++) {
            dfs();
            cdir = (cdir + 1) % 4;
            if (i % 2 == 1) {
                cnt -= 1;
            }
        }
        cout << "#" << test_case << "\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
