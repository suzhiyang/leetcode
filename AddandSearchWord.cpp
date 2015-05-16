#include <iostream>
#include <string>

using namespace std;

class TrieNode {
public:
    TrieNode *child[26];
    bool key;
    TrieNode(): key(false)
    {
        for (int i = 0; i < 26; ++i)
            child[i] = NULL;
    }
};

class WordDictionary {
public:
    TrieNode *root;

    WordDictionary() {
        root = new TrieNode();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        int i;
        TrieNode *cur = root;
        for (i = 0; i < word.size(); ++i)
        {
            if (cur->child[word[i] - 'a'] == NULL)
            {
                cur->child[word[i] - 'a'] = new TrieNode();
            }
            cur = cur->child[word[i] - 'a'];
        }
        cur->key = true;
    }

    bool dfs(string &word, int start, TrieNode *t)
    {
        int i;
        if (t == NULL) return false;
        if (start == word.size() - 1)
        {
            if(t->key == true) return true;
            else return false;
        }
        if (word[start + 1] == '.')
        {
            for (i = 0; i < 26; ++i)
            {
                if (dfs(word, start + 1, t->child[i])) return true;
            }
            return false;
        }
        return dfs(word, start + 1, t->child[word[start + 1] - 'a']);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        if (word[0] == '.')
        {
            for (int i = 0; i < 26; ++i)
                if (dfs(word, 0, root->child[i])) return true;
            return false;
        }
        return dfs(word, 0, root->child[word[0] - 'a']);
    }
};

int main()
{
    WordDictionary wordDictionary;
    wordDictionary.addWord("bad");
    wordDictionary.addWord("dad");
    wordDictionary.addWord("mad");
    wordDictionary.addWord("a");
    cout<<wordDictionary.search("bad")<<endl;
    cout<<wordDictionary.search("pad")<<endl;
    cout<<wordDictionary.search(".ad")<<endl;
    cout<<wordDictionary.search("b.d")<<endl;
    cout<<wordDictionary.search("...")<<endl;
    cout<<wordDictionary.search("..d")<<endl;
    cout<<wordDictionary.search("..")<<endl;
    cout<<wordDictionary.search("b...")<<endl;
}
