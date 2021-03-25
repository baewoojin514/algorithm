//궁금한 민호(1507)
//플로이드 와샬 알고리즘으로 해결할 수 있다.
//skill.1 - 최단 경로 정보가 이차원 배열 형태로 입력된다.
//skill.2 - 플로이드 와샬 알고리즘을 반대로 적용한다([i][j] > [i][k] + [k][j] => 최단 경로가 아니다(불가능한 경우이다))

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#define MAX 20

using namespace std;

int dist[MAX][MAX];
int cost[MAX][MAX];

int N;
bool flag = true;
int result = 0;

int main(void){
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int input;
            cin >> input;
            cost[i][j] = input;
            dist[i][j] = input;
        }
    }
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == k || j == k) {
                    //경유지가 출발지 도착지와 달라야 유효한 비교가 가능하다.
                    continue;
                }
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    flag = false;
                    break;
                }
                if (dist[i][j] == dist[i][k] + dist[k][j]){
                    cost[i][j] = 0;
                    //경유해서 가는 경로들을 놔두고 0으로 만들어준다.
                }
            }
        }
    }
    if (!flag) {
        result = -1;
        cout << result;
    }
    else{
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                result += cost[i][j];
            }
        }
        cout << result;
    }
    return 0;
}
