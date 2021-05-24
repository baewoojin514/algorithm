#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int test_case;
    int T;

    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int N, M;
        vector<int> num;
        
        cin >> N >> M;
        
        int tempMax = -1;
        
        for (int i = 0; i < N; i++) {
            int input;
            cin >> input;
            num.push_back(input);
        }
        
        for (int i = 0; i < N - 1; i++) {
            for (int j = i + 1; j < N; j++) {
                int temp = num[i] + num[j];
                if (temp <= M) {
                    tempMax = max(tempMax, temp);
                }
            }
        }
        cout << "#" << test_case << " " << tempMax << "\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
