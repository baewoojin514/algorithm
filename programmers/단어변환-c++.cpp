//단어 변환(programmers)
//dfs로 해결할 수 있다.
//skill.1 - begin은 words에 포함된 단어로 밖에 변할 수 없다.
//skill.2 - visited가 0인 경우 해당 단어와 begin의 다른 문자를 count하고 count가 1이라면 cnt += 1을 하고 dfs함수를 호출한다.
//skill.3 - begin과 target이 같아지는 경우 cnt를 최소값으로 갱신한다.

#include <string>
#include <vector>
#include <cstring>
#define INF 1e9

using namespace std;

string copy_target;
vector<int> visited;
vector<string> copy_word;
int result;
int N;

void dfs(string begin, int cnt){
    if (begin == copy_target) {
        result = min(result, cnt);
        return;
    }
    for (int i = 0; i < N; i++) {
        if (visited[i] == 0) {
            int tempCnt = 0;
            for (int j = 0; j < copy_word[i].size(); j++) {
                if (begin[j] != copy_word[i][j]) {
                    tempCnt += 1;
                }
            }
            if (tempCnt == 1) {
                visited[i] = 1;
                dfs(copy_word[i], cnt + 1);
                visited[i] = 0;
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    result = INF;
    copy_target = target;
    copy_word = words;
    visited.resize(words.size());
    N = words.size();
    int answer = 0;
    dfs(begin, 0);
    if (result == INF) {
        answer = 0;
    }
    else{
        answer = result;
    }
    return answer;
}
