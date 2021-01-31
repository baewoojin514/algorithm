//N과 M(12)(15666)
//dfs재귀로 해결한다.
//입력되는 N 개의 수중 M개를 고르고 출력한다.
//재귀 함수의 limit == M이면 각 수열을 canbe 리스트에 append한다.
//skill.1 - 입력 받은 수의 리스트를 정렬한다.
//skill.2 - 수열 자체가 중복될 수 없고 내부 요소는 중복 가능하다.
//skill.3 - 수열은 비내림차순 이어야 함으로 parameter로 limit 과 index 를 사용하고 visited 배열을 사용하지 않는다.
//skill.4 - 수열이 만들어지면 set을 통해 중복 여부를 check 하고 출력한다.

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <vector>
#include <set>
#define MAX 9

using namespace std;

int N, M;
int temp[MAX];
vector<int> num;
set<vector<int>> canbe;

void dfs(int index, int limit){
    if (limit == M) {
        vector<int> tmp;
        for (int i = 0; i < M; i++) {
            tmp.push_back(temp[i]);
        }
        if (canbe.find(tmp) == canbe.end()) {
            //find를 통해 집합에서 해당 요소의 위치를 찾는다 => end 일 경우 해당 요소가 존재하지 않기 때문에 삽입한다.
            canbe.insert(tmp);
            for (int j = 0; j < M; j++) {
                cout << tmp[j] << " ";
            }
            cout << '\n';
            //endl을 사용하면 시간초과가 발생할 확률이 높다.
        }
        tmp.clear();
        return;
    }
    for (int j = index; j < num.size(); j++) {
        temp[limit] = num.at(j);
        dfs(j, limit + 1);
        temp[limit] = 0;
    }
    
}

int main(void){
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int input;
        cin >> input;
        num.push_back(input);
    }
    sort(num.begin(), num.end());
    dfs(0, 0);
    
    return 0;
}
