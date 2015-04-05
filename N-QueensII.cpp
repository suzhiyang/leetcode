#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    vector<int> pos;
    int count;
    int expectn;
public:
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
            ++count;
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
    
    int totalNQueens(int n) {
        if (n == 1) return 1;
        else if (n == 2 || n == 3) return 0;
        else
        {
            pos.clear();
            int i;
            for (i = 0; i < n; ++i)
                pos.push_back(0);
            count = 0;
            expectn = n;
            solve(0);
        }
        return count;
    }
};

int main()
{
    Solution s;
    int i;
    for (i = 1; i < 10; ++i)
    {
        cout<<i<<" "<<s.totalNQueens(i)<<endl;
    }
}
