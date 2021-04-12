#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

string intToBin(int num, int cnt){
    string temp = "";
    for (int i = 0; i < cnt; i++) {
        if (num % 2 == 0) {
            temp += '0';
        }
        else{
            temp += '1';
        }
        num /= 2;
    }
    return temp;
}

int main(void)
{
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int N, M;
        cin >> N >> M;
        
        string tempResult = "ON";
        
        string temp = intToBin(M, N);
        
        for (int i = 0; i < temp.size(); i++) {
            if (temp[i] == '0') {
                tempResult = "OFF";
                break;
            }
        }
        
        cout << "#" << test_case << " " << tempResult << "\n";
    }
    return 0;
}
