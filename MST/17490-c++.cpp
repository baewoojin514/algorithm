//일감호에 다리 놓기(17490)
//MST로 해결할 수 있다(disjoint set + pq).
//skill.1 - 공사 중인 강의실을 제외한 곳들을 union_find를 통해 연결한다.
//skill.2 - 0을 와우도로 가정하고 0과 각 강의실을 연결하는 간선을 vector에 저장한다.
//skill.3 - MST를 만들고 totalCost가 k 이하이면서 총 만들어진 간선의 개수가 n이라면 YES를 출력한다.

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#define MAX 1000001

using namespace std;


int parent[MAX];
int connected[MAX];

vector<pair<pair<long long, int>, int>> edge;
int N, M;
long long totalCost;
long long K;

int find_parent(int X){
    if (parent[X] != X) {
        parent[X] = find_parent(parent[X]);
    }
    return parent[X];
}

void union_find(int a, int b){
    a = find_parent(a);
    b = find_parent(b);
    
    if (a > b) {
        parent[a] = b;
    }
    else{
        parent[b] = a;
    }
    return;
}

int main(void){
    cin >> N >> M >> K;
    for (int i = 1; i < N + 1; i++) {
        long long input;
        cin >> input;
        parent[i] = i;
        edge.push_back({{input, 0}, i});
        //i강의실과 와우도를 연결한다.
    }
    
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        if (max(a, b) == min(a, b) + 1) {
            connected[min(a, b)] = 1;
        }
        else{
            connected[max(a, b)] = 1;
        }
    }
    int tempCnt = 0;
    for (int i = 1; i < N + 1; i++) {
        if (!connected[i]) {
            if (i == N) {
                union_find(i, 1);
            }
            else{
                union_find(i, i + 1);
            }
            tempCnt += 1;
            //공사중이 아닌 강의실을 합집합으로 만들어 주고
        }
    }
    
    if (tempCnt >= N - 1) {
        cout << "YES\n";
        return 0;
    }
    
    
    sort(edge.begin(), edge.end());
    for (int i = 0; i < edge.size(); i++) {
        long long cost = edge[i].first.first;
        int a = edge[i].first.second;
        int b = edge[i].second;
        
        if (tempCnt == N || totalCost >= K) {
            break;
        }
        
        if (find_parent(a) != find_parent(b)) {
            totalCost += cost;
            tempCnt += 1;
            union_find(a, b);
        }
    }
    
    if (totalCost <= K && tempCnt == N) {
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
    
    return 0;
}
