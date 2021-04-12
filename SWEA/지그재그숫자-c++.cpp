#include <iostream>
#include <stdio.h>
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
        int tempResult;
        cin >> N;
        if (N % 2 == 0) {
            //N이 짝수인 경우
            tempResult = -(N / 2);
        }
        else{
            //N이 홀수인 경우
            tempResult = -(N / 2) + N;
        }
        cout << "#" << test_case << " " << tempResult << "\n";
    }
    return 0;
}
