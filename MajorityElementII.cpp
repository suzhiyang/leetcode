class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int can1 = 0, can2 = 0, c1 = 0, c2 = 0, i;
        vector<int> r;
        for (i = 0; i < nums.size(); ++i)
        {
            if (c1 == 0)
                can1 = nums[i];
            else if (c2 == 0)
                can2 = nums[i];
            if (nums[i] == can1) ++c1;
            else if (nums[i] == can2) ++c2;
            else --c1, --c2;
        }
        if (c1 > 0)
        {
            c1 = 0;
            for (i = 0; i < nums.size(); ++i)
                if (nums[i] == can1) ++c1;
            if (c1 > nums.size() / 3) r.push_back(can1);
        }
        if (c2 > 0)
        {
            c2 = 0;
            for (i = 0; i < nums.size(); ++i)
                if (nums[i] == can2) ++c1;
            if (c2 > nums.size() / 3) r.push_back(can2);
        }
        return r;
    }
};
