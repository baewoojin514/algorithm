#include <iostream>
#include <string>
#include <cstring>

using namespace std;

bool checkNum(int visited[]){
    int checkCnt = 0;
    for (int i = 0; i < 10; i++) {
        if (visited[i]) {
            checkCnt += 1;
        }
    }
    if (checkCnt == 10) {
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
        int N;
        int num;
        cin >> N;
        num = N;
        int check[10];
        memset(check, 0, sizeof(check));
        while (true) {
            string str = to_string(num);
            for (int i = 0; i < str.size(); i++) {
                check[str[i] - '0'] = 1;
            }
            if (checkNum(check)) {
                break;
            }
            num += N;
        }
        cout << "#" << test_case << " " << num << "\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
