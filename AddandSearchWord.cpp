#include <iostream>

using namespace std;

struct TrieNode
{
    TrieNode *a[26];
    bool isleaf;
    TrieNode() : isleaf(false)
    {
        for (int i = 0; i < 26; ++i)
            a[i] = NULL;
    }
};

class WordDictionary {
public:
    TrieNode *root;

    WordDictionary()
    {
        root = new TrieNode();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        int i;
        TrieNode *cur = root;
        for (i = 0; i < word.size(); ++i)
        {
            if (cur->a[word[i] - 'a'] == NULL)
                cur->a[word[i] - 'a'] = new TrieNode();
            cur = cur->a[word[i] - 'a'];
        }
        cur->isleaf = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string &word, int index, TrieNode *cur) {
        if (index == word.size())
            return cur->isleaf;
        int i;
        if (word[index] == '.')
        {
            for (i = 0; i < 26; ++i)
                if (cur->a[i] != NULL && search(word, index + 1, cur->a[i])) return true;
        }
        else
        {
            if (cur->a[word[index] - 'a'] != NULL)
                return search(word, index + 1, cur->a[word[index] - 'a']);
        }
        return false;
    }

    bool search(string word) {
        return search(word, 0, root);
    }
};

int main()
{
    WordDictionary wd;
    wd.addWord("bad");
    wd.addWord("dad");
    wd.addWord("mad");
    cout<<wd.search("pad")<<endl;
    cout<<wd.search("bad")<<endl;
    cout<<wd.search(".ad")<<endl;
    cout<<wd.search("b..")<<endl;
    cout<<wd.search("ba")<<endl;
}
