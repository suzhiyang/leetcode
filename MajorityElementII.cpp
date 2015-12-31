class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1 = 0, c2 = 1 , cnt1 = 0, cnt2 = 0, i;
        for (i = 0; i < nums.size(); ++i)
        {
            if (c1 == nums[i]) ++cnt1;
            else if (c2 == nums[i]) ++cnt2;
            else if (cnt1 == 0) c1 = nums[i], cnt1 = 1;
            else if (cnt2 == 0) c2 = nums[i], cnt2 = 1;
            else --cnt1, --cnt2;
        }
        cnt1 = 0, cnt2 = 0;
        for (i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == c1) ++cnt1;
            else if (nums[i] == c2) ++cnt2;
        }
        vector<int> r;
        if (cnt1 > nums.size() / 3) r.push_back(c1);
        if (cnt2 > nums.size() / 3) r.push_back(c2);
        return r;
    }
};
