#include <iostream>
#include <string>

using namespace std;

int checkDate(string temp){
    string part1 = temp.substr(0, 2);
    string part2 = temp.substr(2, 2);
    int part1ToInt = stoi(part1);
    int part2ToInt = stoi(part2);
    
    if (part1ToInt <= 12 && part1ToInt != 0) {
        if (part2ToInt <= 12 && part2ToInt != 0) {
            return 1;
        }
        else{
            return 2;
        }
    }
    else{
        if (part2ToInt <= 12 && part2ToInt != 0) {
            return 3;
        }
        else{
            return 4;
        }
    }
    return 5;
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
        
        string result;
        
        int tempResult;
        tempResult = checkDate(str);
        
        if (tempResult == 1) {
            result = "AMBIGUOUS";
        }
        else if (tempResult == 2){
            result = "MMYY";
        }
        else if (tempResult == 3){
            result = "YYMM";
        }
        else{
            result = "NA";
        }
        cout << "#" << test_case << " " << result << "\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
