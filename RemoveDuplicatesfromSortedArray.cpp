class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 0, i;
        for (i = 0; i < nums.size();)
        {
            while(i < nums.size() && nums[l] == nums[i]) ++i;
            if (i < nums.size()) nums[++l] = nums[i];
        }
        return l + 1;
    }
};
