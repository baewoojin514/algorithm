#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
#include <cstring>
#include <string.h>
#define MAX 51

using namespace std;

int N;
int delNode;
int root;
int graph[MAX][MAX];
int visited[MAX];
int result = 0;

void input(){
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        int parent;
        cin >> parent;
        
        if (parent == -1) {
            root = i;
            continue;
        }
        graph[parent][i] = 1;
    }
    cin >> delNode;
}

void delChild(int delNode){
    for (int i = 0; i < N; i++) {
        if (graph[i][delNode]) {
            graph[i][delNode] = 0;
        }
    }
    
    return;
}

void dfs(int root){
    vector<int> tempVec;
    int tempCnt = 0;
    for (int i = 0; i < N; i++) {
        if (graph[root][i] && !visited[i]) {
            tempCnt += 1;
            tempVec.push_back(i);
        }
    }
    
    if (!tempVec.size()) {
        result += 1;
        return;
    }
    for (int i = 0; i < tempVec.size(); i++) {
        visited[tempVec[i]] = 1;
        dfs(tempVec[i]);
    }
    tempVec.clear();
}


int main(void)
{
    input();
    delChild(delNode);
    visited[root] = 1;
    dfs(root);
    
    if (root == delNode) {
        cout << 0;
    }
    else{
        cout << result;
    }
    return 0;
}
