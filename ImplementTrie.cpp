#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class TrieNode {
public:
    TrieNode *child[26];
    int val;
public:
    // Initialize your data structure here.
    TrieNode(): val(0) {
        for (int i = 0; i < 26; ++i)
            child[i] = NULL;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
        int i;
        TrieNode *cur = root;
        for (i = 0; i < s.size(); ++i)
        {
            if (cur->child[s[i] - 'a'] == NULL)
            {
                cur->child[s[i] - 'a'] = new TrieNode();
            }
            cur = cur->child[s[i] - 'a'];
        }
        ++cur->val;
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        int i;
        TrieNode *cur = root;
        for (i = 0; i < key.size(); ++i)
        {
            if (cur->child[key[i] - 'a'] == NULL) return false;
            cur = cur->child[key[i] - 'a'];
        }
        if (cur->val > 0) return true;
        else return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        int i;
        TrieNode *cur = root;
        for (i = 0; i < prefix.size(); ++i)
        {
            if (cur->child[prefix[i] - 'a'] == NULL) return false;
            cur = cur->child[prefix[i] - 'a'];
        }
        return true;
    }

private:
    TrieNode* root;
};

int main()
{
    Trie trie;
    trie.insert("abc");
    trie.insert("bat");
    cout<<trie.search("abcd")<<endl;
    cout<<trie.search("abc")<<endl;
    cout<<trie.startsWith("ab")<<endl;
    cout<<trie.startsWith("ba")<<endl;
    cout<<trie.startsWith("bc")<<endl;
    cout<<trie.search("ba")<<endl;
}
