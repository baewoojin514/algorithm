//줄세우기(2631)
//LIS 알고리즘으로 해결할 수 있다.
//skill.1 - 가장 긴 부분 증가수열의 길이를 찾는다.
//skill.2 - 1의 결과를 제외한 학생들만 움직이면 최소의 움직임으로 오름차순 정렬을 할 수 있다.

#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

vector<int> student;
int N;

int main(void){
    cin >> N;
    for (int i = 0; i < N; i++) {
        int input;
        cin >> input;
        
        int idx = lower_bound(student.begin(), student.end(), input) - student.begin();
        if (idx == student.size()) {
            student.push_back(input);
        }
        else{
            student[idx] = input;
        }
    }
    
    cout << N - student.size();
    
    return 0;
}
