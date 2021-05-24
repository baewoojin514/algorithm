#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int main(void)
{
    int test_case;
    int T;
   
    cin>>T;
   
    for(test_case = 1; test_case <= T; ++test_case)
    {
        string input;
        vector<char> alpha;
        map<char, int> alphaCnt;
        
        cin >> input;
        
        for (int i = 0; i < 4; i++) {
            alphaCnt[input[i]] += 1;
            if (find(alpha.begin(), alpha.end(), input[i]) == alpha.end()) {
                alpha.push_back(input[i]);
            }
        }
        
        bool flag = true;
        for (int i = 0; i < alpha.size(); i++) {
            if (alphaCnt[alpha[i]] != 2) {
                flag = false;
            }
        }
        if (flag) {
            cout << "#" << test_case << " " << "Yes" << "\n";
        }
        else{
            cout << "#" << test_case << " " << "No" << "\n";
        }
        
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
