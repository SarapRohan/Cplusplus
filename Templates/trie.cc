#include <iostream>
#include <string>

using namespace std;

class trie {
  public:
    trie() {
        head = new trieNode();
        head->isEnd = false;
    }
    void insert(string word);
    bool search(string word);
    void print();
  private:
    struct trieNode {
        bool isEnd;
        trieNode* child[26];

        trieNode() {
            for (int i = 0; i < 26; i++)
                child[i] = NULL;
        }
    };
    trieNode* head;
};

void trie :: insert(string word) {
    trieNode* cur = head;
    for (int i = 0; i < word.length(); i++) {
        int letter = word[i] - 'a';
        if(cur->child[letter] == NULL)
            cur->child[letter] = new trieNode();
        cur = cur->child[letter];
    }
    cur->isEnd = true;
}

bool trie :: search(string word) {
    trieNode* cur = head;
    for (int i = 0; i < word.length(); i++) {
        int letter = word[i] - 'a';
        if(cur->child[letter] == NULL) return false;
        cur = cur->child[letter];
    }
    return cur->isEnd;
}

int main() {
}
