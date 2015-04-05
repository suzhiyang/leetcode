#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<int> > &r, vector<int> &num, vector<int> &cur, vector<int> &used)
    {
        if (cur.size() == num.size())
        {
            r.push_back(cur);
            return;
        }
        int i;
        for (i = 0; i < num.size(); ++i)
        {
            if (i > 0 && num[i] == num[i - 1] && used[i - 1] == 0) continue;
            if (used[i] == 0)
            {
                used[i] = 1;
                cur.push_back(num[i]);
                dfs(r, num, cur, used);
                used[i] = 0;
                cur.pop_back();
            }
        }
    }
    
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > r;
        vector<int> used(num.size(), 0), cur;
        sort(num.begin(), num.end());
        dfs(r, num, cur, used);
        return r;
    }
};

int main()
{
    Solution s;
    int a[] = {1,1,2};
    vector<int> num(a, a + sizeof(a) / sizeof(int));
    vector<vector<int> > r = s.permuteUnique(num);
    int i, j;
    for (i = 0; i < r.size(); ++i)
    {
        for (j = 0; j < r[i].size(); ++j)
            cout<<r[i][j]<<" ";
        cout<<endl;
    }
}
