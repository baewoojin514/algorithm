//컨베이어 벨트 위의 로봇(20055)
//컨베이터 벨트 회전시 그리고 로봇들이 움직인 후 떨어지는 위치의 로봇이 떨어진다.
//c++의 deque와 배열을 사용해서 문제를 해결한다.

#include <iostream>
#include <deque>

using namespace std;

int belt[200];
//N이 최대 100까지 임으로 index를 200으로 설정한다.
int N, K;
int robot[100];
//로봇의 움직임을 구현할 배열이다.
int totalTime = 0;

deque<int> q;

int main(void){
    cin >> N >> K;
    for(int i = 0; i < 2 * N; i++){
        cin >> belt[i];
        q.push_back(belt[i]);
    }
    while (true) {
        totalTime += 1;
        int a = q.back();
        q.pop_back();
        q.push_front(a);
        //deque의 요소의 삽입과 삭제가 앞, 뒤로 가능한 것은 python과 매우 유사하다.
        
        for(int i = N - 2; i >= 0; i--){
            robot[i + 1] = robot[i];
            robot[i] = 0;
        }
        robot[N - 1] = 0;
        //컨베이어 벨트 회전과 동시에 로봇의 위치도 변한다.
        for(int i = N - 2; i >= 0; i--){
            if(robot[i] != 0){
                if(robot[i + 1] == 0 && q.at(i + 1) > 0){
                    robot[i + 1] = robot[i];
                    robot[i] = 0;
                    q.at(i + 1) -= 1;
                }
                else{
                    robot[i] = robot[i];
                }
            }
        }
        robot[N - 1] = 0;
        if(q.at(0) > 0 && robot[0] == 0){
            q.at(0) -= 1;
            robot[0] = totalTime;
        }
        int tempCount = 0;
        for (auto i = q.begin(); i != q.end(); i++){
            if(*i == 0){
                tempCount += 1;
            }
        }
        //deque의 원소에 접근해서 특정 정수의 개수를 count한다.
        if(tempCount >= K){
            printf("%d\n", totalTime);
            break;
        }
    }
    return 0;
}
