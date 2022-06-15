#include <vector>

using namespace std;

vector<int> cnt;

int solution(vector<int> numbers) {
    int answer = 0;
    cnt.resize(10);
    
    for (int i = 0; i < numbers.size(); i++) {
        cnt[numbers[i]] += 1;
    }
    for (int i = 0; i < cnt.size(); i++) {
        if (!cnt[i]) {
            answer += i;
        }
    }
    
    return answer;
}
