//수식 최대화(programmers)
//python3와 다른 풀이법을 적용할 필요가 있다.
//연산자는 char형 vector에 저장하고 숫자는 int형 vector에 저장한다.
//skill.1 - dfs를 사용하여 가능한 모든 경우의 우선순위를 계산한다.
//skill.2 - limit == 3일 경우 해당 우선순위에 대해 연산을 하고 절대값의 최대값을 갱신한다.

#include <string>
#include <vector>


using namespace std;

char canbe[3] = {'*', '-', '+'};
vector<long long> num;
vector<char> oper;
int visited[3];
vector<char> temp;
//연산자의 우선순위를 저장하는 char형 vector이다.
long long answer = 0;

void dfs(int limit){
    if (limit == 3) {
        vector<long long> copyNum = num;
        vector<char> copyOper = oper;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < copyOper.size(); j++) {
                if (temp[i] == copyOper[j]) {
                    if (temp[i] == '*') {
                        copyNum[j] = copyNum[j] * copyNum[j + 1];
                        copyNum.erase(copyNum.begin() + j + 1);
                        copyOper.erase(copyOper.begin() + j);
                    }
                    else if (temp[i] == '+'){
                        copyNum[j] = copyNum[j] + copyNum[j + 1];
                        copyNum.erase(copyNum.begin() + j + 1);
                        copyOper.erase(copyOper.begin() + j);
                    }
                    else if (temp[i] == '-'){
                        copyNum[j] = copyNum[j] - copyNum[j + 1];
                        copyNum.erase(copyNum.begin() + j + 1);
                        copyOper.erase(copyOper.begin() + j);
                    }
                    j--;
                    //erase연산시 모든 요소가 자동으로 한칸씩 후진한다. 따라서 --연산을 해주어야 한다.
                }
            }
        }
        if (abs(copyNum[0]) > answer) {
            answer = abs(copyNum[0]);
        }
    }
    for (int i = 0; i < 3; i++) {
        if (visited[i] == 0) {
            visited[i] = 1;
            temp.push_back(canbe[i]);
            dfs(limit + 1);
            visited[i] = 0;
            temp.pop_back();
        }
    }
}

long long solution(string expression) {
    int startidx = 0;
    for (int i = 0; i < expression.size(); i++) {
        if (expression[i] == '*' || expression[i] == '-' || expression[i] == '+') {
            oper.push_back(expression[i]);
            num.push_back(stoll(expression.substr(startidx, i)));
            //stoi를 통해 str을 int로 변환할 수 있다.
            //substr을 통해 slicing을 할 수 있다 startidx부터 i길이 만큼의 string을 slicing한다.
            startidx = i + 1;
        }
    }
    num.push_back(stoll(expression.substr(startidx, expression.length())));
    dfs(0);
    
    return answer;
}
