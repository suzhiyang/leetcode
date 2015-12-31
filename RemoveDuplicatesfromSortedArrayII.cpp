class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 2;
        if (nums.size() <= k) return nums.size();
        int i = 0, j = 0, c = 1;
        for (j = 1 ; j < nums.size(); ++j)
        {
            if (nums[j] == nums[j - 1])
            {
                if (c++ < k) nums[i++] = nums[j];
            }
            else
            {
                c = 1;
                nums[i++] = nums[j];
            }
        }
        return i;
    }
};
