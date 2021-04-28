#include <iostream>

using namespace std;

int main(void)
{
    int test_case;
    int T;
    
    cin>>T;
   
    for(test_case = 1; test_case <= T; ++test_case)
    {
        string command;
        cin >> command;
        
        int leftNode = 1;
        int rightNode = 1;
        for (int i = 0; i < command.size(); i++) {
            if (command[i] == 'L') {
                rightNode += leftNode;
            }
            else{
                leftNode += rightNode;
            }
        }
        cout << "#" << test_case << " " << leftNode << " " << rightNode << "\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
