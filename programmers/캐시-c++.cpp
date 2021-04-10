//[1차]캐시(programmers)
//cache와 LRU를 이해해야 한다.
//skill.1 - 가장 최근에 사용되지 않은 데이터를 시간의 순차적으로 push_back하여 구분한다.
//skill.2 - 이미 cache에 존재하는 data인 경우 해당 data를 erase하고 push_back한다.
//skill.3 - 존재하지 않는 data인 경우 cache가 가득 차있다면 pop_front하고 push_back한다.
//skill.4 - 3이 아닌 경우 push_back한다.

#include <string>
#include <vector>
#include <algorithm>
#include <list>
#define HIT 1
#define MISS 5

using namespace std;

list<string> temp;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    if (cacheSize == 0) {
        answer = cities.size() * MISS;
    }
    else{
        for (int i = 0; i < cities.size(); i++) {
            string city = cities[i];
            transform(city.begin(), city.end(), city.begin(), ::tolower);
            //대문자 소문자를 구분하지 않기 때문에 모두 소문자로 변환한다.
            if (find(temp.begin(), temp.end(), city) != temp.end()) {
                //cache에 이미 저장되어 있는 data인 경우
                temp.remove(city);
                temp.push_back(city);
                answer += HIT;
            }
            else{
                if (temp.size() == cacheSize) {
                    temp.pop_front();
                    temp.push_back(city);
                }
                else{
                    temp.push_back(city);
                }
                answer += MISS;
            }
        }
    }
    return answer;
}
