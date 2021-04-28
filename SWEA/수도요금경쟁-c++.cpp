#include<iostream>

using namespace std;

int main(void)
{
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int P, Q, R, S, W;
        cin >> P >> Q >> R >> S >> W;
        int canbe1 = 0;
        int canbe2 = 0;
        
        int result;
        
        canbe1 = P * W;
        if (W <= R) {
            canbe2 = Q;
        }
        else{
            canbe2 = Q + (W - R) * S;
        }
        
        result = min(canbe1, canbe2);
        
        cout << "#" << test_case << " " << result << "\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
