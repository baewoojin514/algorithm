//[1차]뉴스 클러스터링
//map을 사용해서 해결할 수 있다(구현 문제이다).
//skill.1 - str1, str2를 2개씩 끊어서 alphabet인지 확인후 맞다면 모두 소문자로 변환한다.
//skill.2 - map 의 value 값을 += 1을 하고 0인 경우 totalStr string vector에 삽입한다.
//skill.3 - totalStr을 탐색하면서 min 값은 교집합에 max 값은 합집합에 더한다.
//skill.4 - int(minCnt / maxCnt x 65536)를 반환한다.

#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<string, int> A;
map<string, int> B;

vector<string> totalStr;

int solution(string str1, string str2) {
    double answer = 0.0;
    for (int i = 0; i < str1.size() - 1; i++) {
        string temp = "";
        
        if (isalpha(str1[i]) != 0 && isalpha(str1[i + 1]) != 0) {
            temp += str1[i];
            temp += str1[i + 1];
            transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
            if (A[temp] == 0) {
                totalStr.push_back(temp);
            }
            A[temp] += 1;
        }
    }
    for (int i = 0; i < str2.size() - 1; i++) {
        string temp = "";
        
        if (isalpha(str2[i]) != 0 && isalpha(str2[i + 1]) != 0) {
            temp += str2[i];
            temp += str2[i + 1];
            transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
            if (A[temp] == 0 && B[temp] == 0) {
                totalStr.push_back(temp);
            }
            B[temp] += 1;
        }
    }
    if (totalStr.size() == 0) {
        answer = double(65536);
    }
    else{
        int inter = 0;
        int uni = 0;
        for (int i = 0; i < totalStr.size(); i++) {
            string tmp = totalStr[i];
            inter += min(A[tmp], B[tmp]);
            uni += max(A[tmp], B[tmp]);
        }
        answer = double(inter) / double(uni) * 65536;
    }
    return int(answer);
}
