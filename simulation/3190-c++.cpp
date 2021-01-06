//뱀(3190)
//python3와 같은 방식으로 구현한다.
//뱀은 deque를 통해 구현한다. 꼬리 ~~ 머리 순서로 구현한다.
//뱀은 2, 땅은 0, 사과는 1로 구분한다.
//skill.1 - 다음칸에 사과가 있다면 꼬리는 움직이지 않는다.
//skill.2 - 다음칸에 사과가 없다면 꼬리를 움직인다. 즉 꼬리가 있던 칸을 다시 0으로 바꾼다.
//skill.3 - 다음으로 이동할 칸이 이차원 N을 벗어나거나 2 즉 뱀의 몸체일 경우 break문을 통해 빠져나간다.
//skill.4 - 방향 전환 함수를 구현한다.

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <deque>

using namespace std;

int N;
int K;
int L;

int board[100][100];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int totalTime = 0;

vector<pair<int, char>> direction;

int change(char d, int n){
    if (d == 'D') {
        if (n == 0) {
            n = 1;
        }
        else if (n == 1){
            n = 2;
        }
        else if (n == 2){
            n = 3;
        }
        else if (n == 3){
            n = 0;
        }
    }
    else if (d == 'L'){
        if (n == 0) {
            n = 3;
        }
        else if (n == 1){
            n = 0;
        }
        else if (n == 2){
            n = 1;
        }
        else if (n == 3){
            n = 2;
        }
    }
    return n;
}

int main(void){
    
    cin >> N;
    cin >> K;
    
    for (int i = 0; i < K; i++) {
        int x;
        int y;
        cin >> x >> y;
        board[x - 1][y - 1] = 1;
    }
    cin >> L;
    for (int i = 0; i < L; i++) {
        int time;
        char dir;
        cin >> time >> dir;
        direction.push_back(make_pair(time, dir));
    }
    deque<pair<pair<int, int>, int>> snake;
    snake.push_back(make_pair(make_pair(0, 0), 0));
    
    while (!snake.empty()) {
        totalTime += 1;
        int cx, cy, cdir;
        cx = snake.back().first.first;
        cy = snake.back().first.second;
        cdir = snake.back().second;
        snake.pop_back();
        int nx = cx + dx[cdir];
        int ny = cy + dy[cdir];
        snake.push_back(make_pair(make_pair(cx, cy), cdir));
        
        if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
            if (board[nx][ny] == 0) {
                snake.push_back(make_pair(make_pair(nx, ny), cdir));
                board[nx][ny] = 2;
                int ox, oy, odir;
                ox = snake.front().first.first;
                oy = snake.front().first.second;
                odir = snake.front().second;
                snake.pop_front();
                board[ox][oy] = 0;
            }
            else if (board[nx][ny] == 1){
                snake.push_back(make_pair(make_pair(nx, ny), cdir));
                board[nx][ny] = 2;
            }
            else if (board[nx][ny] == 2){
                break;
            }
            for (int i = 0; i < L; i++) {
                if (direction.at(i).first == totalTime) {
                    char dirInfo = direction.at(i).second;
                    int newDir = change(dirInfo, cdir);
                    int newInfo1, newInfo2, newInfo3;
                    newInfo1 = snake.back().first.first;
                    newInfo2 = snake.back().first.second;
                    newInfo3 = snake.back().second;
                    snake.pop_back();
                    snake.push_back(make_pair(make_pair(newInfo1, newInfo2), newDir));
                }
            }
        }
        else{
            break;
        }
    }
    cout << totalTime;
    
    return 0;
}
