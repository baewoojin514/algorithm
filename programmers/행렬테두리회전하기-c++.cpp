#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

vector<int> answer;
vector<vector<int>> board;
deque<int> dq;

int rotation(int stx, int sty, int edx, int edy){
    dq.clear();
    
    int tmpSty1 = sty;
    for (int i = 0; i < edy - sty; i++) {
        dq.push_back(board[stx][tmpSty1]);
        tmpSty1 += 1;
    }
    
    int tmpStx1 = stx;
    for (int i = 0; i < edx - stx; i++) {
        dq.push_back(board[tmpStx1][edy]);
        tmpStx1 += 1;
    }
    
    int tmpEdy1 = edy;
    for (int i = 0; i < edy - sty; i++) {
        dq.push_back(board[edx][tmpEdy1]);
        tmpEdy1 -= 1;
    }
    
    int tmpEdx1 = edx;
    for (int i = 0; i < edx - stx; i++) {
        dq.push_back(board[tmpEdx1][sty]);
        tmpEdx1 -= 1;
    }
    
    int tempNum = dq.back();
    dq.pop_back();
    dq.push_front(tempNum);
    
    int idx = -1;
    
    int tmpSty2 = sty;
    for (int i = 0; i < edy - sty; i++) {
        idx += 1;
        board[stx][tmpSty2] = dq[idx];
        tmpSty2 += 1;
    }
    
    int tmpStx2 = stx;
    for (int i = 0; i < edx - stx; i++) {
        idx += 1;
        board[tmpStx2][edy] = dq[idx];
        tmpStx2 += 1;
    }
    
    int tmpEdy2 = edy;
    for (int i = 0; i < edy - sty; i++) {
        idx += 1;
        board[edx][tmpEdy2] = dq[idx];
        tmpEdy2 -= 1;
    }
    
    int tmpEdx2 = edx;
    for (int i = 0; i < edx - stx; i++) {
        idx += 1;
        board[tmpEdx2][sty] = dq[idx];
        tmpEdx2 -= 1;
    }
    
    int tempMin = 10001;
    for (int i = 0; i < dq.size(); i++) {
        tempMin = min(tempMin, dq[i]);
    }
    
    return tempMin;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    board.resize(rows, vector<int>(columns, 1));
    
    int sumNum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            board[i][j] += sumNum;
            sumNum += 1;
        }
    }
    for (int i = 0; i < queries.size(); i++) {
        int stx = queries[i][0];
        int sty = queries[i][1];
        
        int edx = queries[i][2];
        int edy = queries[i][3];
        
        answer.push_back(rotation(stx -= 1, sty -=1, edx -=1, edy -= 1));
    }

    return answer;
}
