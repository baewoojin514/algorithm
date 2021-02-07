#include <iostream>
#include <algorithm>
#include <cmath>
#define MAX 1000

using namespace std;

int board[MAX][MAX];
int n, m;

int main(void){
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &board[i][j]);
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (board[i][j]) {
                board[i][j] = min(min(board[i - 1][j], board[i - 1][j - 1]), board[i][j - 1]) + 1;
            }
        }
    }
    int maxValue = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            maxValue = max(maxValue, board[i][j]);
        }
    }
    cout << pow(maxValue, 2);
    return 0;
}
