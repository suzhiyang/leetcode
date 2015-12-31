#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        if (nums.size() < 3) return res;
        sort(nums.begin(), nums.end());
        int l, r, i;
        for (i = 0; i < nums.size() - 2; ++i)
        {
            l = i + 1; r = nums.size() - 1;
            while(l < r)
            {
                if (nums[l] + nums[r] == -nums[i])
                {
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[l]);
                    v.push_back(nums[r]);
                    res.push_back(v);
                    ++l;
                    while(l < r && nums[l - 1] == nums[l]) ++l;
                    --r;
                    while(l < r && nums[r + 1] == nums[r]) --r;
                }
                else if (nums[l] + nums[r] < -nums[i]) ++l;
                else --r;
            }
            while(nums[i] == nums[i + 1]) ++i;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    int a[] = {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
    vector<int> v(a, a + sizeof(a) / sizeof(int));
    vector<vector<int> > r = sol.threeSum(v);
    for (int i = 0; i < r.size(); ++i)
        cout<<r[i][0]<<" "<<r[i][1]<<" "<<r[i][2]<<endl;
}
