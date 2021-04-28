#include <iostream>
#include <vector>
#define MAX 21

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    
    cin>>T;
   
    for(test_case = 1; test_case <= T; ++test_case)
    {
        vector<int> num;
        int N;
        int result = 0;
        cin >> N;
        num.resize(N);
        for (int i = 0; i < N; i++) {
            cin >> num[i];
        }
        for (int i = 1; i < N - 1; i++) {
            int tempMax = 0;
            int tempMin = MAX;
            int tempNum = num[i];
            for (int j = i - 1; j <= i + 1; j++) {
                tempMin = min(num[j], tempMin);
                tempMax = max(num[j], tempMax);
            }
            if (tempNum != tempMax && tempNum != tempMin) {
                result += 1;
            }
            tempMax = 0;
            tempMin = MAX;
        }
        cout << "#" << test_case << " " << result << "\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
