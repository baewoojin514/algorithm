//해킹(10282)
//최초 감염된 컴퓨터로부터 연결된 컴퓨터들을 count 하고 cost들을 더한다.
//bfs로 해결한다.

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>

#define MAX 10001
#define INF 1e9
//무한을 의미하는 값으로 10억을 설정한다.

using namespace std;

int T;
queue<int> q;

int main(void){
    cin >> T;
    int n, d, c;
    for (int i = 0; i < T; i++) {
        vector<pair<int, int>> graph[MAX];
        cin >> n >> d >> c;
        int a, b, s;
        for (int j = 0; j < d; j++) {
            cin >> a >> b >> s;
            graph[b].push_back({a, s});
        }
        q.push(c);
        int totalNum = 1;
        int totalTime = 0;
        while (!q.empty()) {
            int cx;
            cx = q.front();
            q.pop();
            for (int k = 0; k < graph[cx].size(); k++) {
                int nx, cost;
                nx = graph[cx][k].first;
                cost = graph[cx][k].second;
                totalTime += cost;
                totalNum += 1;
                q.push(nx);
            }
        }
        cout << totalNum << " " << totalTime;
    }
}
//해킹(10282)
//최초 감염된 컴퓨터로부터 연결된 컴퓨터들을 count 하고 cost들을 더한다.
//컴퓨터 x가 a,b,c에 동시에 의존한다고 가정하면 가장 적은 시간이 걸리는 컴퓨터에 의해 먼저 감염이 된다.
//skill.1 - 다익스트라 알고리즘을 사용하여 최단 시간을 구한다.
//skill.2 - dis배열을 visited처럼 사용하여 이미 최단시간으로 갱신된 컴퓨터는 continue로 넘어간다.
//skill.3 - dis배열의 값이 INF 가 아닌경우 count += 1 을 하고 걸린 시간의 최대값을 갱신한다 => INF가 아닌것은 감염된 컴퓨터이고 INF를 제외한 가장 큰 값이 최대한 많이 감염시킨 case이다.

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>

#define MAX 10001
#define INF 1e9
//무한을 의미하는 값으로 10억을 설정한다.

using namespace std;

int T;
int dis[MAX];

int main(void){
    cin >> T;
    int n, d, c;
    for (int i = 0; i < T; i++) {
        vector<pair<int, int>> graph[100001];
        cin >> n >> d >> c;
        int a, b, s;
        for (int j = 0; j < d; j++) {
            cin >> a >> b >> s;
            graph[b].push_back({a, s});
        }
        fill(dis, dis + 10001, INF);
        priority_queue<pair<int, int>> pq;
        pq.push({0, c});
        dis[c] = 0;
        int count = 0;
        while (!pq.empty()) {
            int tempTime1, cx;
            tempTime1 = -pq.top().first;
            cx = pq.top().second;
            
            pq.pop();
            
            if (dis[cx] < tempTime1) {
                continue;
            }
            for (int i = 0; i < graph[cx].size(); i++) {
                int tempTime2 = tempTime1 + graph[cx][i].second;
                if (tempTime2 < dis[graph[cx][i].first]) {
                    dis[graph[cx][i].first] = tempTime2;
                    pq.push(make_pair(-tempTime2, graph[cx][i].first));
                }
            }
        }
        int maxValue = 0;
        for (int i = 1; i <= n; i++) {
            if (dis[i] != INF) {
                maxValue = max(maxValue, dis[i]);
                count++;
            }
        }
        printf("%d %d\n", count, maxValue);
    }
    return 0;
}
