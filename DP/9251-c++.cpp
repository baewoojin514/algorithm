//LCS(9251)
//최장 공통 부분 문자열을 통해 해결할 수 있다.

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <stdio.h>
#include <cstring>

#define MAX 1001

using namespace std;

int LCS[MAX][MAX];

string str1, str2;

int main(void){
    string tmp1, tmp2;
    cin >> tmp1;
    cin >> tmp2;
    
    str1 = '*' + tmp1;
    str2 = '*' + tmp2;
    
    for (int i = 0; i < str1.size(); i++) {
        for (int j = 0; j < str2.size(); j++) {
            if (i == 0 || j == 0) {
                LCS[i][j] = 0;
                continue;
            }
            if (str1[i] == str2[j]) {
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            }
            else{
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
            }
        }
    }
    
    cout << LCS[str1.size() - 1][str2.size() - 1];
    
    return 0;
}
