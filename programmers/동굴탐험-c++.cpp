//동굴 탐험(programmers)
//bfs를 통해 해결할 수 있다.
//order 즉 선.후 행 관계를 afer, before로 관리한다.

#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <set>
#define MAX 200000

using namespace std;

vector<int> graph[MAX];
int visited[MAX];
int after[MAX];
int before[MAX];
deque<int> q;
set<int> temp;

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    bool answer = true;
    for (auto i : path) {
        graph[i[0]].push_back(i[1]);
        graph[i[1]].push_back(i[0]);
    }
    memset(after, -1, sizeof(after));
    memset(before, -1, sizeof(before));
    
    for (auto i : order) {
        after[i[0]] = i[1];
        before[i[1]] = i[0];
    }
    if (before[0] != -1) {
        answer = false;
    }
    //0은 시작 node로 선행 노드가 존재할 수 없다.
    q.push_back(0);
    
    while (!q.empty()) {
        int cx = q.front();
        q.pop_front();
        
        if (after[cx] != -1) {
            //만약 후행 노드가 있다면 후행 노드의 선행 노드를 -1로 만들어
            before[after[cx]] = -1;
        }
        if (temp.find(after[cx]) != temp.end()) {
            //현재 노드의 후행 노드가 임시 집합에 있다면 방문한다.
            temp.erase(after[cx]);
            q.push_back(after[cx]);
            visited[after[cx]] = 1;
        }
        for (int i = 0; i < graph[cx].size(); i++) {
            int nx = graph[cx][i];
            
            if (visited[nx] == 1) {
                //방문한 노드라면 continue로 넘어간다.
                continue;
            }
            if (before[nx] != -1) {
                temp.insert(nx);
            }
            else{
                q.push_back(nx);
                visited[nx] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            answer = false;
            break;
        }
    }
    return answer;
}
