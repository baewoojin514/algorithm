#include <iostream>
#include <cstring>

using namespace std;

bool inRange(int num){
    return num >= 1 && num <= 9;
}

int main(void)
{
    int test_case;
    int T;
   
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int N;
        cin >> N;
        
        bool numCheck = true;
        
        for (int i = 1; i < 10; i++) {
            if (N % i == 0) {
                if (inRange(N / i)) {
                    numCheck = false;
                }
            }
        }
        
        if (!numCheck) {
            cout << "#" << test_case << " " << "Yes" << "\n";
        }
        else{
            cout << "#" << test_case << " " << "No" << "\n";
        }
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
