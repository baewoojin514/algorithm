#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int idx[10][2] = {{3, 1}, {0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2}};

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    int leftX = 3;
    int leftY = 0;
    
    int rightX = 3;
    int rightY = 2;
    
    for (int i = 0; i < numbers.size(); i++) {
        int tempNum = numbers[i];
        if (tempNum == 1 || tempNum == 4 || tempNum == 7) {
            answer += "L";
            leftX = idx[tempNum][0];
            leftY = idx[tempNum][1];
        }
        else if (tempNum == 3 || tempNum == 6 || tempNum == 9){
            answer += "R";
            rightX = idx[tempNum][0];
            rightY = idx[tempNum][1];
        }
        else{
            int lDis = abs(leftX - idx[tempNum][0]) + abs(leftY - idx[tempNum][1]);
            int rDis = abs(rightX - idx[tempNum][0]) + abs(rightY - idx[tempNum][1]);
            
            if (lDis > rDis) {
                answer += "R";
                rightX = idx[tempNum][0];
                rightY = idx[tempNum][1];
            }
            else if (lDis < rDis){
                answer += "L";
                leftX = idx[tempNum][0];
                leftY = idx[tempNum][1];
            }
            else{
                if (hand == "right") {
                    rightX = idx[tempNum][0];
                    rightY = idx[tempNum][1];
                    answer += "R";
                }
                else{
                    leftX = idx[tempNum][0];
                    leftY = idx[tempNum][1];
                    answer += "L";
                }
            }
        }
    }
    
    return answer;
}
