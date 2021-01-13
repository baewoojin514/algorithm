//N과 M(1)(15649)
//dfs 재귀로 해결한다.
//1부터 N까지의 수중 N개를 고르고 출력한다.
//재귀 함수의 limit == M이면 각 수열을 출력한다.

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <deque>

using namespace std;

int N;
int M;

deque<int> temp;

int visited[9];

void dfs(int limit){
    if (limit == M) {
        for (int i = 0; i < temp.size(); i++) {
            cout << temp.at(i) << " ";
        }
        cout << endl;
    }
    for (int j = 1; j < N + 1; j++) {
        if (visited[j] == 0) {
            visited[j] = 1;
            temp.push_back(j);
            dfs(limit + 1);
            visited[j] = 0;
            temp.pop_back();
        }
    }
    
}

int main(void){
    
    cin >> N >> M;
    dfs(0);
  
    return 0;
}
//N과 M(1)(15649)
//dfs 재귀로 해결한다.
//1부터 N까지의 수중 N개를 고르고 출력한다.
//재귀 함수의 limit == M이면 각 수열을 출력한다.

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
        if (visited[j] == 0) {
            visited[j] = 1;
            temp[limit] = j;
            dfs(limit + 1);
            visited[j] = 0;
            temp[limit] = 0;
        }
    }
    
}

int main(void){
    
    cin >> N >> M;
    dfs(0);
  
    return 0;
}
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <deque>

using namespace std;

int N;
int M;

deque<int> temp;

int visited[9];

void dfs(int limit){
    if (limit == M) {
        for (int i = 0; i < temp.size(); i++) {
            cout << temp.at(i) << " ";
        }
        cout << "\n";
    }
    for (int j = 1; j < N + 1; j++) {
        if (visited[j] == 0) {
            visited[j] = 1;
            temp.push_back(j);
            dfs(limit + 1);
            visited[j] = 0;
            temp.pop_back();
        }
    }
    
}

int main(void){
    
    cin >> N >> M;
    dfs(0);
  
    return 0;
}
