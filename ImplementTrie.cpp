class TrieNode {
public:
    // Initialize your data structure here.
    bool isleaf;
    TrieNode *p[26];
    TrieNode() : isleaf(false) {
        memset(p, 0, sizeof(p));
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        int i;
        TrieNode *cur = root;
        for (i = 0; i < word.size(); ++i)
        {
            if (cur->p[word[i] - 'a'] == NULL)
                cur->p[word[i] - 'a'] = new TrieNode();
            cur = cur->p[word[i] - 'a'];
        }
        cur->isleaf = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        int i;
        TrieNode *cur = root;
        for (i = 0; i < word.size(); ++i)
        {
            if (cur->p[word[i] - 'a'] == NULL) return false;
            cur = cur->p[word[i] - 'a'];
        }
        return cur->isleaf;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        int i;
        TrieNode *cur = root;
        for (i = 0; i < prefix.size(); ++i)
        {
            if (cur->p[prefix[i] - 'a'] == NULL) return false;
            cur = cur->p[prefix[i] - 'a'];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
