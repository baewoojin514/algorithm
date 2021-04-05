//쿼드압축 후 개수 세기(programmers)
//구현문제이다.
//skill.1 - arr의 길이에서 /2 를 하며 정사각형 이내의 요소가 모두 동일한지 확인한다.
//skill.2 - 모두 같은 값이라면 해당 값의 cnt_arr index에 += 1 한다.

#include <string>
#include <vector>
#include <cstring>

using namespace std;

int cnt_arr[2];
vector<vector<int>> copy_arr;
int N;

void dfs(int X, int Y, int limit){
    int compare = copy_arr[X][Y];
    bool check = true;
    for (int i = 0; i < limit; i++) {
        for (int j = 0; j < limit; j++) {
            if (copy_arr[X + i][Y + j] != compare) {
                check = false;
            }
        }
    }
    if (check) {
        cnt_arr[compare] += 1;
        return;
    }
    dfs(X, Y, limit/2);
    dfs(X + limit/2, Y, limit/2);
    dfs(X, Y + limit/2, limit/2);
    dfs(X + limit/2, Y + limit/2, limit/2);
}

vector<int> solution(vector<vector<int>> arr) {
    copy_arr = arr;
    memset(cnt_arr, 0, sizeof(cnt_arr));
    N = arr.size();
    dfs(0, 0, N);
    vector<int> answer;
    answer.push_back(cnt_arr[0]);
    answer.push_back(cnt_arr[1]);
    
    return answer;
}
