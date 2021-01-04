//공유기 설치(2110)
//python3와 같은 방식으로 구현한다.
//이분 탐색으로 해결한다.
//탐색 범위를 1부터 가장 멀리 떨어진 집간의 거리로 설정한다.
//주어진 C보다 더 많은 공유기를 설치할 수 있다면 거리를 늘리고 반대의 경우라면 거리를 줄인다.
//skill.1 - 이분 탐색을 위하여 집의 좌표를 정렬해야 한다.
//skill.2 - 현재 집을 기준으로 거리를 더해서 다음 집의 좌표보다 작거나 같다면 count를 늘린다.
//skill.3 - vector에 집의 좌표를 입력 받아 정렬시 편하게 한다.

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int N, C;
int result = 0;

vector<int> house;

int main(void){
    
    cin >> N >> C;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        house.push_back(a);
    }
    //집의 좌표를 입력한다.
    sort(house.begin(), house.end());
    //vector를 사용하면 정렬을 하기 편하다.
    
    int left = house.front();
    int right = house.back();
    
    int start = 1;
    int end = right - left;
    
    while (start <= end) {
        int mid = (start + end) / 2;
        int value = 0;
        int count = 1;
        
        for (int i = 1; i < N; i++) {
            if (house.at(i) >= house.at(value) + mid) {
                count += 1;
                value = i;
            }
        }
        //at을 사용하면 index로 편하게 vector 요소에 접근할 수 있다.
        if (count >= C) {
            start = mid + 1;
            result = mid;
        }
        else{
            end = mid - 1;
        }
        
    }
    cout << result;
    
    return 0;
}
