//게임 개발(1516)
//위상정렬로 해결할 수 있다.

#include <algorithm>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <deque>
#include <vector>
#define MAX 501

using namespace std;

int N;
int indegree[MAX];
int result[MAX];
int workTime[MAX];

vector<int> graph[MAX];
deque<int> q;

int main(void){
    cin >> N;
    for (int i = 1; i < N + 1; i++) {
        int times;
        cin >> times;
        workTime[i] = times;
        while (1) {
            int tmp;
            cin >> tmp;
            if (tmp == -1) {
                break;
            }
            indegree[i] += 1;
            graph[tmp].push_back(i);
        }
    }
    for (int i = 1; i < N + 1; i++) {
        if (indegree[i] == 0) {
            result[i] = workTime[i];
            q.push_back(i);
        }
    }
    while (!q.empty()) {
        int cx;
        cx = q.front();
        
        q.pop_front();
        for (int i = 0; i < graph[cx].size(); i++) {
            int nx = graph[cx][i];
            indegree[nx] -= 1;
            if (indegree[nx] == 0) {
                q.push_back(nx);
            }
            result[nx] = max(result[nx], result[cx] + workTime[nx]);
        }
    }
    for (int i = 1; i < N + 1; i++) {
        cout << result[i] << "\n";
    }
    
    return 0;
}
