//메뉴 리뉴얼
//구현 문제이다.
//skill.1 - 코스 요리에 들어갈 수 있는 메뉴는 최소 2명 이상 주문한 경우만 가능하다(map[C] == 1일 경우 가능하다).
//skill.2 - 코스요리가 가능한 조합을 만든다(dfs).
//skill.3 - 해당 코스요리가 포함되어 있는 경우를 count하고 최대 값을 갱신한다(최대 값일 경우 result string vector에 삽입한다).
//map으로 가능한 최대의 경우의 수를 탐색할 경우 시간초과가 발생한다.

#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

void dfs(int idx, int cnt, int limit, vector<char> canbe, int &maxValue, vector<string> order, vector<char> &temp, vector<int> &visited, vector<string> &tempResult){
    if (cnt == limit) {
        map<char, int> tempM;
        for (int i = 0; i < limit; i++) {
            tempM[temp[i]] += 1;
        }
        int tempValue = 0;
        for (int i = 0; i < order.size(); i++) {
            int tempCheck = 0;
            for (int j = 0; j < order[i].size(); j++) {
                if (tempM[order[i][j]] > 0) {
                    tempCheck += 1;
                }
            }
            if (tempCheck == limit) {
                tempValue += 1;
            }
        }
        string tempStr = "";
        for (int i = 0; i < limit; i++) {
               tempStr += temp[i];
        }
        if (maxValue > tempValue || tempValue < 2) {
            return;
        }
        if (maxValue == tempValue) {
            tempResult.push_back(tempStr);
        }
        else if (maxValue < tempValue) {
            tempResult.clear();
            maxValue = tempValue;
            tempResult.push_back(tempStr);
        }
        return;
    }
    for (int i = idx; i < canbe.size(); i++) {
        if (visited[canbe[i] - 'A'] == 0) {
            visited[canbe[i] - 'A'] = 1;
            temp.push_back(canbe[i]);
            dfs(i, cnt + 1, limit, canbe, maxValue, order, temp, visited, tempResult);
            visited[canbe[i] - 'A'] = 0;
            temp.pop_back();
        }
    }
    
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<char> canbe;
    map<char, int> m;
    vector<string> answer;
    for (int i = 0; i < orders.size(); i++) {
        for (int j = 0; j < orders[i].size(); j++) {
            //코스 요리의 메뉴가 되기 위해서는 2명 이상의 주문을 받아야 한다.
            if (m[orders[i][j]] == 0) {
                m[orders[i][j]] += 1;
            }
            else if (m[orders[i][j]] == 1){
                m[orders[i][j]] += 1;
                canbe.push_back(orders[i][j]);
            }
        }
    }
    int maxLimit = canbe.size();
    //코스요리는 최대 maxLimit개 만큼만 만들 수 있다.
    sort(canbe.begin(), canbe.end());
    
    for (int i = 0; i < course.size(); i++) {
        if (course[i] <= maxLimit) {
            int maxValue = 0;
            vector<char> temp;
            vector<string> tempResult;
            vector<int> visited;
            visited.resize(27);
            dfs(0, 0, course[i], canbe, maxValue, orders, temp, visited, tempResult);
            for (int j = 0; j < tempResult.size(); j++) {
                answer.push_back(tempResult[j]);
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}
//메뉴 리뉴얼
//구현 문제이다.
//skill.1 - 코스 요리에 들어갈 수 있는 메뉴는 최소 2명 이상 주문한 경우만 가능하다(map[C] == 1일 경우 가능하다).
//skill.2 - 코스요리가 가능한 조합을 만든다(dfs).
//skill.3 - 해당 코스요리가 포함되어 있는 경우를 count하고 최대 값을 갱신한다(최대 값일 경우 result string vector에 삽입한다).
//map으로 가능한 최대의 경우의 수를 탐색할 경우 시간초과가 발생한다.

#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

void dfs(int idx, int cnt, int limit, vector<char> canbe, int &maxValue, vector<string> order, vector<char> &temp, vector<int> &visited, vector<string> &tempResult){
    if (cnt == limit) {
        string tempStr = "";
        for (int i = 0; i < limit; i++) {
               tempStr += temp[i];
        }
        int tempValue = 0;
        for (int i = 0; i < order.size(); i++) {
            bool check = true;
            for (int j = 0; j < temp.size(); j++) {
                if (order[i].find(temp[j]) == string::npos) {
                    //temp의 char data를 모두 포함한 경우만 += 1을 한다.
                    //break를 통해 prunning을 한다.
                    check = false;
                    break;
                }
            }
            if (check) {
                tempValue += 1;
            }
        }
        
        if (maxValue > tempValue || tempValue < 2) {
            return;
        }
        if (maxValue == tempValue) {
            tempResult.push_back(tempStr);
        }
        else if (maxValue < tempValue) {
            tempResult.clear();
            maxValue = tempValue;
            tempResult.push_back(tempStr);
        }
        return;
    }
    for (int i = idx; i < canbe.size(); i++) {
        if (visited[canbe[i] - 'A'] == 1) {
            continue;
        }
        visited[canbe[i] - 'A'] = 1;
        temp.push_back(canbe[i]);
        dfs(i, cnt + 1, limit, canbe, maxValue, order, temp, visited, tempResult);
        visited[canbe[i] - 'A'] = 0;
        temp.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<char> canbe;
    map<char, int> m;
    vector<string> answer;
    for (int i = 0; i < orders.size(); i++) {
        for (int j = 0; j < orders[i].size(); j++) {
            //코스 요리의 메뉴가 되기 위해서는 2명 이상의 주문을 받아야 한다.
            if (m[orders[i][j]] == 0) {
                m[orders[i][j]] += 1;
            }
            else if (m[orders[i][j]] == 1){
                m[orders[i][j]] += 1;
                canbe.push_back(orders[i][j]);
            }
        }
    }
    int maxLimit = canbe.size();
    //코스요리는 최대 maxLimit개 만큼만 만들 수 있다.
    sort(canbe.begin(), canbe.end());
    
    for (int i = 0; i < course.size(); i++) {
        if (course[i] <= maxLimit) {
            int maxValue = 0;
            vector<char> temp;
            vector<string> tempResult;
            vector<int> visited;
            visited.resize(27);
            dfs(0, 0, course[i], canbe, maxValue, orders, temp, visited, tempResult);
            for (int j = 0; j < tempResult.size(); j++) {
                answer.push_back(tempResult[j]);
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}

