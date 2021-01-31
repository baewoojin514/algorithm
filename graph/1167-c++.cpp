//트리의 지름(1167)
//트리의 임의의 두 노드 사이의 거리 중 가장 큰 것이 트리의 지름이다.
//skill.1 - 임의의 노드에서 가장 거리가 큰 노드를 찾는다.
//skill.2 - 1에서 찾은 노드에서 가장 거리가 큰 노드를 찾는다.
//skill.3 - 1,2 노드 간 거리를 구한다.

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int V;
int distance1[100001];
int distance2[100001];

struct info{
    int node;
    int cost;
};

vector<info> graph[100001];
//구조체를 저장할 수 있는 vector를 선언한다.
//node 번호와 cost를 저장한다.

int main(void){
    cin >> V;
    
    int node, a, b;
    for (int i = 1; i < V + 1; i++) {
        cin >> node;
        while (1) {
            cin >> a;
            if (a == -1) {
                break;
            }
            cin >> b;
            graph[node].push_back({a, b});
            graph[a].push_back({node, b});
        }
    }
    memset(distance1, -1, sizeof(distance1));
    queue<int> q1;
    q1.push(1);
    distance1[1] = 0;
    
    while (!q1.empty()) {
        int cx;
        cx = q1.front();
        q1.pop();
        
        for (int i = 0; i < graph[cx].size(); i++) {
            int nx, cost;
            nx = graph[cx][i].node;
            cost = graph[cx][i].cost;
            if (distance1[nx] == -1) {
                distance1[nx] = distance1[cx] + cost;
                q1.push(nx);
            }
        }
    }
    int rsx = distance(distance1, max_element(distance1, distance1 + (V + 1)));
    //python3의 .index 로 max 값의 index를 구하듯이 c++ 에서는 distance를 사용한다.
    memset(distance2, -1, sizeof(distance2));
    queue<int> q2;
    q2.push(rsx);
    distance2[rsx] = 0;
    
    while (!q2.empty()) {
        int cx;
        cx = q2.front();
        q2.pop();
        
        for (int i = 0; i < graph[cx].size(); i++) {
            int nx, cost;
            nx = graph[cx][i].node;
            cost = graph[cx][i].cost;
            if (distance2[nx] == -1) {
                distance2[nx] = distance2[cx] + cost;
                q2.push(nx);
            }
        }
    }
    cout << *max_element(distance2, distance2 + (V + 1));
    //max_element 를 통해 배열의 max 값을 계산할 수 있다.
    
    return 0;
}
