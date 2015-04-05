#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        int row = board.size(), col = board[0].size();
        int *v = new int[row * col];
        bool r;
        int i, j;
        for (i = 0; i < board.size(); ++i)
        {
            for(j = 0; j < board[0].size(); ++j)
            {
                memset(v, 0, sizeof(int) * row * col);
                r = dfs(board, v, i, j, word, 0);
                if (r == true) return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char> > &board, int *v,
             int x, int y, string &word, int s)
    {
        if (s == word.size()) return true;
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) return false;
        int col = board[0].size();
        if (v[x * col + y] == 1 || board[x][y] != word[s]) return false;
        v[x * col + y] = 1;
        if (dfs(board, v, x + 1, y, word, s + 1) ||
            dfs(board, v, x - 1, y, word, s + 1) ||
            dfs(board, v, x, y + 1, word, s + 1) ||
            dfs(board, v, x, y - 1, word, s + 1)) return true;
        v[x * col + y] = 0;
        return false;
    }
};

int main()
{
    Solution s;
    char a[][5] = {"ABCE",
                   "SFCS",
                   "ADEE"};
//     char a[][5] = {"ABCE",
//                    "SFES",
//                    "ADEE"};
    vector<vector<char> > board;
    int i;
    for (i = 0; i < 3; ++i)
        board.push_back(vector<char>(a[i], a[i] + 4));
    string str;
    str = "ABCCED";
    cout<<s.exist(board, str)<<endl;
    str = "SEE";
    cout<<s.exist(board, str)<<endl;
    str = "ABCB";
    cout<<s.exist(board, str)<<endl;
    str = "ABCESEEEFS";
    cout<<s.exist(board, str)<<endl;
//     board.clear();
//     board.push_back(vector<char>('a', 1));
//     cout<<s.exist(board, str)<<endl;
}
