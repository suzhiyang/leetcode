class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int r = nums[0], i;
        for (i = 1; i < nums.size(); ++i)
            r ^= nums[i];
        return r;
    }
};
