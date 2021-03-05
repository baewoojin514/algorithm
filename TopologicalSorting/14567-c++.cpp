//선수과목(Prerequisite)
//위상정렬을 사용해서 해결할 수 있다.

#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <deque>
#define MAX 1001

using namespace std;

int N, M;
vector<int> graph[MAX];
int indegree[MAX];
int result[MAX];
deque<pair<int, int>> q;

int main(void){
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        indegree[b] += 1;
    }
    for (int i = 1; i < N + 1; i++) {
        if (indegree[i] == 0) {
            q.push_back({1, i});
            result[i - 1] = 1;
        }
    }
    
    while (!q.empty()) {
        int year, cx;
        year = q.front().first;
        cx = q.front().second;
        
        q.pop_front();
        
        for (int i = 0; i < graph[cx].size(); i++) {
            indegree[graph[cx][i]] -= 1;
            if (indegree[graph[cx][i]] == 0) {
                q.push_back({year + 1, graph[cx][i]});
                result[graph[cx][i] - 1] = year + 1;
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        printf("%d ", result[i]);
    }
    return 0;
}
