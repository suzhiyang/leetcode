class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0, i, n = nums.size();
        for (i = 0; i < nums.size(); ++i)
            sum += nums[i];
        if (n % 2 == 0) n = n / 2 * (n + 1);
        else n = (n + 1) / 2 * n;
        return n - sum;
    }
};
