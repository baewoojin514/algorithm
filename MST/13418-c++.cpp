#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 1000

using namespace std;

int N, M;

vector<pair<pair<int, int>, int>> edges;
int parent[MAX];

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

void reset_parent(){
    for (int i = 0; i <= N; i++) {
        parent[i] = i;
    }
}


int main(void){
    cin >> N >> M;
    
    for (int i = 0; i < M + 1; i++) {
        int a, b, c;
        
        cin >> a >> b >> c;
        
        edges.push_back({{c, a}, b});
    }
    sort(edges.begin(), edges.end());
    
    reset_parent();
    
    int tempTotal1 = 0;
    
    for (int i = 0; i < M + 1; i++) {
        int cost, a, b;
        
        cost = edges[i].first.first;
        a = edges[i].first.second;
        b = edges[i].second;
        
        if (find_parent(a) != find_parent(b)) {
            if (cost == 0) {
                tempTotal1 += 1;
            }
            union_find(a, b);
        }
    }
    
    reset_parent();
    
    int tempTotal2 = 0;
    
    for (int i = M; i >= 0; i--) {
        int cost, a, b;
        
        cost = edges[i].first.first;
        a = edges[i].first.second;
        b = edges[i].second;
        
        if (find_parent(a) != find_parent(b)) {
            if (cost == 0) {
                tempTotal2 += 1;
            }
            union_find(a, b);
        }
    }
    
    cout << tempTotal1 * tempTotal1 - tempTotal2 * tempTotal2;
    
    return 0;
}
