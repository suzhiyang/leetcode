class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int l = 0, r = 0, m = INT_MAX, sum = 0;
        while(r < nums.size())
        {
            while(r < nums.size())
            {
                sum += nums[r];
                if (sum >= s) break;
                ++r;
            }
            while(l <= r)
            {
                if (sum - nums[l] < s) break;
                sum -= nums[l];
                ++l;
            }
            if (sum >= s) m = min(m, r - l + 1);
            ++r;
        }
        if (m == INT_MAX) return 0;
        return m;
    }
};
