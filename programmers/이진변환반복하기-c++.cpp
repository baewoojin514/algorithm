//이진 변환(programmers)
//구현 문제이다.

#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int cnt = 0;
    int zeroCnt = 0;
    while (true) {
        if (s == "1") {
            break;
        }
        string temp = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                zeroCnt += 1;
            }
            else{
                temp += "1";
            }
        }
        int num = temp.size();
        s = "";
        while (num > 0) {
            if (num % 2 == 0) {
                s += "0";
            }
            else{
                s += "1";
            }
            num /= 2;
        }
        cnt += 1;
    }
    answer.push_back(cnt);
    answer.push_back(zeroCnt);
    return answer;
}
