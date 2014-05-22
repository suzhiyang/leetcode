#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int bitset[10];
        int i, j, t;
        char c;
        // Validate each col
        for(i = 0; i < 9; ++i)
        {
            memset(bitset, 0, 10 * sizeof(int));
            for(j = 0; j < 9; ++j)
            {
                c = board[i][j];
                if (c == '.') continue;
                t = c - '0';
                if (bitset[t] == 1) return false;
                bitset[t] = 1;
            }
        }
        // Validate each row
        for(i = 0; i < 9; ++i)
        {
            memset(bitset, 0, 10 * sizeof(int));
            for(j = 0; j < 9; ++j)
            {
                c = board[j][i];
                if (c == '.') continue;
                t = c - '0';
                if (bitset[t] == 1) return false;
                bitset[t] = 1;
            }
        }
        // Validate subboxes
        for(i = 0; i < 9; i += 3)
        {
            for(j = 0; j < 9; j += 3)
            {
                memset(bitset, 0, 10 * sizeof(int));
                int m, n;
                for(m = i; m < i + 3; ++m)
                {
                    for(n = j; n < j + 3; ++n)
                    {
                        c = board[m][n];
                        if (c == '.') continue;
                        t = c - '0';
                        if (bitset[t] == 1) return false;
                        bitset[t] = 1;
                    }
                }
            }
        }
        return true;
    }
};

int main()
{
    vector<vector<char> > board(9, vector<char>(9));
    char *a[9] = {"..4...63.",".........","5......9.","...56....","4.3.....1","...7.....","...5.....",".........","........."};
        //{".87654321","2........","3........","4........","5........","6........","7........","8........","9........"};
    int i, j;
    for(i = 0; i < 9; ++i)
        board[i].assign(a[i], a[i] + 9);
    for(i = 0; i < 9; ++i)
    {
        for(j = 0; j < 9; ++j)
            cout<<board[i][j]<<" ";
        cout<<endl;
    }
    Solution s;
    cout<<s.isValidSudoku(board)<<endl;
}
