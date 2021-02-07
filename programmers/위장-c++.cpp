//위장(programmers)
//c++의 map(key, value) 자료구조를 활용하면 된다.
//skill.1 - 각 의상의 종류를 조합하는 경우의 수를 구하면 된다.
//skill.2 - 각 의상의 종류를 착용하지 않는 경우가 가능하다.
//skill.3 - 아무것도 착용하지 않는 것은 불가능 하기 때문에 *(의상의 종류 + 1) - 1(아무것도 착용하지 않은 경우)를 계산한다.

#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, int> canbe;
    
    for (int i = 0; i < clothes.size(); i++) {
        canbe[clothes[i][1]] += 1;
        //배열이나 vector의 index를 사용하듯이 key를 사용해서 value에 접근할 수 있다.
    }
    
    int answer = 1;
    for (auto it = canbe.begin(); it != canbe.end(); it++) {
        //for문 사용시 iterator를 사용해서 접근해야 한다.
        answer *= (it -> second) + 1;
    }
    return answer - 1;
}
