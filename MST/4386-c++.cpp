//별자리 만들기(4386)
//MST로 해결할 수 있다.
//skill.1 - 좌표간 모든 조합으로 좌표간 거리를 cost로 간선을 만든다.
//skill.2 - 1을 통해 얻은 간선 정보로 MST를 만들고 totalCost를 출력한다.

#include <algorithm>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <math.h>
#define MAX 100

using namespace std;

vector<pair<double, double>> point;
vector<pair<pair<double, int>, int>> edges;
//좌표간 거리와 i, j index를 저장한다.

int n;
int parent[MAX];
double totalCost;

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
    cin >> n;
    for (int i = 0; i < n; i++) {
        double a, b;
        cin >> a >> b;
        point.push_back({a, b});
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double x1, y1, x2, y2;
            x1 = point[i].first; y1 = point[i].second;
            x2 = point[j].first; y2 = point[j].second;
            
            double tempCost = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
            edges.push_back({{tempCost, i}, j});
        }
    }
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
    sort(edges.begin(), edges.end());
    for (int i = 0; i < edges.size(); i++) {
        double cost;
        int a, b;
        cost = edges[i].first.first;
        a = edges[i].first.second;
        b = edges[i].second;
        
        if (find_parent(a) != find_parent(b)) {
            union_find(a, b);
            totalCost += cost;
        }
    }
    cout.precision(3);
    //소수점 둘째 자리로 출력을 고정한다.
    cout << totalCost;
    
    return 0;
}
