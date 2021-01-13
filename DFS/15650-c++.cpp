//N과 M(1)(15650)
//dfs 재귀로 해결한다.
//1부터 N까지의 수중 N개를 고르고 출력한다.
//재귀 함수의 limit == M이면 각 수열을 출력한다.
//skill.1 - index를 재귀 함수의 parameter로 넘겨 현재 수보다 큰 수를 선택할 수 있게한다.
//skill.2 - endl은 buffer flash 때문에 "\n"보다 속도가 느리다.

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <deque>

#define MAX 9

using namespace std;

int N;
int M;

int temp[MAX];

int visited[MAX];

void dfs(int index, int limit){
    if (limit == M) {
        for (int i = 0; i < M; i++) {
            cout << temp[i] << " ";
        }
        cout << "\n";
        //endl을 사용하면 시간초과가 발생한다.
        return;
    }
    for (int j = index; j < N + 1; j++) {
        if (visited[j] == 0) {
            visited[j] = 1;
            temp[limit] = j;
            dfs(j + 1, limit + 1);
            visited[j] = 0;
            temp[limit] = 0;
        }
    }
    
}

int main(void){
    
    cin >> N >> M;
    dfs(1, 0);
  
    return 0;
}
