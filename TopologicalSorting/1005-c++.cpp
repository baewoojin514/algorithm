//ACM Craft(1005)
//작업의 전후 관계를 graph vector로 만든다.
//skill.1 - 위상정렬을 적용해서 해결할 수 있다.
//skill.2 - indgree가 0인 작업이 동시에 여러개 발생할 수도 있다.
//skill.3 - 선행작업이 여러개라면 그 중 시간이 가장 많이 걸리는 작업을 해결해야 후행 작업을 할 수 있다.

#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <iostream>
#include <queue>
#define MAX 1001

using namespace std;

int T;
int indegree[MAX];
int result[MAX];
vector<int> graph[MAX];
vector<int> times;
deque<int> q;

int main(void){
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        memset(indegree, 0, sizeof(indegree));
        memset(result, 0, sizeof(result));
        times.clear();
        q.clear();
        for (int i = 0; i < MAX; i++) {
            graph[i].clear();
        }
        int N, K;
        scanf("%d %d", &N, &K);
        for (int j = 0; j < N; j++) {
            int t;
            scanf("%d", &t);
            times.push_back(t);
        }
        for (int j = 0; j < K; j++) {
            int a, b;
            scanf("%d %d", &a, &b);
            graph[a].push_back(b);
            indegree[b] += 1;
        }
        int W;
        scanf("%d", &W);
        for (int i = 1; i < N + 1; i++) {
            if (indegree[i] == 0) {
                result[i] = times[i - 1];
                q.push_back(i);
            }
        }
        while (!q.empty()) {
            int cx;
            cx = q.front();
            
            q.pop_front();
            for (int i = 0; i < graph[cx].size(); i++) {
                indegree[graph[cx][i]] -= 1;
                if (indegree[graph[cx][i]] == 0) {
                    q.push_back(graph[cx][i]);
                }
                result[graph[cx][i]] = max(result[graph[cx][i]], result[cx] + times[graph[cx][i] - 1]);
                //선행 작업이 여러개라면 그중 시간이 가장 많이 걸리는 작업을 해결해야 후행 작업을 해결할 수 있다.
            }
            
        }
        printf("%d\n", result[W]);
    }
   
    return 0;
}
