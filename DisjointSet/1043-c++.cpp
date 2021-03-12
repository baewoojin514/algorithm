//거짓말(1043)
//disjoint set 문제이다.
//find_parent 와 union_find 함수를 사용하여 구현할 수 있다.
//skill.1 - 이차원 vector에 파티 정보를 입력 받는다.
//skill.2 - 파티 정보를 통해 union_find 한다.
//skill.3 - 모든 파티원의 부모가 진실을 아는 사람이 아닌 경우를 count 한다.

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#define MAX 51

using namespace std;

int parent[MAX];
int N, M;
int result = 0;

int find_parent(int X){
    if (parent[X] != X) {
        parent[X] = find_parent(parent[X]);
    }
    return parent[X];
}

void union_find(int a, int b){
    a = find_parent(a);
    b = find_parent(b);
    
    if (a > b) {
        parent[a] = b;
        return;
    }
    else{
        parent[b] = a;
        return;
    }
}

int main(void){
    cin >> N >> M;
    int p;
    cin >> p;
    
    for (int i = 0; i < N + 1; i++) {
        parent[i] = i;
    }
    
    for (int i = 0; i < p; i++) {
        int tmp;
        cin >> tmp;
        union_find(0, tmp);
        //진실을 아는 사람을 입력 받는다.
    }
    vector<vector<int>> party(M);
    
    for (int i = 0; i < M; i++) {
        int tmpP;
        cin >> tmpP;
        for (int j = 0; j < tmpP; j++) {
            int partyP;
            cin >> partyP;
            party[i].push_back(partyP);
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 1; j < party[i].size(); j++) {
            union_find(party[i][0], party[i][j]);
        }
    }
    for (int i = 0; i < M; i++) {
        int tmpP = find_parent(party[i][0]);
        if (find_parent(tmpP) != find_parent(0)) {
            result += 1;
        }
    }
    cout << result;
    return 0;
}
