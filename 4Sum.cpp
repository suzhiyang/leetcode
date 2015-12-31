#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > res;
        if (nums.size() < 4) return res;
        int i, j, l, r, t, tmp;
        sort(nums.begin(), nums.end());
        for (i = 0; i < nums.size() - 3;)
        {
            for (j = i + 1; j < nums.size() - 2;)
            {
                l = j + 1; r = nums.size() - 1;
                while(l < r)
                {
                    t = target - nums[i] - nums[j];
                    if (nums[l] + nums[r] == t)
                    {
                        vector<int> v(4, 0);
                        v[0] = nums[i], v[1] = nums[j], v[2] = nums[l], v[3] = nums[r];
                        res.push_back(v);
                        while (l < r && nums[l] == v[2]) ++l;
                        while (l < r && nums[r] == v[3]) --r;
                    }
                    else if (nums[l] + nums[r] < t) ++l;
                    else --r;
                }
                tmp = nums[j];
                while (j < nums.size() - 2 && nums[j] == tmp) ++j;
            }
            tmp = nums[i];
            while (i < nums.size() - 3 && nums[i] == tmp) ++i;
        }
        return res;
    }
};
