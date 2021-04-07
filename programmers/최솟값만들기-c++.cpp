//최솟값 만들기(programmers)
//dfs로 해결할 수 있다.
//skill.1 - A의 index로 수열은 만드는 dfs 함수를 호출한다.
//skill.2 - 1의 함수에서 수열이 완성된 경우 B의 index로 수열을 만드는 dfs 함수를 호출한다.
//skill.3 - 2의 과정이 완료 후 index의 순서에 따라 곱을 하여 합을 구하고 최소값을 갱신한다.
//dfs로 구현시 시간 초과가 발생한다.

#include <iostream>
#include <vector>
#define INF 1e9

using namespace std;

int n;
vector<int> visited1;
vector<int> visited2;
vector<int> temp1;
vector<int> temp2;
int result;

void dfs2(int cnt, vector<int> A, vector<int> B){
    if (cnt == n) {
        int tempSum = 0;
        for (int i = 0; i < n; i++) {
            int idx1, idx2;
            idx1 = temp1[i]; idx2 = temp2[i];
            tempSum += A[idx1] * B[idx2];
        }
        result = min(result, tempSum);
    }
    for (int i = 0; i < n; i++) {
        if (visited2[i] == 0) {
            visited2[i] = 1;
            temp2.push_back(i);
            dfs2(cnt + 1, A, B);
            visited2[i] = 0;
            temp2.pop_back();
        }
    }
}

void dfs1(int cnt, vector<int> A, vector<int> B){
    if (cnt == n) {
        dfs2(0, A, B);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (visited1[i] == 0) {
            visited1[i] = 1;
            temp1.push_back(i);
            dfs1(cnt + 1, A, B);
            visited1[i] = 0;
            temp1.pop_back();
        }
    }
}

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    result = INF;
    
    n = A.size();
    visited1.resize(n);
    visited2.resize(n);
    
    dfs1(0, A, B);
    
    answer = result;
    
    return answer;
}

//최솟값 만들기(programmers)
//skill.1 - 큰 수일 수록 작은 수와 곱해져야 누적합을 최소값으로 만들 수 있다.
//skill.2 - A를 오름차순 정렬하고 B를 내림차순 정렬하여 같은 index 곱의 누접합을 구한다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

bool cmp(int A, int B){
    if (A > B) {
        return true;
    }
    return false;
}

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    n = A.size();
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), cmp);
    
    for (int i = 0; i < n; i++) {
        answer += A[i] * B[i];
    }
    
    return answer;
}
