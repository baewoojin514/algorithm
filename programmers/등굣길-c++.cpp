//등굣길(programmers)
//dfs와 dp로 해결할 수 있다.
//skill.1 - 방문하지 않았던 곳을 -1을 통해 구분한다.
//skill.2 - 이미 방문했던 곳이면 dp[i][j]를 반환하고 [m][n]에 도착하면 1을 반환한다(목적지로 가는 경우의 수가 1가지 있다는 의미).
//skill.3 - [0][0]을 출력한다.

#include <cstring>
#include <string>
#include <vector>
#define MAX 100

using namespace std;

int board[MAX][MAX];
int dp[MAX][MAX];
int dx[2] = {1, 0};
int dy[2] = {0, 1};

int M, N;

bool inRange(int X, int Y){
    return X >= 0 && X < N && Y >= 0 && Y < M;
}

int dfs(int cx, int cy){
    if (cx == N - 1 && cy == M - 1) {
        return 1;
    }
    if (dp[cx][cy] == -1) {
        dp[cx][cy] = 0;
        for (int i = 0; i < 2; i++) {
            int nx, ny;
            nx = cx + dx[i];
            ny = cy + dy[i];
            if (inRange(nx, ny) && !board[nx][ny]) {
                dp[cx][cy] += dfs(nx, ny);
            }
        }
    }
    return dp[cx][cy];
}

int solution(int m, int n, vector<vector<int>> puddles) {
    memset(board, 0, sizeof(board));
    memset(dp, -1, sizeof(dp));
    M = m;
    N = n;
    for (auto e : puddles) {
        int a = e[0];
        int b = e[1];
        board[b - 1][a - 1] = 1;
    }
    
    int answer = dfs(0, 0);
    return answer % 1000000007;
}
//등굣길(programmers)
//dp로 해결할 수 있다.

#include <cstring>
#include <string>
#include <vector>
#define MAX 101

using namespace std;

int dp[MAX][MAX];

int solution(int m, int n, vector<vector<int>> puddles) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = 1;
        }
    }
    for (int i = 0; i < puddles.size(); i++) {
        int a = puddles[i][0];
        int b = puddles[i][1];
        dp[b][a] = 0;
        
        if (b == 1) {
            for (int i = a; i <= m; i++) {
                dp[b][i] = 0;
            }
        }
        if (a == 1) {
            for (int i = b; i <= n; i++) {
                dp[i][a] = 0;
            }
        }
        //index 0에 해당하는 열이라면 해당 열의 행을 모두 0으로 만들어준다(갈 수 없는 길).
        //index 0에 해당하는 행이라면 해당 행의 열을 모두 0으로 만들어준다(갈 수 없는 길).
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            if (dp[i][j] != 0) {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
            }
        }
    }
    int answer = dp[n][m];
    
    return answer;
}
