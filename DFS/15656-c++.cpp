//N과 M(7)(15656)
//dfs 재귀로 해결한다.
//입력되는 N개의 수 중 M개를 고르고 출력한다.
//재귀 함수의 limit == M이면 각 수열을 출력한다.
//skill.1 - 입력 받은 수를 정렬해야 한다.
//skill.2 - 중복이 가능하다.
//skill.3 - 수열은 사전 순이어야 하지만 중복이 가능하기 때문에 parameter는 limit만 사용해서 재귀함수를 호출한다.

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

#define MAX 9

using namespace std;

int N;
int M;

int temp[MAX];
vector<int> num;

void dfs(int limit){
    if (limit == M) {
        for (int i = 0; i < M; i++) {
            cout << temp[i] << " ";
        }
        cout << "\n";
        //endl을 사용하면 시간초과가 발생한다.
        return;
    }
    for (int j = 0; j < N; j++) {
        temp[limit] = num.at(j);
        dfs(limit + 1);
        temp[limit] = 0;
    }
}

int main(void){
    
    cin >> N >> M;
    num.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> num.at(i);
    }
    sort(num.begin(), num.end());
    dfs(0);
  
    return 0;
}
