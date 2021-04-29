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
        vector<int> num;
        int N;
        cin >> N;
        int result = 0;
        
        for (int i = 0; i < N; i++) {
            int input;
            cin >> input;
            
            num.push_back(input);
        }
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += num[i];
        }
        double average = sum / N;
        for (int i = 0; i < N; i++) {
            if ((double)num[i] <= average) {
                result += 1;
            }
        }
        cout << "#" << test_case << " " << result << "\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
