#include <iostream>
#include <vector>
#include <cstring>

#define MAX 20

using namespace std;

int board[MAX][MAX];
vector<int> score;

int main(void)
{
    int test_case;
    int T;
    
    cin>>T;
   
    for(test_case = 1; test_case <= T; ++test_case)
    {
        memset(board, 0, sizeof(board));
        score.clear();
        int N, K;
        
        cin >> N >> K;
        
        int tempCnt = 1;
        
        for (int i = 0; i < N; i++) {
            if (i % 2 == 0) {
                for (int j = 0; j < K; j++) {
                    board[i][j] = tempCnt;
                    tempCnt += 1;
                }
            }
            else if (i % 2 == 1) {
                for (int j = K - 1; j >= 0; j--) {
                    board[i][j] = tempCnt;
                    tempCnt += 1;
                }
            }
        }
        for (int i = 0; i < K; i++) {
            int tempSum = 0;
            for (int j = 0; j < N; j++) {
                tempSum += board[j][i];
            }
            score.push_back(tempSum);
        }
        cout << "#" << test_case << " ";
        for (int i = 0; i < K; i++) {
            cout << score[i] << " ";
        }
        cout << "\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
