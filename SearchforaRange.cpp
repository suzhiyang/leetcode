class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int l = 0, r = nums.size() - 1, m;
        while(l <= r)
        {
            m = l + (r - l) / 2;
            if (nums[m] == target)
            {
                if (m == 0 || nums[m - 1] < target) {res[0] = m;break;}
                r = m - 1;
            }
            else if (nums[m] > target) r = m - 1;
            else l = m + 1;
        }
        if (res[0] == -1) return res;
        l = res[0], r = nums.size() - 1;
        while(l <= r)
        {
            m = l + (r - l) / 2;
            if (nums[m] == target)
            {
                if (m == nums.size() - 1 || nums[m + 1] > target) {res[1] = m;break;}
                l = m + 1;
            }
            else if (nums[m] > target) r = m - 1;
            else l = m + 1;
        }
        return res;
    }
};
