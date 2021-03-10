//선발명단(3980)
//dfs 재귀로 해결할 수 있다.
//중복이 허락되지 않는 N과 M의 풀이와 유사하다.

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#define MAX 11
 
using namespace std;

int soccer[MAX][MAX];
int visited[MAX];
int C;
int result = 0;

void dfs(int limit, int tempSum){
    if (limit == MAX) {
        result = max(result, tempSum);
        return;
    }
    for (int i = 0; i < MAX; i++) {
        if (soccer[limit][i] != 0 && visited[i] == 0) {
            visited[i] = 1;
            dfs(limit + 1, tempSum + soccer[limit][i]);
            visited[i] = 0;
            //선수별로 가능한 모든 포지션에 배정하는 방식으로 구현한다.
        }
    }
}

int main(void){
    cin >> C;
    for (int i = 0; i < C; i++) {
        memset(soccer, 0, sizeof(soccer));
        memset(visited, 0, sizeof(visited));
        
        for (int j = 0; j < MAX; j++) {
            for (int k = 0; k < MAX; k++) {
                cin >> soccer[j][k];
            }
        }
        dfs(0, 0);
        cout << result << "\n";
        result = 0;
    }
    return 0;
}
