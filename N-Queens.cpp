#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    vector<int> pos;
    vector<vector<string> > r;
    int expectn;
public:
    void pushsol()
    {
        int i;
        vector<string> sol;
        for (i = 0; i < expectn; ++i)
        {
            string str(expectn, '.');
            str[pos[i]] = 'Q';
            sol.push_back(str);
        }
        r.push_back(sol);
    }

    bool check(int k)
    {
        int i;
        for (i = 0; i < k; ++i)
        {
            if (pos[i] == pos[k] || pos[i] - pos[k] == k - i
                || pos[k] - pos[i] == k - i) return false;
        }
        return true;
    }
    
    void solve(int k)
    {
        if (k == expectn)
            pushsol();
        else
        {
            int i;
            for (i = 0; i < expectn; ++i)
            {
                pos[k] = i;
                if (check(k)) solve(k + 1);
            }
        }
    }
    
    vector<vector<string> > solveNQueens(int n) {
        if (n == 1)
        {
            r.push_back(vector<string>(1, "Q"));
        }
        else if (n == 2 || n == 3) ;
        else
        {
            pos.clear();
            int i;
            for (i = 0; i < n; ++i)
                pos.push_back(0);
            expectn = n;
            solve(0);
        }
        return r;
    }
};

int main()
{
    Solution s;
    int n = 4;
    n = 1;
    vector<vector<string> > r = s.solveNQueens(5);
    int i, j;
    for (i = 0; i < r.size(); ++i)
    {
        cout<<"["<<endl;
        for (j = 0; j < r[i].size(); ++j)
            cout<<" "<<r[i][j]<<endl;
        cout<<"]"<<endl;
    }
}
