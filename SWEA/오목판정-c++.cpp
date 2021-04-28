#include <iostream>
#define MAX 20

using namespace std;

char board[MAX][MAX];
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

void initialize(){
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            board[i][j] = '.';
        }
    }
    return;
}

bool inRange(int N, int X, int Y){
    return X >= 0 && X < N && Y >= 0 && Y < N;
}

void checkOmok(int N, int test_case){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == '.') {
                continue;
            }
            for (int k = 0; k < 8; k++) {
                int stx = i;
                int sty = j;
                int tempCnt = 1;
                while (true) {
                    stx += dx[k];
                    sty += dy[k];
                    if (board[stx][sty] == '.' || !inRange(N, stx, sty)) {
                        break;
                    }
                    tempCnt += 1;
                }
                if (tempCnt >= 5) {
                    cout << "#" << test_case << " " << "YES" << "\n";
                    return;
                }
            }
        }
    }
    cout << "#" << test_case << " " << "NO" << "\n";
}

int main(void)
{
    int test_case;
    int T;
    
    cin>>T;
  
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int N;
        cin >> N;
        initialize();
        for (int i = 0; i < N; i++) {
            scanf("%s", board[i]);
        }
        checkOmok(N, test_case);
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
