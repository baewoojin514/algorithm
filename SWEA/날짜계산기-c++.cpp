#include<iostream>

using namespace std;

int daysPerMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(void)
{
    int test_case;
    int T;
    
    cin>>T;
   
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int result = 0;
        int month1, month2, day1, day2;
        cin >> month1 >> day1 >> month2 >> day2;
        
        if (month1 == month2) {
            result = day2 - day1 + 1;
        }
        else if (month2 - month1 == 1){
            result += daysPerMonth[month1] - day1 + 1;
            result += day2;
        }
        else{
            result += daysPerMonth[month1] - day1 + 1;
            result += day2;
            for (int i = month1 + 1; i < month2; i++) {
                result += daysPerMonth[i];
            }
        }
        cout << "#" << test_case << " " << result << "\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
