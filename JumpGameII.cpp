class Solution {
public:
    int jump(vector<int>& nums) {
        int maxreach = 0, curreach = 0, i, step = 0;
        for (i = 0; i < nums.size() - 1; ++i)
        {
            curreach = max(curreach, i + nums[i]);
            if (i == maxreach)
            {
                ++step;
                maxreach = curreach;
            }
        }
        return step;
    }
};
