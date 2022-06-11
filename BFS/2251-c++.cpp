//물통(2251)
//bfs 탐색
//a -> b, b -> a, b -> c, c -> b, a -> c, c -> a 6가지 경우 탐색
//skill.1 - 위의 6가지 중 가능한 경우 물 옮기고 queue에 저장
//skill.2 - a 물통이 빈 경우 c 물양을 vector에 저장

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define MAX 201

using namespace std;

int visited[MAX][MAX][MAX];
int A, B, C;

queue<pair<pair<int, int>, int>> water;
vector<int> cWater;

void moveWater(){
    while (!water.empty()) {
        int ca, cb, cc;
        ca = water.front().first.first;
        cb = water.front().first.second;
        cc = water.front().second;
        
        water.pop();
        
        if (visited[ca][cb][cc]) {
            continue;
        }
        visited[ca][cb][cc] = 1;
        
        if (ca == 0) {
            cWater.push_back(cc);
        }
        
        //a -> b
        if (ca + cb > B) {
            water.push(make_pair(make_pair(ca + cb - B, B), cc));
        }
        else{
            water.push(make_pair(make_pair(0, ca + cb), cc));
        }
        
        //b -> a
        if (cb + ca > A) {
            water.push(make_pair(make_pair(A, cb + ca - A), cc));
        }
        else{
            water.push(make_pair(make_pair(ca + cb, 0), cc));
        }
        
        //b -> c
        if (cb + cc > C) {
            water.push(make_pair(make_pair(ca, cb + cc - C), C));
        }
        else{
            water.push(make_pair(make_pair(ca, 0), cb + cc));
        }
        
        //c -> b
        if (cc + cb > B) {
            water.push(make_pair(make_pair(ca, B), cc + cb - B));
        }
        else{
            water.push(make_pair(make_pair(ca, cc + cb), 0));
        }
        
        //a -> c
        if (ca + cc > C) {
            water.push(make_pair(make_pair(ca + cc - C, cb), C));
        }
        else{
            water.push(make_pair(make_pair(0, cb), ca + cc));
        }
        
        //c -> a
        if (cc + ca > A) {
            water.push(make_pair(make_pair(A, cb), cc + ca - A));
        }
        else{
            water.push(make_pair(make_pair(cc + ca, cb), 0));
        }
    }
}

int main(void)
{
    cin >> A >> B >> C;
    
    water.push(make_pair(make_pair(0, 0), C));
    
    moveWater();
    
    sort(cWater.begin(), cWater.end());
    
    for (int i = 0; i < cWater.size(); i++) {
        cout << cWater[i] << " ";
    }
    cout << endl;
   
    return 0;
}
