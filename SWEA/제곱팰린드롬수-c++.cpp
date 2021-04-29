#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

bool isPalindrome(int num){
    string str1 = to_string(num);
    string str2 = to_string(num);
    
    reverse(str2.begin(), str2.end());
    
    if (str1 == str2) {
        return true;
    }
    return false;
}

int main(void)
{
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int A, B;
        cin >> A >> B;
        int result = 0;
        
        for (int i = A; i <= B; i++) {
            if (isPalindrome(i)) {
                double temp;
                temp = sqrt(i);
                if (temp - (int)temp == 0) {
                    if (isPalindrome(temp)) {
                        result += 1;
                    }
                }
            }
        }
        cout << "#" << test_case << " " << result << "\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
