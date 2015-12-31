class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> r;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i >= k && dq.front() == nums[i - k]) dq.pop_front();
            while(!dq.empty() && nums[i] > dq.back()) dq.pop_back();
            dq.push_back(nums[i]);
            if (i >= k - 1) r.push_back(dq.front());
        }
        return r;
    }
};
