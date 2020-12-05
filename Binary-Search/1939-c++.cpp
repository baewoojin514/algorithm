//중량제한(1939)
//python3와 같은 방식으로 구현한다.
//bfs와 이진탐색을 활용해서 문제를 풀이한다.
//python3에서는 이차원 리스트를 사용하였지만 c++에서는 vector를 배열 형식으로 선언해서 간선과 중량 정보를 저장한다.
//이진탐색을 하는 함수를 구현한다.

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int N;
int M;

int minValue = 1000000001;
int maxValue = 0;
int src;
int dest;
int result;
int visited[100001];

vector<pair<int, int>> graph[100001];
//vector를 배열 형태로 선언했다.

bool binarySearch(int weight){
    memset(visited, 0, sizeof(visited));
    queue<int> q;
    visited[src] = 1;
    q.push(src);
    
    while (!q.empty()) {
        int cx = q.front();
        q.pop();
        for (int i = 0; i < graph[cx].size(); i++) {
            int nx = graph[cx][i].first;
            int nw = graph[cx][i].second;
            if (visited[nx] == 0 && nw >= weight) {
                visited[nx] = 1;
                q.push(nx);
            }
        }
        
    }
    if (visited[dest] == 1) {
        return true;
    }
    return false;
}

int main(void){
    cin >> N >> M;
    
    for (int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        graph[A - 1].push_back(make_pair(B - 1, C));
        graph[B - 1].push_back(make_pair(A - 1, C));
        maxValue = max(maxValue, C);
        minValue = min(minValue, C);
    }
    cin >> src >> dest;
    
    src -= 1;
    dest -= 1;
    
    while (minValue <= maxValue) {
        int mid = (minValue + maxValue) / 2;
        if (binarySearch(mid)) {
            result = mid;
            minValue = mid + 1;
        }
        else{
            maxValue = mid - 1;
        }
    }
    cout << result;

    return 0;
}
