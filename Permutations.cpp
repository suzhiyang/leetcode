#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> > result;
        result.push_back(num);
        vector<vector<int> >::iterator last = --result.end();
        while(1)
        {
            int i, j, t;
            for(i = (*last).size() - 1; i > 0; --i)
                if ((*last)[i - 1] < (*last)[i]) break;
            if (i == 0) break;
            i = i - 1;
            for(j = (*last).size() - 1; j > 0; --j)
                if ((*last)[j] > (*last)[i]) break;
            vector<int> next(*last);
            t = next[i];
            next[i] = next[j];
            next[j] = t;
            sort(next.begin() + i + 1, next.end());
            result.push_back(next);
            last = --result.end();
        }
        return result;
    }
};

int main()
{
    Solution s;
    int a[] = {3, 1, 2};
    vector<int> num(a, a + 3);
    vector<vector<int> > r = s.permute(num);
    for(int i = 0; i < r.size(); ++i)
    {
        cout<<"[";
        for(int j = 0; j < r[i].size(); ++j)
        {
            cout<<r[i][j]<<",";
        }
        cout<<"]"<<endl;
    }
}
