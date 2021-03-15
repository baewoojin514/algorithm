//캠프 준비(16938)
//dfs 재귀로 해결할 수 있다(N 과 M 응용).
//skill.1 - M의 범위 2 ~ N
//skill.2 - check 함수를 구현한다(L <= sum <= R, max(vec) - min(vec) >= X).

#include <algorithm>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#define MAX 15

using namespace std;

int N, L, R, X;
vector<int> num;
int visited[MAX];
vector<int> temp;

int result = 0;
int M;


void dfs(int idx, int limit){
    if (limit == M) {
        int min = *min_element(temp.begin(), temp.end());
        int max = *max_element(temp.begin(), temp.end());
        int tempSum = 0;
        for (int i = 0; i < temp.size(); i++) {
            tempSum += temp[i];
        }
        if (max - min >= X && tempSum <= R && tempSum >= L) {
            result += 1;
        }
        return;
    }
    for (int i = idx; i < N; i++) {
        if (visited[i] == 0) {
            temp[limit] = num[i];
            visited[i] = 1;
            dfs(i, limit + 1);
            temp[limit] = 0;
            visited[i] = 0;
        }
    }
}

int main(void){
    cin >> N >> L >> R >> X;
    for (int i = 0; i < N; i++) {
        int input;
        cin >> input;
        num.push_back(input);
    }
    for (int i = 2; i <= N; i++) {
        M = i;
        temp.resize(i);
        dfs(0, 0);
        temp.clear();
        memset(visited, 0, sizeof(visited));
    }
    cout << result;
    return 0;
}
