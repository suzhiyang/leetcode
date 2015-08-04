#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TrieNode
{
    TrieNode *root;
    TrieNode *p[26];
    int count;
    bool isleaf;
    bool added;
    TrieNode() : root(NULL), isleaf(false), count(0), added(false)
    {
        for (int i = 0; i < 26; ++i)
            p[i] = NULL;
    }
};

class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string &str)
    {
        int i;
        TrieNode *cur = root;
        for (i = 0; i < str.size(); ++i)
        {
            if (cur->p[str[i] - 'a'] == NULL)
            {
                ++cur->count;
                cur->p[str[i] - 'a'] = new TrieNode();
            }
            cur = cur->p[str[i] - 'a'];
        }
        cur->isleaf = true;
    }
};

class Solution {
public:
    vector<string> r;
    Trie trie;
    // v[i][j]: 0 - unvisited, 1 - visiting
    void dfs(vector<vector<char> > &a, vector<vector<int> > &v, string cur, int x, int y, TrieNode *node)
    {
        if (v[x][y] == 1) return;
        v[x][y] = 1;
        cur += a[x][y];
        if (node->p[a[x][y] - 'a'] != NULL)
        {
            if (node->p[a[x][y] - 'a']->isleaf == true && node->p[a[x][y] - 'a']->added == false)
            {
                r.push_back(cur);
                node->p[a[x][y] - 'a']->added = true;
            }
            if (x + 1 < a.size()) dfs(a, v, cur, x + 1, y, node->p[a[x][y] - 'a']);
            if (x - 1 >= 0) dfs(a, v, cur, x - 1, y, node->p[a[x][y] - 'a']);
            if (y + 1 < a[0].size())dfs(a, v, cur, x, y + 1, node->p[a[x][y] - 'a']);
            if (y - 1 >= 0) dfs(a, v, cur, x, y - 1, node->p[a[x][y] - 'a']);
        }
        v[x][y] = 0;
    }
    
    bool search(vector<vector<char> > &board)
    {
        int i, j;
        vector<vector<int> > v(board.size(), vector<int>(board[0].size(), 0));
        for (i = 0; i < board.size(); ++i)
        {
            for (j = 0; j < board[0].size(); ++j)
            {
                string cur;
                dfs(board, v, cur, i, j, trie.root);
            }
        }
        return false;
    }
    
    vector<string> findWords(vector<vector<char> > &board, vector<string> &words) {
        int i;
        for (i = 0; i < words.size(); ++i)
            trie.insert(words[i]);
        search(board);
        return r;
    }
};

int main()
{
    Solution s;
    vector<vector<char> > board;
    char a[][5] = {{'o','a','a','n'},
                   {'e','t','a','e'},
                   {'i','h','k','r'},
                   {'i','f','l','v'}};
    int i;
    for (i = 0; i < 4; ++i)
    {
        vector<char> cv(a[i], a[i] + 4);
        board.push_back(cv);
    }
    vector<string> words;
    string str;
    char wc[][10] = {"oath", "pea","eat","rain"};
    for (i = 0; i < 4; ++i)
        words.push_back(wc[i]);
    vector<string> r;
    r = s.findWords(board, words);
    for (i = 0; i < r.size(); ++i)
        cout<<r[i]<<endl;
    cout<<endl;
    // "aa", "a"
    Solution s1;
    board.clear();
    board.push_back(vector<char>(2, 'a'));
    words.clear();
    words.push_back("a");
    r = s1.findWords(board, words);
    for (i = 0; i < r.size(); ++i)
        cout<<r[i]<<endl;
    cout<<endl;
    // ["ab","cd"], ["cdba"]
    Solution s2;
    board.clear();
    vector<char> c1, c2;
    c1.push_back('a'); c1.push_back('b');
    board.push_back(c1);
    c2.push_back('c'); c2.push_back('d');
    board.push_back(c2);
    words.clear();
    words.push_back("cdba");
    r = s2.findWords(board, words);
    for (i = 0; i < r.size(); ++i)
        cout<<r[i]<<endl;
}
