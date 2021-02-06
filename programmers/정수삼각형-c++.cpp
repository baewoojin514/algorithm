//정수 삼각형(programmers)
//행의 양쪽 끝 값일 경우 바로 위 행의 값을 더해주면 된다.
//중간에 낀 값인 경우 위 행의 오른쪽과 왼쪽의 값중 큰 값을 더해주면 된다.

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    for (int i = 1; i < triangle.size(); i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            if (j == 0) {
                triangle[i][j] = triangle[i][j] + triangle[i - 1][j];
            }
            else if (j == triangle[i].size() - 1){
                triangle[i][j] = triangle[i][j] + triangle[i - 1][j - 1];
            }
            else{
                triangle[i][j] = triangle[i][j] + max(triangle[i - 1][j - 1], triangle[i - 1][j]);
            }
        }
    }
    int maxValue = 0;
    int vsize = triangle.size();
    
    for (int i = 0; i < triangle[vsize - 1].size(); i++) {
        maxValue = max(maxValue, triangle[vsize - 1][i]);
    }
    return maxValue;
}
