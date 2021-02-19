#트리 순회(1991)
#skill.1 - 이차원 리스트의 [a][0] 에 left child를 정수형으로 변환해서 저장한다.
#skill.2 - 이차원 리스트의 [a][1] 에 right child를 정수형으로 변환해서 저장한다.
#전위 순회(preorder) : (루트) (왼쪽 자식) (오른쪽 자식)
#중위 순회(inorder) : (왼쪽 자식) (루트) (오른쪽 자식)
#후위 순회(postorder) : (왼쪽 자식) (오른쪽 자식) (루트)

def preorder(X):
    if X == -1:
        return
    print(chr(X + 65), end = "")
    preorder(tree[X][0])
    preorder(tree[X][1])


def inorder(X):
    if X == -1:
        return
    inorder(tree[X][0])
    print(chr(X + 65), end="")
    inorder(tree[X][1])


def postorder(X):
    if X == -1:
        return
    postorder(tree[X][0])
    postorder(tree[X][1])
    print(chr(X + 65), end="")


N = int(input())
tree = [[0] * 2 for _ in range(26)]

for _ in range(N):
    a, b, c = map(str, input().split())
    a = ord(a) - 65
    #알파벳을 정수형으로 바꾸기 위해서는 ord를 사용해야 한다.
    if b == '.':
        tree[a][0] -= 1
    else:
        tree[a][0] = ord(b) - 65

    if c == '.':
        tree[a][1] -= 1
    else:
        tree[a][1] = ord(c) - 65

preorder(0)
print()
inorder(0)
print()
postorder(0)
