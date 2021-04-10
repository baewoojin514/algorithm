//2 x n 타일링(programmers)
//dfs로 해결할 수 있다.
//skill.1 - 1 또는 2를 더해서 n을 만들 수 있는 dfs로 구현한다.
//skill.2 - tempSum == n인 경우 answer += 1을 한다.

#include <string>
#include <vector>

using namespace std;

int N;
int canbe[2] = {1, 2};

void dfs(int tempSum, int &result){
    if (tempSum == N) {
        result += 1;
        return;
    }
    for (int i = 0; i < 2; i++) {
        if (tempSum + canbe[i] <= N) {
            dfs(tempSum + canbe[i], result);
        }
    }
}

int solution(int n) {
    int answer = 0;
    N = n;
    dfs(0, answer);
    
    return answer;
}
//2 x n 타일링(programmers)
//dp로 해결할 수 있다.
//skill.1 - i - 1인 경우에 세로 막대기 하나를 추가하면 된다.
//skill.2 - i - 2인 경우에 가로 막대기 두개를 추가하면 된다.
//skill.3 - i - 2에 세로 막대기 두개를 추가하는 경우는 1과 겹친다.
//skill.4 - [i] = [i - 1] + [i - 2]이다.

#include <string>
#include <vector>
#define MAX 60001

using namespace std;

int dp[MAX];

int solution(int n) {
    int answer = 0;
    dp[1] = 1;
    dp[2] = 2;
    
    if (n >= 3) {
        for (int i = 3; i < n + 1; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
        }
    }
    
    answer = dp[n];
    return answer;
}
