#include <iostream>
#include <deque>

using namespace std;

int main(void)
{
    int test_case;
    int T;
    
    cin>>T;
  
    for(test_case = 1; test_case <= T; ++test_case)
    {
        deque<int> num;
        int K;
        
        cin >> K;
        
        for (int i = 0; i < K; i++) {
            int input;
            cin >> input;
            
            if (input == 0) {
                if (!num.empty()) {
                    num.pop_back();
                }
                else{
                    continue;
                }
            }
            else{
                num.push_back(input);
            }
        }
        int result = 0;
        
        for (int i = 0; i < num.size(); i++) {
            result += num[i];
        }
        
        cout << "#" << test_case << " " << result << "\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
