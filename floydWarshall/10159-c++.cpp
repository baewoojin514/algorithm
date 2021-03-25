//저울(10159)
//플로이드 와샬 알고리즘으로 해결할 수 있다.
//skill.1 - i > j 인 경우을 1 반대의 경우를 -1로 갱신한다.
//skill.2 - [i][k] == 1 && [k][j] == 1 인 경우 [i][k] 를 1로 갱신하고 둘 다 -1인 경우 -1로 갱신한다.
//skill.3 - 1, -1 이 아닌 경우 즉 무게를 비교할 수 없는 경우의 수를 count 하고 result vector에 삽입한다(N개의 물건을 기준으로).

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#define MAX 100

using namespace std;

int dist[MAX][MAX];
vector<int> result;

int N, M;

int main(void){
    cin >> N;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        dist[a - 1][b - 1] = 1;
        dist[b - 1][a - 1] = -1;
    }
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) {
                    continue;
                }
                if (dist[i][k] == 1 && dist[k][j] == 1) {
                    dist[i][j] = 1;
                }
                if (dist[i][k] == -1 && dist[k][j] == -1) {
                    dist[i][j] = -1;
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        int temp = 0;
        for (int j = 0; j < N; j++) {
            if (dist[i][j] == 0 && i != j) {
                temp += 1;
            }
        }
        result.push_back(temp);
    }
    
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << "\n";
    }
    
    return 0;
}
