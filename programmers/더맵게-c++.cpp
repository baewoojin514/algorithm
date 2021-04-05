//힙(Heap)
//우선순위 큐를 사용하여 해결할 수 있다.
//skill.1 - 섞은 음식의 스코빌 지수 = 가장 맵지 않은 음식의 스코빌 지수 + (두 번째로 맵지 않은 음식의 스코빌 지수 * 2)
//skill.2 - 1의 값이 K 이상이 되는 경우의 cnt를 반환한다.

#include <string>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int> pq;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    for (int i = 0; i < scoville.size(); i++) {
        pq.push(-scoville[i]);
    }
    while (true) {
        int fx, sx;
        fx = -pq.top();
        pq.pop();
        
        if (fx >= K) {
            break;
        }
        else if (pq.empty()) {
            answer = -1;
            break;
        }
        sx = -pq.top();
        pq.pop();
        
        int newValue = fx + (sx * 2);
        answer += 1;
        pq.push(-newValue);
    }
    return answer;
}
