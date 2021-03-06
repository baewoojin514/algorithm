//음악프로그램(2623)
//위상정렬로 해결할 수 있다.
//가수 순서의 전후 관계를 통해 graph vector를 만든다.

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#define MAX 10001

using namespace std;

vector<int> graph[MAX];
int indegree[MAX];
vector<int> result;
deque<int> q;
int N, M;

int main(void){
    scanf("%d %d", &N, &M);
    
    for (int i = 0; i < M; i++) {
        int cnt;
        cin >> cnt;
        vector<int> temp;
        for (int j = 0; j < cnt; j++) {
            int tmp;
            cin >> tmp;
            temp.push_back(tmp);
        }
        for (int j = 0; j < temp.size() - 1; j++) {
            graph[temp[j]].push_back(temp[j + 1]);
            indegree[temp[j + 1]] += 1;
        }
        temp.clear();
    }
    for (int j = 1; j < N + 1; j++) {
        if (indegree[j] == 0) {
            q.push_back(j);
        }
    }
    while (!q.empty()) {
        int cx;
        cx = q.front();
        result.push_back(cx);
        q.pop_front();
        
        for (int k = 0; k < graph[cx].size(); k++) {
            int nx;
            nx = graph[cx][k];
            indegree[nx] -= 1;
            if (indegree[nx] == 0) {
                q.push_back(nx);
            }
        }
    }
    if (result.size() != N) {
        cout << 0;
    }
    else{
        for (int i = 0; i < N; i++) {
            cout << result[i] << "\n";
        }
    }
    return 0;
}
