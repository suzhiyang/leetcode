#include <iostream>
#include <vector>
#include <set>
#include <cstring>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        int a[] = {1,2,3,4,5,6,7,8,9};
        vector<vector<set<int> > > candidates(9, vector<set<int> >(9, set<int>(a, a + 9)));
        int bitset[10], left = 0;
        int i, j, t;
        char c;
        // Check unfill grid number
        for(i = 0; i < 9; ++i)
        {
            for(j = 0; j < 9; ++j)
            {
                if (board[i][j] == '.') ++left;
                else candidates[i][j].clear();
            }
        }
        while(left > 0)
        {
            
        }
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
    s.solveSudoku(board);
    for(i = 0; i < 9; ++i)
    {
        for(j = 0; j < 9; ++j)
            cout<<board[i][j]<<" ";
        cout<<endl;
    }
}
