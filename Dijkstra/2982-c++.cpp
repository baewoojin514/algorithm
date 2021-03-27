//국왕의 방문(2982)
//다익스트라 알고리즘으로 해결할 수 있다.
//skill.1 - 다익스트라 알고리즘을 위해 국왕이 지나가는 도로의 시간을 전처리 해야 한다.
//skill.2 - 현재 목표 지점을 지나가는 시간이 국왕과 곂친다면 국왕이 지나간 후 해당 도로를 지날 수 있다.
//skill.3 - 국왕이 특정 도로를 건너는 시간은 이차원 배열의 vector에 저장한다. <start, end> [p][q] p -> q

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#define MAX 1001
#define INF 1e9

using namespace std;

vector<pair<int, int>> graph[MAX];
vector<pair<int, int>> king[MAX][MAX];
int dist[MAX];
int adjacency[MAX][MAX];
int N, M;
int A, B, K, G;

int main(void){
    cin >> N >> M;
    cin >> A >> B >> K >> G;
    //상근이는 K에 출발하고 왕은 0에 출발한다.
    
    vector<int> kingsRoad;
    for (int i = 0; i < G; i++) {
        int input;
        cin >> input;
        kingsRoad.push_back(input);
    }
    for (int i = 0; i < M; i++) {
        int U, V, L;
        cin >> U >> V >> L;
        adjacency[U][V] = L;
        adjacency[V][U] = L;
        //왕의 이동 시간을 위해 도로의 이동시간을 저장한다(양방향).
        graph[U].push_back(make_pair(V, L));
        graph[V].push_back(make_pair(U, L));
    }
    int kingTime = 0;
    for (int i = 0; i < G - 1; i++) {
        int tmpS, tmpE;
        tmpS = kingsRoad[i];
        tmpE = kingsRoad[i + 1];
        king[tmpS][tmpE].push_back(make_pair(kingTime, kingTime + adjacency[tmpS][tmpE]));
        king[tmpE][tmpS].push_back(make_pair(kingTime, kingTime + adjacency[tmpE][tmpS]));
        kingTime += adjacency[tmpS][tmpE];
        //왕의 이동 시간을 갱신한다.
    }
    for (int i = 0; i < MAX; i++) {
        dist[i] = INF;
    }
    priority_queue<pair<int, int>> pq;
    dist[A] = K;
    pq.push(make_pair(-K, A));
    
    while (!pq.empty()) {
        int tempTime, cx;
        tempTime = -pq.top().first;
        cx = pq.top().second;
        
        pq.pop();
        
        if (dist[cx] < tempTime) {
            continue;
        }
        for (int i = 0; i < graph[cx].size(); i++) {
            int nx = graph[cx][i].first;
            int cost = tempTime + graph[cx][i].second;
            if (dist[nx] > cost) {
                if (king[cx][nx].size() != 0) {
                    if (tempTime >= king[cx][nx].front().first && tempTime <= king[cx][nx].front().second) {
                        //국왕의 해당 도로 이동시간과 겹친다면 무조건 국왕이 이동한 후에 해당 도로에 들어갈 수 있다.
                        dist[nx] = king[cx][nx].front().second + graph[cx][i].second;
                        //국왕이 지나간후 해당 도로를 건너는 시간을 더한다.
                        pq.push(make_pair(-(king[cx][nx].front().second + graph[cx][i].second), nx));
                    }
                    else{
                        dist[nx] = cost;
                        pq.push(make_pair(-cost, nx));
                    }
                }
                else if (king[cx][nx].size() == 0){
                    dist[nx] = cost;
                    pq.push(make_pair(-cost, nx));
                }
            }
        }
    }
    cout << dist[B] - K;
    //도로를 건너는 시간을 구해야 함으로 출발 시간 K를 차감해 준다.
    
    return 0;
}
