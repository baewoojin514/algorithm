#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

int main(void)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int tempResult;
        string input;
        cin >> input;
        int n;
        n = input.size();
        
        if (n == 1) {
            tempResult = 1;
        }
        else{
            if (n % 2 == 0) {
                //문자열의 길이가 짝수인 경우
                string tmp1 = input.substr(0, n/2);
                string tmp2 = input.substr(n/2, n/2);
                reverse(tmp2.begin(), tmp2.end());
                if (tmp1 == tmp2) {
                    tempResult = 1;
                }
                else{
                    tempResult = 0;
                }
            }
            else{
                string tmp1 = input.substr(0, n/2);
                string tmp2 = input.substr(n/2 + 1, n/2);
                reverse(tmp2.begin(), tmp2.end());
                if (tmp1 == tmp2) {
                    tempResult = 1;
                }
                else{
                    tempResult = 0;
                }
            }
        }
        cout << "#" << test_case << " " << tempResult << "\n";
    }
    return 0;
}
