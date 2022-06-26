#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cstdio>
#define INF 10000000001
#define MAX 5001
#define ll long long

using namespace std;

int n, m;
int s, t;
priority_queue<pair<ll, int>> pq;
ll int dis[MAX];
vector<pair<int, int>> graph[MAX];

void dijkstra(int start){
    dis[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int cx;
        ll dist;
        
        dist = -pq.top().first;
        cx = pq.top().second;
        
        pq.pop();
        
        if (dis[cx] < dist) {
            continue;
        }
        for (int i = 0; i < graph[cx].size(); i++) {
            int nx;
            ll cost;
            
            nx = graph[cx][i].first;
            cost = graph[cx][i].second;
            
            ll newCost = dist + cost;
            
            if (newCost < dis[nx]) {
                dis[nx] = newCost;
                pq.push({-newCost, nx});
            }
        }
    }
}

int main(void){
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    
    cin >> s >> t;
    fill(dis, dis + MAX, INF);
    
    dijkstra(s);
    
    cout << dis[t];
    
    return 0;
}
