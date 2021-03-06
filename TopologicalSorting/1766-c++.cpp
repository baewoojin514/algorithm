//문제집(1766)
//풀어야 할 문제의 전후 관계를 graph 리스트로 만든다.
//최대한 쉬운 문제 즉 index가 작은 문제를 풀어야한다.
//skill.1 - 우선순위 큐를 사용해서 index가 가장 작은 node를 pop한다.
//skill.2 - 위상정렬을 적용해서 해결할 수 있다.

#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <queue>
#define MAX 32001

using namespace std;

int indegree[MAX];
vector<int> graph[MAX];
int N, M;

priority_queue<int> pq;
vector<int> result;

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
            pq.push(-i);
        }
    }
    while (!pq.empty()) {
        int cx;
        cx = -pq.top();
        result.push_back(cx);
        pq.pop();
        
        for (int i = 0; i < graph[cx].size(); i++) {
            indegree[graph[cx][i]] -= 1;
            if (indegree[graph[cx][i]] == 0) {
                pq.push(-graph[cx][i]);
            }
        }
    }
    for (auto i : result) {
        printf("%d ", i);
    }
    
    return 0;
}
