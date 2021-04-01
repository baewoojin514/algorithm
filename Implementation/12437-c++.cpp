//새로운 달력(Small)(12437)
//skill.1 - 어느 달의 일 수가 한 주의 일 수로 나누어 떨어지는 경우 line += 몫 이다.
//skill.2 - 어느 달의 일 수가 한 주의 일 수로 나누어 떨어지지 않는 경우 line += 몫 += 1이다.
//skill.3 - 2의 경우 다음 달의 일 수에 나머지 까지 더해주어야 한다.

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <stdio.h>
#include <cstring>

using namespace std;

int T;

int main(void)
{
    int idx = 0;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        int line = 0;
        int res = 0;
        for (int j = 0; j < a; j++) {
            res += b;
            int temp1 = res / c;
            int temp2 = res % c;
            if(temp2 == 0) {
                line += temp1;
                res = 0;
            }
            else if (temp2 != 0){
                line += temp1;
                line += 1;
                res = temp2;
            }
        }
        idx += 1;
        cout << "Case #" << idx << ": " << line << "\n";
    }
    return 0;
}
