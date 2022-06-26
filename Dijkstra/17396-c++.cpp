#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cstdio>
#define INF 10000000001
#define MAX 100000
#define ll long long

using namespace std;

int N, M;
priority_queue<pair<ll, int>> pq;
ll int dis[MAX];
int nexus[MAX];
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
            
            if (nexus[nx] && nx != N - 1) {
                continue;
            }
            ll newDist = dist + cost;
            if (newDist < dis[nx]) {
                dis[nx] = newDist;
                pq.push({-newDist, nx});
            }
        }
    }
}

int main(void){
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> nexus[i];
    }
    fill(dis, dis + MAX, INF);
    
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    
    dijkstra(0);
    
    if (dis[N - 1] >= INF) {
        cout << -1;
    }
    else{
        cout << dis[N - 1];
    }

    return 0;
}
