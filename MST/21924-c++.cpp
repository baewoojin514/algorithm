#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 5001
#define ll long long

using namespace std;

int N, M;

vector<pair<pair<ll, int>, int>> edges;
vector<int> parent;
vector<int> visited;
ll total;

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
    cin >> N >> M;
    total = 0;
    
    for (int i = 0; i < M; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        edges.push_back({{c, a}, b});
        total += c;
    }
    parent.resize(N + 1);
    visited.resize(N);
    
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }
    sort(edges.begin(), edges.end());
    
    ll tempTotal = 0;
    
    for (auto s : edges) {
        int a, b;
        ll cost;
        cost = s.first.first;
        a = s.first.second;
        b = s.second;
        
        if (find_parent(a) != find_parent(b)) {
            union_find(a, b);
            visited[a - 1] = 1;
            visited[b - 1] = 1;
            tempTotal += cost;
        }
    }
    bool flag = true;
    
    for (int i = 2; i <= N; i++) {
        if (find_parent(1) != find_parent(i)) {
            flag = false;
        }
    }
    
    if (!flag) {
        cout << -1 << "\n";
    }
    else{
        cout << total - tempTotal << "\n";
    }
    
    return 0;
}
