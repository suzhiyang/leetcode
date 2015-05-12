class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int m = INT_MAX, l = 0, i, sum = 0;
        for (i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            while(sum - nums[l] >= s)
                sum -= nums[l++];
            if (sum >= s && i - l + 1 < m) m = i - l + 1;
        }
        if (sum < s) return 0;
        return m;
    }
};
