#include <vector>
#include <set>

using namespace std;

set<int> result;
int answer;

int solution(vector<int> nums)
{
    for (int i = 0; i < nums.size(); i++) {
        result.insert(nums[i]);
    }
    int N = nums.size();
    N /= 2;
    
    if (result.size() >= N) {
        answer = N;
    }
    else{
        answer = result.size();
    }
    
    return answer;
}
