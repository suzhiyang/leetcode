#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool dfs(vector<vector<char> > &board, vector<vector<bool> > &v, int x, int y, string &word, int pos)
    {
        if (v[x][y] == true) return false;
        if (pos == word.size() - 1)
        {
            if (board[x][y] == word[pos]) return true;
            else return false;
        }
        int m = board.size(), n = board[0].size();
        if (board[x][y] == word[pos])
        {
            v[x][y] = true;
            if (x + 1 < m && dfs(board, v, x + 1, y, word, pos + 1)) return true;
            if (x - 1 >= 0 && dfs(board, v, x - 1, y, word, pos + 1)) return true;
            if (y + 1 < n && dfs(board, v, x, y + 1, word, pos + 1)) return true;
            if (y - 1 >= 0 && dfs(board, v, x, y - 1, word, pos + 1)) return true;
            v[x][y] = false;
        }
        return false;
    }
    
    bool exist(vector<vector<char> >& board, string word) {
        if (word == "") return true;
        vector<vector<bool> > v(board.size(), vector<bool>(board[0].size(), false));
        int i, j;
        for (i = 0; i < board.size(); ++i)
        {
            for (j = 0; j < board[i].size(); ++j)
                if (dfs(board, v, i, j, word, 0)) return true;
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<vector<char> > board;
    char a[][10] = {"ABCE",
                    "SFCS",
                    "ADEE"};
    int i, j;
    for (i = 0; i < 3; ++i)
        board.push_back(vector<char>(a[i], a[i] + 4));
    cout<<s.exist(board, "ABCCED")<<endl;
    cout<<s.exist(board, "ABCB")<<endl;
}
