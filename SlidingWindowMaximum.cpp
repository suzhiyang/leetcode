#include <vector>
#include <iostream>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i = 0, t;
        vector<int> r;
        if (nums.size() == 0) return r;
        deque<int> dq;
        for (i = 0; i < k; ++i)
        {
            while (!dq.empty() && nums[i] > dq.back()) dq.pop_back();
            dq.push_back(nums[i]);
        }
        r.push_back(dq.front());
        for (; i < nums.size(); ++i)
        {
            if (nums[i - k] == dq.front()) dq.pop_front();
            while (!dq.empty() && nums[i] > dq.back()) dq.pop_back();
            dq.push_back(nums[i]);
            r.push_back(dq.front());
        }
        return r;
    }
};

int main()
{
    int a[] = {1,3,-1,-3,5,3,6,7};
    Solution s;
    vector<int> v(a, a + 8);
    vector<int> r = s.maxSlidingWindow(v, 3);
    for (int i = 0; i < r.size(); ++i)
        cout<<r[i]<<" ";
    cout<<endl;
}
