class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> r(2, 0);
        int i, x = 0, n1 = 0, n2 = 0;
        for (i = 0; i < nums.size(); ++i)
            x = x ^ nums[i];
        x = x & (-x);
        for (i = 0; i < nums.size(); ++i)
        {
            if ((nums[i] & x) == 0) n1 = n1 ^ nums[i];
            else n2 = n2 ^ nums[i];
        }
        r[0] = n1; r[1] = n2;
        return r;
    }
};
