#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int test_case;
    int T;
    
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int n;
        cin >> n;
        vector<pair<char, int>> info;
        for (int i = 0; i < n; i++) {
            char alpha;
            int cnt;
            cin >> alpha >> cnt;
            info.push_back(make_pair(alpha, cnt));
        }
        int tempCnt = 0;
        cout << "#" << test_case << "\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < info[i].second; j++) {
                cout << info[i].first;
                tempCnt += 1;
                
                if (tempCnt == 10) {
                    tempCnt = 0;
                    cout << "\n";
                }
            }
        }
        cout << "\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
