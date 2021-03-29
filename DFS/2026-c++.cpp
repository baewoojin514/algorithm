//소풍(2026)
//dfs로 해결할 수 있다.
//skill.1 - 1차원 배열에 친구의 수를 += 1하여 count한다.
//skill.2 - 친구가 k - 1명 미만인 경우 탐색할 필요가 없다.
//skill.3 - dfs 함수와 현재 추가하고자 하는 친구가 이전에 추가된 친구들과 모두 친구 관계인지를 check하는 함수가 필요하다.

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#define MAX 901

using namespace std;

int friends[MAX];
int graph[MAX][MAX];
int visited[MAX];
bool flags = true;

int K, N, F;

bool check(int idx){
    for (int i = 1; i < N + 1; i++) {
        if (i == idx) {
            continue;
        }
        if (visited[i] && !graph[idx][i]) {
            //친구관계가 아닌데 visited에 check되어 있는 경우 false를 return 한다.
            return false;
        }
    }
    return true;
}

void dfs(int idx, int cnt){
    if (!flags) {
        //경우의 수가 여러가지 있을 수도 있다. 따라서 첫 번째 경우를 출력한 이후는 return을 통해 종료한다.
        return;
    }
    if (cnt == K) {
        for (int i = 1; i < N + 1; i++) {
            if (visited[i]) {
                cout << i << "\n";
            }
        }
        flags = false;
        return;
    }
    for (int i = idx + 1; i < N + 1; i++) {
        if (!visited[i] && check(i)) {
            visited[i] = 1;
            dfs(i, cnt + 1);
            visited[i] = 0;
        }
    }
}

int main(void){
    cin >> K >> N >> F;
    //K명을 뽑아야 한다.
    for (int i = 0; i < F; i++) {
        int a, b;
        cin >> a >> b;
        friends[a] += 1;
        friends[b] += 1;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    
    for (int i = 1; i < N + 1; i++) {
        if (friends[i] >= K - 1) {
            //친구가 최소 k - 1명 이어야 총 K 명의 친구 관계를 만들 수 있다.
            visited[i] = 1;
            dfs(1, 1);
            visited[i] = 0;
        }
    }
    if (flags) {
        cout << -1;
    }
    
    return 0;
}
