#include <iostream>

using namespace std;

int main(void)
{
    int test_case;
    int T;
   
    cin>>T;
  
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int N, A, B;
        int tempMax = 0;
        int tempMin = 0;
        
        cin >> N >> A >> B;
        if (N == A && N == B) {
            tempMax = N;
            tempMin = N;
        }
        if (N > (A + B)) {
            tempMax = min(A, B);
            tempMin = 0;
        }
        if (N < (A + B)) {
            tempMax = min(A, B);
            tempMin = (A + B) - N;
        }
        if (N == (A + B)) {
            tempMax = min(A, B);
            tempMin = 0;
        }
        
        cout << "#" << test_case << " " << tempMax << " " << tempMin << "\n";
        
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
