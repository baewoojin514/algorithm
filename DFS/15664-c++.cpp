//N과 M(10)(15664)
//dfs 재귀로 해결한다.
//입력되는 N개의 수 중 M개를 고르고 출력한다.
//재귀 함수의 limit == M이면 각 수열을 출력한다.
//skill.1 - 입력 받은 수를 정렬해야 한다.
//skill.2 - 수열과 수열의 요소가 중복될 수 없다.
//skill.3 - set 즉 집합을 사용해서 삽입시 중복을 방지한다.
//skill.4 - 수열은 비내림차순 이어야 하기 때문에 j + 1 로 재귀 함수를 호출해야 한다.

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#define MAX 9

using namespace std;

int N;
int M;

int temp[MAX];
int visited[MAX];
vector<int> num;
set<vector<int>> canbe;

void dfs(int index, int limit){
    if (limit == M) {
        vector<int> tmp;
        for (int i = 0; i < M; i++) {
            tmp.push_back(temp[i]);
            //임시 vector에 현재 temp 배열에 들어있는 수를 삽입한다.
        }
        canbe.insert(tmp);
        //set에 data를 입력시 insert를 사용하고 중복된 data는 삽입되지 않는다.
        tmp.clear();
        return;
    }
    for (int j = index; j < N; j++) {
        if (visited[j] == 0) {
            temp[limit] = num.at(j);
            visited[j] = 1;
            dfs(j + 1, limit + 1);
            temp[limit] = 0;
            visited[j] = 0;
        }
    }
}

int main(void){
    
    cin >> N >> M;
    num.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> num.at(i);
    }
    sort(num.begin(), num.end());
    dfs(0, 0);
    
    for (auto e : canbe) {
        for (int i = 0; i < e.size(); i++) {
            cout << e[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}
