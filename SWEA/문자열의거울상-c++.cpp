#include <iostream>

using namespace std;

char charToMirror(char C){
    if (C == 'b') {
        return 'd';
    }
    else if (C == 'd'){
        return 'b';
    }
    else if (C == 'p'){
        return 'q';
    }
    return 'p';
}

int main(void)
{
    int test_case;
    int T;
    
    cin>>T;
   
    for(test_case = 1; test_case <= T; ++test_case)
    {
        string str;
        cin >> str;
        string result = "";
        for (int i = str.size() - 1; i >= 0 ; i--) {
            result += charToMirror(str[i]);
        }
        cout << "#" << test_case << " " << result << "\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
