#include <iostream>
#include <vector>

using namespace std;

vector<int> num;

int result = 0;

void dfs(int tempSum, int index, int limit){
    if (index == limit) {
        result = max(result, tempSum);
        return;
    }
    dfs(tempSum + num[index], index + 1, limit);
    dfs(tempSum * num[index], index + 1, limit);
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
        
        result = 0;
        num.clear();
        for (int i = 0; i < N; i++) {
            int input;
            cin >> input;
            num.push_back(input);
        }
        dfs(0, 0, N);
        
        cout << "#" << test_case << " " << result << "\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
