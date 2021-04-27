#include <iostream>
#include <vector>
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
        vector<int> num;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int input;
            cin >> input;
            num.push_back(input);
        }
        sort(num.begin(), num.end());
        
        cout << "#" << test_case << " ";
        for (int i = 0; i < N; i++) {
            cout << num[i] << " ";
        }
        cout << "\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
