#include<iostream>

using namespace std;

int main(void)
{
    int test_case;
    int T;
    cin>>T;
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int hour_1, hour_2, minute_1, minute_2;
        int newHour, newMinute;
        
        cin >> hour_1 >> minute_1 >> hour_2 >> minute_2;
        
        newHour = hour_1 + hour_2;
        newMinute = minute_1 + minute_2;
        
        if (newMinute > 60) {
            //60분이 넘어가면 1시간이 된다.
            newHour += 1;
        }
        newHour %= 12;
        newMinute %= 60;
        
        if (newHour == 0) {
            newHour = 12;
        }
        
        cout << "#" << test_case << " " << newHour << " " << newMinute << "\n";

    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

