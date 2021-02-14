//반도체 설계(2352)
//skill.1 - 반도체 선은 꼬일 수 없다. 즉 연결된 port 번호가 증가하는 형태여야 한다.
//skill.2 - port 번호의 최장 증가 수열을 LIS 알고리즘을 통해 구해야 한다.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> num;

int main(void){
    cin >> n;
    
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        
        int idx = lower_bound(num.begin(), num.end(), a) - num.begin();
        
        if (idx == num.size()) {
            num.push_back(a);
        }
        else{
            num[idx] = a;
        }
    }
    
    cout << num.size();
    return 0;
}
