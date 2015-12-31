class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target){
        int res = 0, i, mgap = INT_MAX;
        sort(nums.begin(), nums.end());
        for (i = 0; i < nums.size() - 2; ++i)
        {
            int l = i + 1, r = nums.size() - 1;
            while(l < r)
            {
                int t = nums[i] + nums[l] + nums[r];
                if (fabs(t - target) < mgap)
                {
                    mgap = fabs(t - target);
                    res = t;
                }
                if (nums[l] + nums[r] == target - nums[i])
                    return target;
                else if (nums[l] + nums[r] < target - nums[i])
                    ++l;
                else --r;
            }
        }
        return res;
    }
};
