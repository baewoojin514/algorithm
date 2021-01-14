//N과 M(3)(15651)
//dfs 재귀로 해결한다.
//1부터 N까지의 수중 N개를 고르고 출력한다.
//재귀 함수의 limit == M이면 각 수열을 출력한다.
//skill.1 - 중복이 허용된다.
//skill.2 - visited 배열을 사용하지 않는다. 즉 중복을 허용한다.

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

void dfs(int limit){
    if (limit == M) {
        for (int i = 0; i < M; i++) {
            cout << temp[i] << " ";
        }
        cout << "\n";
        //endl을 사용하면 시간초과가 발생한다.
        return;
    }
    for (int j = 1; j < N + 1; j++) {
        temp[limit] = j;
        dfs(limit + 1);
        temp[limit] = 0;
    }
    
}

int main(void){
    
    cin >> N >> M;
    dfs(0);
  
    return 0;
}
