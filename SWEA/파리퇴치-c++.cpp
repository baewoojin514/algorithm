#include <iostream>
#include <stdio.h>
#include <cstring>
#define MAX 15

using namespace std;

int board[MAX][MAX];

int main(void)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        memset(board, 0, sizeof(board));
        int N, M;
        int tempMax = 0;
        cin >> N >> M;
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> board[i][j];
            }
        }
        for (int i = 0; i <= N - M; i++) {
            for (int j = 0; j <= N - M; j++) {
                int temp = 0;
                int stx = i; int sty = j;
                for (int k1 = 0; k1 < M; k1++) {
                    for (int k2 = 0; k2 < M; k2++) {
                        temp += board[stx + k1][sty + k2];
                    }
                }
                tempMax = max(tempMax, temp);
            }
        }
        cout << "#" << test_case << " " << tempMax << "\n";
    }
    return 0;
}
