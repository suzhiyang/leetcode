class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int e = nums[0], i, cnt = 1;
        for (i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == e)
                ++cnt;
            else
            {
                if (cnt > 1) --cnt;
                else e = nums[i];
            }
        }
        return e;
    }
};
