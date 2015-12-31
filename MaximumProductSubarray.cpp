class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int lmax = nums[0], lmin = nums[0], r = nums[0], i;
        for (i = 1; i < nums.size(); ++i)
        {
            if (nums[i] < 0) swap(lmax, lmin);
            lmax = max(nums[i], lmax * nums[i]);
            lmin = min(nums[i], lmin * nums[i]);
            r = max(r, lmax);
        }
        return r;
    }
};

// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int mp = nums[0], mn = nums[0], i, r = nums[0];
//         if (mp <= 0) mp = 1;
//         if (mn == 0) mn = 1;
//         for (i = 1; i < nums.size(); ++i)
//         {
//             if (nums[i] > 0)
//             {
//                 mp *= nums[i];
//                 mn *= nums[i];
//                 r = max(r, mp);
//                 r = max(r, mn);
//             }
//             else if (nums[i] < 0)
//             {
//                 mn *= nums[i];
//                 mp = 1;
//                 r = max(r, mn);
//             }
//             else
//             {
//                 r = max(r, 0);
//                 mp = 1;
//                 mn = 1;
//             }
//         }
//         mp = nums.back(); mn = nums.back();
//         if (mp <= 0) mp = 1;
//         if (mn == 0) mn = 1;
//         for (i = nums.size() - 2; i >= 0; --i)
//         {
//             if (nums[i] > 0)
//             {
//                 mp *= nums[i];
//                 mn *= nums[i];
//                 r = max(r, mp);
//                 r = max(r, mn);
//             }
//             else if (nums[i] < 0)
//             {
//                 mn *= nums[i];
//                 mp = 1;
//                 r = max(r, mn);
//             }
//             else
//             {
//                 r = max(r, 0);
//                 mp = 1;
//                 mn = 1;
//             }
//         }
//         return r;
//     }
// };
