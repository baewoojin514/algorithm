//JadenCase 문자열 만들기(programmers)

#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> temp;

string solution(string s) {
    string answer = "";
    istringstream tempStr(s);
    string splitStr;
    
    while (getline(tempStr, splitStr, ' ')) {
        temp.push_back(splitStr);
    }
    
    for (int i = 0; i < temp.size(); i++) {
        string tmp = temp[i];
        for (int j = 0; j < tmp.size(); j++) {
            if (j == 0) {
                tmp[j] = toupper(tmp[j]);
            }
            else{
                tmp[j] = tolower(tmp[j]);
            }
        }
        answer += tmp;
        answer += ' ';
    }
    answer = answer.substr(0,s.size() - 1);
    
    return answer;
}
