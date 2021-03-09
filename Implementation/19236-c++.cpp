//청소년 상어(19236)
//시뮬레이션 문제이다.
//skill.1 - 물고기의 좌표, 방향을 array vector로 관리한다.
//skill.2 - dfs 시작마다 result 즉 잡아먹은 물고기 값의 최대를 갱신한다.
//skill.3 - 물고기 이동, dfs(backtracking) 함수를 구현한다.
//skill.4 - 현재 방향을 기준으로 최대 3번 움직일 수 있고 해당 경로에 있는 물고기를 먹을 수 있다(dfs를 호출하고 원래 상태로 되돌랴야 한다).

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define MAX 16 + 1

using namespace std;

int mx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int my[8] = {0, -1, -1, -1, 0, 1, 1, 1};

int board[4][4];

struct FISH{
    int i, j, dir;
    bool isDead;
};
//물고기 좌표, 방향, 생.사 여부를

FISH fish[MAX];

int result = 0;

bool inRange(int i, int j){
    return i >= 0 && i < 4 && j >= 0 && j < 4;
}

void fishMove(){
    for (int i = 1; i <= 16; i++) {
        bool complete = true;
        int limit = 0;
        int cx = fish[i].i;
        int cy = fish[i].j;
        
        if (board[cx][cy] <= 0 || fish[i].isDead == false) {
            //물고기가 먹혔거나 상어가 위치한 경우 continue를 통해 넘어간다.
            continue;
        }
        while (complete && limit <= 7) {
            //물고기의 위피를 바꿀 수 있고 8 방향 이하로 방향을 바꾸는 경우까지 탐색한다.
            limit += 1;
            if (!complete) {
                break;
            }
            int nx = cx + mx[fish[i].dir];
            int ny = cy + my[fish[i].dir];
            
            if (inRange(nx, ny) && board[nx][ny] >= 0) {
                //빈칸이거나 물고기가 존재하는 경우만 이동할 수 있다.
                if (board[nx][ny] > 0) {
                    complete = false;
                    swap(fish[board[nx][ny]].i, fish[i].i);
                    swap(fish[board[nx][ny]].j, fish[i].j);
                    swap(board[cx][cy], board[nx][ny]);
                    break;
                }
                else if (board[nx][ny] == 0){
                    complete = false;
                    fish[i].i = nx;
                    fish[i].j = ny;
                    swap(board[cx][cy], board[nx][ny]);
                    break;
                }
            }
            else{
                fish[i].dir += 1;
                fish[i].dir %= 8;
            }
        }
        
    }
}

void sharkEatFish(int X, int Y, int tempSum, int tempDir){
    result = max(result, tempSum);
    //dfs 함수 시작마다 최대값을 갱신한다.
    int copyBord[4][4];
    FISH copyFish[MAX];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            copyBord[i][j] = board[i][j];
        }
    }
    for (int i = 1; i < MAX; i++) {
        copyFish[i] = fish[i];
    }
    //dfs함수를 호출한 후 원래 상태로 복구하기 위해 정보를 복사해 둔다.
    fishMove();
    int nx = X;
    int ny = Y;
    for (int i = 0; i < 3; i++) {
        nx += mx[tempDir];
        ny += my[tempDir];
        
        if (!inRange(nx, ny)) {
            break;
        }
        else{
            if (board[nx][ny] != 0) {
                int tmpNum = board[nx][ny];
                int tmpDir = fish[tmpNum].dir;
                board[X][Y] = 0;
                board[nx][ny] = -2;
                fish[tmpNum].isDead = false;
                sharkEatFish(nx, ny, tempSum + tmpNum, tmpDir);
                fish[tmpNum].isDead = true;
                board[nx][ny] = tmpNum;
                board[X][Y] = -2;
                //dfs 후 상어와 물고기의 위치를 원래로 돌려 놓는다.
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            board[i][j] = copyBord[i][j];
        }
    }
    for (int i = 1; i < MAX; i++) {
        fish[i] = copyFish[i];
    }
    //복사해 둔 정보를 다시 복구시킨다.
}

int main(void){
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int fishNum, fishDir;
            cin >> fishNum >> fishDir;
            board[i][j] = fishNum;
            FISH temp {i, j, fishDir - 1, true};
            fish[fishNum] = temp;
            
        }
    }
    int initSum = board[0][0];
    board[0][0] = -2;
    //상어는 -2로 표시한다.
    //물고기가 죽은 좌표는 0
    fish[initSum].isDead = false;
    //상어는 무조건 0, 0에서 시작하기 때문에 0, 0에 위치한 상어는 무조선 먹힌다.
    int initDir = fish[initSum].dir;
    sharkEatFish(0, 0, initSum, initDir);
    
    cout << result;
    
    return 0;
}
