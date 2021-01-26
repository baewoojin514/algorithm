//N과 M(8)(15657)
//dfs 재귀로 해결한다.
//입력되는 N개의 수 중 M개를 고르고 출력한다.
//재귀 함수의 limit == M이면 각 수열을 출력한다.
//skill.1 - 입력 받은 수를 정렬해야 한다.
//skill.2 - 중복이 가능하다.
//skill.3 - 중복이 가능하고 수열은 비내림차순 이어야 한다.
//skill.4 - parameter로 index를 사용하고 중복허용을 위해 j + 1 이 아니라 j로 재귀함수를 호출한다.

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

void dfs(int index, int limit){
    if (limit == M) {
        for (int i = 0; i < M; i++) {
            cout << temp[i] << " ";
        }
        cout << "\n";
        //endl을 사용하면 시간초과가 발생한다.
        return;
    }
    for (int j = index; j < N; j++) {
        temp[limit] = num.at(j);
        dfs(j, limit + 1);
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
    dfs(0, 0);
  
    return 0;
}
