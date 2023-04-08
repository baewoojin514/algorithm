#include <string>
#include <vector>
#include <cstring>

using namespace std;

int answer = 0;
int numOfNum = 0;

vector<string> tempBabbling;
vector<string> canBe = {"aya", "ye", "woo", "ma"};
int visited[4];

void dfs(int cnt, string temp, int limit){
    if (cnt == limit) {
        for (int i = 0; i < numOfNum; i++) {
            if (tempBabbling[i] == temp) {
                answer += 1;
            }
        }
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (visited[i] == 0) {
            visited[i] = 1;
            dfs(cnt + 1, temp + canBe[i], limit);
            visited[i] = 0;
        }
    }
    
}

int solution(vector<string> babbling) {
    numOfNum = babbling.size();
    tempBabbling = babbling;
    memset(visited, 0, sizeof(visited));
    
    for (int i = 0; i < 4; i++) {
        dfs(0, "", i + 1);
    }
    return answer;
}

