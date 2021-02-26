//보석 쇼핑(programmes)
//투 포인터 알고리즘을 사용해서 해결할 수 있다.
//보석의 구매 여부를 확인하기 위해서 map 자료구조를 사용한다.
//skill.1 - gems vector의 요소를 집합에 삽입하여 보석의 종류의 개수를 구한다.
//skill.2 - python3의 two pointer logic을 사용하여 구현한다.

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    int totaljew;
    map<string, int> m;
    vector<pair<pair<int, int>, int>> result;
    //구간의 길이, 시작점(stx), 끝점(edx)을 저장한다.
    for (int i = 0; i < gems.size(); i++) {
        m[gems[i]] += 1;
    }
    totaljew = m.size();
    //구매해야 보석 종류의 수이다.
    int edx = 0;
    m.clear();
    //map을 비워준다.
    //부분 합에서 sum을 첫 번째 수로 초기화 하는 것과 같은 원리이다.
    for (int stx = 0; stx < gems.size(); stx++) {
        while (m.size() < totaljew && edx < gems.size()) {
            m[gems[edx]] += 1;
            edx += 1;
        }
        if (m.size() == totaljew) {
            result.push_back({{edx - stx, stx}, edx});
        }
        if (m[gems[stx]] == 1) {
            //해당 보석이 1개 라면 erase를 해야 size에 반영되지 않는다.
            m.erase(gems[stx]);
        }
        else {
            //해당 보석이 1개 이상인 경우 하나를 빼준다.
            m[gems[stx]] -= 1;
        }
    }
    sort(result.begin(), result.end());
    int a, b;
    a = result[0].first.second;
    b = result[0].second;
    answer.push_back(a + 1);
    answer.push_back(b);
    //edx += 1 되어 있기 때문에 + 1을 할 필요가 없다.
    return answer;
}
