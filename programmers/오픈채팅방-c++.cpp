//오픈채팅방(programmers)
//skill.1 - sstream 을 통해 record를 parsing한다.
//skill.2 - enter와 change의 경우 map[uid] = name 을 통해 전처리한다.
//skill.3 - record를 탐색하면서 answer에 명령을 삽입한다.

#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

map<string, string> m;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    for (int i = 0; i < record.size(); i++) {
        vector<string> temp;
        istringstream tempStr(record[i]);
        string splitStr;
        
        while (getline(tempStr, splitStr, ' ')) {
            temp.push_back(splitStr);
        }
        if (temp[0] == "Enter" || temp[0] == "Change") {
            m[temp[1]] = temp[2];
        }
    }
    for (int i = 0; i < record.size(); i++) {
        vector<string> temp;
        istringstream tempStr(record[i]);
        string splitStr;
        
        while (getline(tempStr, splitStr, ' ')) {
            temp.push_back(splitStr);
        }
        if (temp[0] == "Enter") {
            string cmd = m[temp[1]] + "님이 들어왔습니다.";
            answer.push_back(cmd);
        }
        if (temp[0] == "Leave") {
            string cmd = m[temp[1]] + "님이 나갔습니다.";
            answer.push_back(cmd);
        }
    }
    return answer;
}
