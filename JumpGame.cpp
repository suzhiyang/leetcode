class Solution {
public:
    bool canJump(vector<int>& nums) {
        int canreach = 0, i;
        for (i = 0; i < nums.size(); ++i)
        {
            if (i > canreach) return false;
            canreach = max(canreach, i + nums[i]);
        }
        if (canreach >= nums.size() - 1) return true;
        return false;
    }
};
