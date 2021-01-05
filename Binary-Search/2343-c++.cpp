//기타 레슨(2343)
//python3와 같은 방식으로 구현한다.
//이분 탐색으로 해결한다.
//블루레이는 모든 동영상을 다 포함할 수도 있고 동영상의 개수 만큼 존재할 수도 있다.
//skill.1 - 블루레이 크기를 기준으로 탐색한다. 블루레이 크기는 최대 모든 동영상 크기의 합과 동영상 길이의 최대값 사이이다.
//skill.2 - 블루레이에 담을 수 있는 영상들로 count하고 count가 M보다 작거나 같으면 블루레이 크기를 줄인다.
//skill.3 - count가 M보다 크면 블루레이 크기를 늘린다.


#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <numeric>

using namespace std;

int N, M;
int result = 0;

vector<int> video;

int main(void){
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        video.push_back(a);
    }
    int start = *max_element(video.begin(), video.end());
    //vector의 최대값은 max_element를 통해 찾는다.
    int end = accumulate(video.begin(), video.end(), 0);
    //vector의 요소들의 합은 accumulate를 통해 구할 수 있다.
    //마지막 parameter는 초기값을 의미한다.
    
    while (start <= end) {
        int mid = (start + end) / 2;
        
        int temp = 0;
        int count = 1;
        
        for (int i = 0; i < N; i++) {
            temp += video.at(i);
            if (temp > mid) {
                count += 1;
                temp = video.at(i);
            }
        }
        
        if (count <= M) {
            end = mid - 1;
            result = mid;
        }
        else{
            start = mid + 1;
        }
    }
    cout << result;
    
    return 0;
}
