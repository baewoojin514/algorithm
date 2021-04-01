//괄호 추가하기(16637)
//dfs를 통해 해결할 수 있다.
//skill.1 - 괄호로 묶는 경우 그리고 묶지 않는 경우로 나눌 수 있다.
//skill.2 - 괄호로 묵는 경우는 묶인 괄호 내부의 연산과 이전 까지의 값들을 연산해서 idx + 4 를 통해서 재귀 함수를 호출한다.
//skill.3 - 괄호로 묶지 않는 경우는 idx + 2 를 통해서 재귀 함수를 호출한다.

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <stdio.h>
#include <cstring>
#include <vector>
#define INF 1e9

using namespace std;

int result = -INF;
int N;

string input;

int calculateValue(int a, int b, char op){
    if (op == '+') {
        //더하기 값을 반환한다.
        return a + b;
    }
    if (op == '-') {
        //빼기 값을 반환한다.
        return a - b;
    }
    return a * b;
    //곱셈 값을 반환한다.
}

void dfs(int idx, int tempSum){
    if (idx >= N) {
        //idx가 N 이상일 경우 최대값을 갱신하고 종료한다.
        result = max(result, tempSum);
        return;
    }
    char op;
    if (idx == 0) {
        op = '+';
    }
    else{
        op = input[idx - 1];
    }
    if (idx + 2 < N) {
        int temp;
        temp = calculateValue(input[idx] - '0', input[idx + 2] - '0', input[idx + 1]);
        //- '0' 을 통해 char to int 변환을 할 수 있다.
        dfs(idx + 4, calculateValue(tempSum, temp, op));
        //괄호로 묶는 경우 + 4 idx 부터 탐색을 시작한다.
    }
    dfs(idx + 2, calculateValue(tempSum, input[idx] - '0', op));
    //괄호로 묶지 않는 경우 현재 수와 이전 까지의 결과 값을 op을 통해 연산하여 준다.
}

int main(void){
    cin >> N;
    cin >> input;
    
    dfs(0, 0);
    
    cout << result;
    
    return 0;
}
