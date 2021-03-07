//빗물(14719)
//구현(implementation) 문제이다.
//skill.1 - index 1 ~ W - 1까지 좌우로 블록의 높이의 최대를 각각구한다.
//skill.2 - 좌우 최대값의 최소값에서 현재 블록의 높이를 차감한 만큼 빗물이 찰 수 있다.

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define MAX 501

using namespace std;

int H, W;
vector<int> rain;
int result = 0;

int main(void){
    cin >> H >> W;
    for (int i = 0; i < W; i++) {
        int tempRain;
        cin >> tempRain;
        rain.push_back(tempRain);
    }
    
    for (int i = 1; i < W - 1; i++) {
        int tempMax1 = rain[i];
        int tempMax2 = rain[i];
        //현재 블럭의 높이를 기준으로 max값을 계산해야 한다.
        for (int j = 0; j < i; j++) {
            tempMax1 = max(tempMax1, rain[j]);
        }
        for (int j = i + 1; j < W; j++) {
            tempMax2 = max(tempMax2, rain[j]);
        }
        if (tempMax1 != 0 && tempMax1 != 0) {
            int canbe = min(tempMax1, tempMax2);
            result += canbe - rain[i];
        }
    }
    cout << result;
    return 0;
}
