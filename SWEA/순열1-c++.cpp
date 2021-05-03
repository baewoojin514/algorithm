#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int N;
        string result;
        vector<int> visited;
        cin >> N;
        
        visited.resize(N + 1);
        
        for (int i = 0; i < N; i++) {
            int input;
            cin >> input;
            
            visited[input - 1] = 1;
        }
        
        int check = 0;
        for (int i = 0; i < N; i++) {
            if (visited[i] == 1) {
                check += 1;
            }
        }
        
        if (check == N) {
            result = "Yes";
        }
        else{
            result = "No";
        }
        
        cout << "#" << test_case << " " << result << "\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
