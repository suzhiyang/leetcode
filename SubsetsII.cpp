#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > r(1, vector<int>());
        sort(nums.begin(), nums.end());
        int i, j = 0, k, l, t;
        for (i = 0; i < nums.size();)
        {
            while (i < nums.size() && nums[i] == nums[j]) ++i;
            t = r.size();
            for (l = 0; l < t; ++l)
            {
                vector<int> v = r[l];
                for (k = 0; k < i - j; ++k)
                {
                    v.push_back(nums[j]);
                    r.push_back(v);
                }
            }
            j = i;
        }
        return r;
    }
};

int main()
{
}
