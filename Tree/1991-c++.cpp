//트리 순회(1991)
//skill.1 - 이차원 배열의 [a][0] 에 left child를 정수형으로 변환해서 저장한다.
//skill.2 - 이차원 배열의 [a][1] 에 right child를 정수형으로 변환해서 저장한다.
//전위 순회(preorder) : (루트) (왼쪽 자식) (오른쪽 자식)
//중위 순회(inorder) : (왼쪽 자식) (루트) (오른쪽 자식)
//후위 순회(postorder) : (왼쪽 자식) (오른쪽 자식) (루트)

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define MAX 26
//대문자 알파벳의 개수는 26개이다.

using namespace std;

int tree[MAX][2];
int N;

void preorder(int X){
    if (X == -1) {
        //자식이 없는 경우이다.
        return;
    }
    cout << (char)(X + 'A');
    preorder(tree[X][0]);
    preorder(tree[X][1]);
}

void inorder(int X){
    if (X == -1) {
        //자식이 없는 경우이다.
        return;
    }
    inorder(tree[X][0]);
    cout << (char)(X + 'A');
    inorder(tree[X][1]);
}

void postorder(int X){
    if (X == -1) {
        //자식이 없는 경우이다.
        return;
    }
    postorder(tree[X][0]);
    postorder(tree[X][1]);
    cout << (char)(X + 'A');
}

int main(void){
    cin >> N;
    for (int i = 0; i < N; i++) {
        char a, b, c;
        cin >> a >> b >> c;
        a -= 'A';
        if (b == '.') {
            tree[a][0] -= 1;
        }
        else{
            tree[a][0] = b -= 'A';
        }
        //left child가 없으면 -1을 저장하고 아니면 정수형으로 변환해서 자식 노드를 저장한다.
        
        if (c == '.') {
            tree[a][1] -= 1;
        }
        else{
            tree[a][1] = c -= 'A';
        }
        //right child가 없으면 -1을 저장하고 아니면 정수형으로 변환해서 자식 노드를 저장한다.
    }
    preorder(0);
    //루트 노드는 A이다. 따라서 A - 'A' = 0 이다.
    cout << "\n";
    inorder(0);
    cout << "\n";
    postorder(0);
    
    return 0;
}
