//애너그램(6443)
//N과 M을 응용하여 해결할 수 있다.
//skill.1 - 입력으로 들어오는 문자열을 정렬한다.
//skill.2 - dfs 함수의 초기에 limit == len - 1 이면 문자열이 집합에 있는지 확인후 없다면 삽입하고 출력한다.
//시간초과가 발생하였다.

#include <algorithm>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int N;
set<string> canbe;
//집합을 통해 문자열의 중복을 확인한다.
vector<int> visited;
vector<char> tmpC;

void dfs(string S, int cnt, int limit){
    if (cnt == limit) {
        if (canbe.find(S) == canbe.end()) {
            canbe.insert(S);
            cout << S << '\n';
            return;
        }
    }
    for (int j = 0; j < limit; j++) {
        if (visited[j] == 0) {
            S  += tmpC[j];
            visited[j] = 1;
            dfs(S, cnt + 1, limit);
            visited[j] = 0;
            S.erase(cnt);
        }
    }
}

int main(void){
    cin >> N;
    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        sort(tmp.begin(), tmp.end());
        tmpC.resize(tmp.size());
        for (int j = 0; j < tmp.size(); j++) {
            tmpC[j] = tmp[j];
        }
        string tmpS = "";
        int tmpLen = tmp.size();
        visited.resize(tmpLen);
        dfs(tmpS, 0, tmpLen);
        tmpC.clear();
        //전역변수 임으로 clear를 통해 비워준다.
    }
    return 0;
}
//애너그램(6443)
//N과 M을 응용하여 해결할 수 있다.
//skill.1 - 입력으로 들어오는 문자열을 정렬한다.
//skill.2 - dfs 함수의 초기에 limit == len - 1 이면 문자열이 집합에 있는지 확인후 없다면 삽입하고 출력한다.

#include <algorithm>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>

using namespace std;

int N;

void dfs(string S, int cnt, int limit){
    if (cnt == limit) {
        cout << S << '\n';
        return;
    }
    for (int j = cnt; j < limit; j++) {
        //중복을 집합을 통해 확인하는 방법보다 문자열의 위치를 바꿔주는 방식이 효율적이다.
        if (j != cnt && S[j] == S[cnt]) {
            //다른 위치의 문자인데 같은 문자인 경우는 그냥 넘어간다.
            continue;
        }
        if (S[j] != S[cnt]) {
            //문자가 다른 경우 그 위치를 바꿔준다.
            char c = S[j];
            S[j] = S[cnt];
            S[cnt] = c;
        }
        dfs(S, cnt + 1, limit);
    }
}

int main(void){
    cin >> N;
    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        sort(tmp.begin(), tmp.end());
        dfs(tmp, 0, tmp.size());
    }
    return 0;
}
