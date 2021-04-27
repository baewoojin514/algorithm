#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main(void)
{
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int N;
        cin >> N;
        vector<int> num;
        for (int i = 0; i < N; i++) {
            int input;
            cin >> input;
            num.push_back(abs(input));
        }
        sort(num.begin(), num.end());
        int minValue = num[0];
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if (num[i] == minValue) {
                cnt += 1;
            }
        }
        cout << "#" << test_case << " " << minValue << " " << cnt << "\n";
        
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

