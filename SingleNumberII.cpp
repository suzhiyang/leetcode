class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a[32], i, j, t, r = 0;
        memset(a, 0, sizeof(a));
        for (i = 0; i < nums.size(); ++i)
        {
            t = nums[i];
            for (j = 0; j < 32; ++j)
            {
                a[j] += t & 1;
                t = t >> 1;
            }
        }
        for (j = 31; j >= 0; --j)
        {
            r = r << 1;
            r = r | (a[j] % 3);
        }
        return r;
    }
};
