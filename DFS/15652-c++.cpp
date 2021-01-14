//N과 M(4)(15652)
//dfs 재귀로 해결한다.
//1부터 N까지의 수중 M개를 고르고 출력한다.
//재귀 함수의 limit == M이면 각 수열을 출력한다.
//skill.1 - 중복이 허용된다.
//skill.2 - 수열은 비내림차순 즉 다음 수는 현재 수 이상의 수만 추가될 수 있다.
//skill.3 - visited 리스트를 사용해 중복 체크하지 않고 index를 parameter로 사용해 dfs함수를 호출한다.

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

#define MAX 9

using namespace std;

int N;
int M;

int temp[MAX];

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
        temp[limit] = j;
        dfs(j, limit + 1);
        temp[limit] = 0;
    }
    
}

int main(void){
    
    cin >> N >> M;
    dfs(1, 0);
  
    return 0;
}
