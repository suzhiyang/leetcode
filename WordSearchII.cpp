class TrieNode {
public:
    bool isleaf;
    TrieNode *p[26];
    TrieNode(): isleaf(false) {
        memset(p, 0, sizeof(p));
    }
};

class Trie {
public:
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }

    void insert(string &word)
    {
        TrieNode *cur = root;
        for (int i = 0; i < word.size(); ++i)
        {
            if (cur->p[word[i] - 'a'] == NULL)
                cur->p[word[i] - 'a'] = new TrieNode();
            cur = cur->p[word[i] - 'a'];
        }
        cur->isleaf = true;
    }
};

class Solution {
public:
    void dfs(vector<string> &r, string &cur, vector<vector<char> > &board, vector<vector<bool> > &v,
             TrieNode *t, int x, int y)
    {
        if (v[x][y]) return;
        v[x][y] = true;
        char &c = board[x][y];
        if (t->p[c - 'a'] != NULL)
        {
            cur += c;
            if (t->p[c - 'a']->isleaf)
            {
                t->p[c - 'a']->isleaf = false;
                r.push_back(cur);
            }
            if (x + 1 < board.size()) dfs(r, cur, board, v, t->p[c - 'a'], x + 1, y);
            if (x - 1 >= 0) dfs(r, cur, board, v, t->p[c - 'a'], x - 1, y);
            if (y + 1 < board[0].size()) dfs(r, cur, board, v, t->p[c - 'a'], x, y + 1);
            if (y - 1 >= 0) dfs(r, cur, board, v, t->p[c - 'a'], x, y - 1);
            cur.pop_back();
        }
        v[x][y] = false;
    }
    
    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        vector<string> r;
        if (board.size() == 0) return r;
        vector<vector<bool> > v(board.size(), vector<bool>(board[0].size(), false));
        Trie trie;
        int i, j;
        for (i = 0; i < words.size(); ++i)
            trie.insert(words[i]);
        for (i = 0; i < board.size(); ++i)
            for (j = 0; j < board[0].size(); ++j)
            {
                string cur;
                dfs(r, cur, board, v, trie.root, i, j);
            }
        return r;
    }
};
