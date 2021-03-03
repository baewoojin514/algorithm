#자동완성(programmers)
#trie(트라이) 자료구조를 사용하여 해결 가능하다(python풀이가 유리하다).
#skill.1 - words 리스트의 요소들을 통해 Trie를 만든다.
#skill.2 - words 리스트의 요소들로 Trie를 탐색하면서 하위 노드가 1즉 더이상 분기하지 않는 index를 찾아 + 1을 answer에 더한다.

def makeTrie(words):
    Trie = {}
    for word in words:
        currentTrie = Trie
        for w in word:
            currentTrie.setdefault(w, [0, {}])
            #0은 하위 트리의 개수를 count하기 위함이다.
            currentTrie[w][0] += 1
            currentTrie = currentTrie[w][1]
            #currentTrie를 하위 트리로 바꿔준다.
    return Trie

def countChildTrie(temp, words):
    global answer
    for word in words:
        currentTrie = temp
        for i in range(len(word)):
            if currentTrie[word[i]][0] == 1:
                #하위 트리가 1개인 경우 더이상 분기하지 않는다는 의미이다.
                break
            currentTrie = currentTrie[word[i]][1]
            # currentTrie를 하위 트리로 바꿔준다.
        answer += i + 1

answer = 0

def solution(words):
    temp = makeTrie(words)
    countChildTrie(temp, words)

    return answer
