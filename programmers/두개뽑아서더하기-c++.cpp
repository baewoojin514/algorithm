#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

set<int> result;

vector<int> solution(vector<int> numbers) {
    for (int i = 0; i < numbers.size() - 1; i++) {
        int num1 = numbers[i];
        for (int j = i + 1; j < numbers.size(); j++) {
            int num2 = numbers[j];
            result.insert(num1 + num2);
        }
    }
    vector<int> answer;
    
    for (auto i : result) {
        answer.push_back(i);
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}
