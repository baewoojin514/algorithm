#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string.h>
#define MAX 5
#define INF 1e9

using namespace std;

int num[MAX][MAX];
char oper[MAX][MAX];
int N;
int result1;
int result2;
int dx[2] = {0, 1};
int dy[2] = {1, 0};

void input(){
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if ((i + j) % 2 == 0) {
                cin >> num[i][j];
            }
            else{
                cin >> oper[i][j];
            }
        }
    }
}

bool inRange(int cx, int cy){
    return cx >= 0 && cx < N && cy >= 0 && cy < N;
}

int operChange(char oper){
    if (oper == '+') {
        return 0;
    }
    else if (oper == '-'){
        return 1;
    }
    return 2;
}

void dfs(int stX, int stY, int tempResult){
    int copyResult = tempResult;
    if (stX == N - 1 && stY == N - 1) {
        result1 = max(result1, tempResult);
        result2 = min(result2, tempResult);
        return;
    }
    if ((stX + stY) % 2 == 0) {
        for (int i = 0; i < 2; i++) {
            int nxtX = stX + dx[i];
            int nxtY = stY + dy[i];
            if (inRange(nxtX, nxtY)) {
                dfs(nxtX, nxtY, tempResult);
            }
        }
    }
    else{
        for (int i = 0; i < 2; i++) {
            int nxtX = stX + dx[i];
            int nxtY = stY + dy[i];
            if (inRange(nxtX, nxtY)) {
                if (operChange(oper[stX][stY]) == 0) {
                    dfs(nxtX, nxtY, tempResult += num[nxtX][nxtY]);
                    tempResult = copyResult;
                }
                else if (operChange(oper[stX][stY]) == 1){
                    dfs(nxtX, nxtY, tempResult -= num[nxtX][nxtY]);
                    tempResult = copyResult;
                }
                else{
                    dfs(nxtX, nxtY, tempResult *= num[nxtX][nxtY]);
                    tempResult = copyResult;
                }
            }
        }
    }
    
}

int main(void)
{
    result1 = -INF;
    result2 = INF;
    input();
    
    dfs(0, 0, num[0][0]);
    
    cout << result1 << " " << result2;
    
    return 0;
}
