class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i, n = nums.size();
        int slow = nums[n - 1], fast = nums[nums[nums[n - 1] - 1] - 1];
        while(slow != fast)
        {
            slow = nums[slow - 1];
            fast = nums[nums[fast - 1] - 1];
        }
        slow = nums[n - 1];
        while(slow != fast)
        {
            slow = nums[slow - 1];
            fast = nums[fast - 1];
        }
        return slow;
    }
};

// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         int cnt, l = 1, r = nums.size() - 1, mid, i;
//         while(l < r)
//         {
//             mid = l + (r - l ) / 2;
//             cnt = 0;
//             for (i = 0; i < nums.size(); ++i)
//                 if (nums[i] <= mid) ++cnt;
//             if (cnt <= mid) l = mid + 1;
//             else r = mid;
//         }
//         return nums[r];
//     }
// };
