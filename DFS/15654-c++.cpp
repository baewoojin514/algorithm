//N과 M(5)(15654)
//dfs 재귀로 해결한다.
//입력된 N개의 수중 M개를 고르고 출력한다.
//재귀 함수의 limit == M이면 각 수열을 출력한다.
//skill.1 - 입력 받은 수의 배열을 정렬해야 한다.
//skill.2 - 사전순으로 출력해야 하기 때문에 정렬한다.
//skill.3 - resize를 통해 vector의 크기를 지정해서 배열처럼 사용할 수 있다.

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
int visited[MAX];
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
        if (visited[j] == 0) {
            temp[limit] = num[j];
            visited[j] = 1;
            dfs(limit + 1);
            temp[limit] = 0;
            visited[j] = 0;
        }
    }
    
}

int main(void){
    
    cin >> N >> M;
    num.resize(N);
    //resize를 통해 vector의 크기를 미리 지정할 수 있다.
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }
    sort(num.begin(), num.end());
    dfs(0);
  
    return 0;
}
