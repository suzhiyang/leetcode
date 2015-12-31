class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int r = 0, i, left, right;
        unordered_map<int, int> h;
        for (i = 0; i < nums.size(); ++i)
        {
            if (h.find(nums[i]) == h.end())
            {
                left = 0; right = 0;
                if (h.find(nums[i] - 1) != h.end()) left = h[nums[i] - 1];
                if (h.find(nums[i] + 1) != h.end()) right = h[nums[i] + 1];
                h[nums[i]] = left + right + 1;
                r = max(r, h[nums[i]]);

                h[nums[i] - left] = h[nums[i]];
                h[nums[i] + right] = h[nums[i]];
            }
        }
        return r;
    }
};
