#include <iostream>
#include <vector>

using namespace std;

bool checkCanBe(int B, int E, int num){
    for (int i = B - E; i <= B + E; i++) {
        if (i % num == 0) {
            return true;
        }
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
        int N, B, E;
        
        cin >> N >> B >> E;
        
        int result = 0;
        for (int i = 0; i < N; i++) {
            int input;
            cin >> input;
            
            if (checkCanBe(B, E, input)) {
                result += 1;
            }
            
        }
        cout << "#" << test_case << " " << result << "\n";
        
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
