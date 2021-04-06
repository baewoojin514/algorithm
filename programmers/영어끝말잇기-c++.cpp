//영어 끝말잇기(programmers)
//map을 사용해서 구현할 수 있다.
//skill.1 - map의 value가 1인 경우 이미 존재하는 string 임으로 위배된다.
//skill.2 - 이전 string의 끝과 현재 string의 시작이 동일하지 않다면 위배된다.
//skill.3 - 차례는 idx를 번호로 나눈 값 += 1이다.

#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

map<string, int> m;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    int answerNum = 0;
    int answerTerm = 0;
    int num = 2;
    m[words[0]] += 1;
    for (int i = 1; i < words.size(); i++) {
        int idx = i + 1;
        if (idx % n == 1) {
            //n명의 사람이 모두 끝말잇기를 한 후 다시 첫 번째 차례가 돌아오면 num을 1로 바꾼다.
            num = 1;
        }
        int compareIdx = words[i - 1].size();
        if (words[i - 1][compareIdx - 1] != words[i][0] || m[words[i]] == 1) {
            //끝말있기 규칙 위배
            answerNum = num;
            answerTerm = (i / n) + 1;
            break;
        }
        num += 1;
        m[words[i]] += 1;
    }
    answer.push_back(answerNum);
    answer.push_back(answerTerm);
    return answer;
}
