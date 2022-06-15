#include <vector>

using namespace std;

int ranks[7] = {6, 6, 5, 4, 3, 2, 1};

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    int tempRank = 0;
    int zeroCnt = 0;
    
    for (int i = 0; i < 6; i++) {
        if (lottos[i] == 0) {
            zeroCnt += 1;
        }
        for (int j = 0; j < 6; j++) {
            if (lottos[i] == win_nums[j]) {
                tempRank += 1;
            }
        }
    }
    
    vector<int> answer;
    
    answer.push_back(ranks[zeroCnt + tempRank]);
    answer.push_back(ranks[tempRank]);
    return answer;
}
