//가장 긴 증가하는 부분 수열(11053)
//최장 증가 수열은 LIS 알고리즘을 사용하여 구할 수 있다.
//LIS 알고리즘은 binary search로 구현이 가능하다.

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <vector>
#define MAX 1000

using namespace std;

int N;
vector<int> num;

int main(void){
    cin >> N;
    
    int a;
    for (int i = 0; i < N; i++) {
        cin >> a;
        
        int idx = lower_bound(num.begin(), num.end(), a) - num.begin();
        
        if (idx == num.size()) {
            num.push_back(a);
        }//vector의 후방에 숫자를 삽입한다.
        else{
            num[idx] = a;
        }//vector의 알맞은 위치에 숫자를 삽입한다.
    }
    
    cout << num.size();
    return 0;
}
