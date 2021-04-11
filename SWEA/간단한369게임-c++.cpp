#include<iostream>
#include<string>

using namespace std;

int intTo369(int num){
    string temp = to_string(num);
    
    int cnt = 0;
    for (int i = 0; i < temp.size(); i++) {
        if (temp[i] == '3' || temp[i] == '6' || temp[i] == '9') {
            cnt += 1;
        }
    }
    return cnt;
}

int main()
{
    int input;
    cin >> input;
    for (int i = 1; i < input + 1; i++) {
        int cnt = intTo369(i);
        if (cnt == 0) {
            cout << i << " ";
        }
        else{
            for (int i = 0; i < cnt; i++) {
                cout << "-";
            }
            cout << " ";
        }
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
