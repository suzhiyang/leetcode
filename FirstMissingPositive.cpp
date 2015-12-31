class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i, t, n = nums.size();
        for (i = 0; i < n; ++i)
        {
            while(nums[i] != i + 1)
            {
                if (nums[i] <= 0 || nums[i] >= n) break;
                t = nums[nums[i] - 1];
                if (t == nums[i]) break;
                nums[nums[i] - 1] = nums[i];
                nums[i] = t;
            }
        }
        for (i = 0; i < n; ++i)
            if (nums[i] != i + 1) break;
        return i + 1;
    }
};

// class Solution {
// public:
//     int firstMissingPositive(vector<int>& nums) {
//         int i, t, j, n = nums.size();
//         for (i = 0; i < nums.size(); ++i)
//         {
//             j = nums[i];
//             while(j > 0 && j < n)
//             {
//                 t = nums[j];
//                 nums[j] = INT_MIN;
//                 j = t;
//             }
//         }
//         for (i = 1; i < nums.size(); ++i)
//             if (nums[i] != INT_MIN) break;
//         return i;
//     }
// };
