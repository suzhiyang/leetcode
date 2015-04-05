#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > result;
        if (num.size() < 4) return result;
        int i, j, k, l, r, t;
        sort(num.begin(), num.end());
        for (i = 0; i < num.size() - 3; ++i)
        {
            for(j = i + 1; j < num.size() - 2; ++j)
            {
                l = j + 1; r = num.size() - 1;
                while(l < r)
                {
                    t = num[i] + num[j] + num[l] + num[r];
                    if (t == target)
                    {
                        vector<int> v(1, num[i]);
                        v.push_back(num[j]); v.push_back(num[l]); v.push_back(num[r]);
                        result.push_back(v);
                        while(l < r && num[l] == num[l + 1]) ++l;
                        while(r > l && num[r] == num[r - 1]) --r;
                        ++l; --r;
                    }
                    else if (t < target) ++l;
                    else --r;
                }
                while(num[j] == num[j + 1]) ++j;
            }
            while(num[i] == num[i + 1]) ++i;
        }
        return result;
    }
};

int main()
{
    Solution s;
    int a[] = {1, 0, -1, 0, -2, 2};
    vector<int> num(a, a + sizeof(a) / sizeof(int));
    vector<vector<int> > r = s.fourSum(num, 0);
    int i, j;
    for(i = 0; i < r.size(); ++i)
    {
        for(j = 0; j < r[i].size(); ++j)
            cout<<r[i][j]<<",";
        cout<<endl;
    }
}
