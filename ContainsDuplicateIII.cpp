#include <iostream>
#include <set>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int i;
        set<int> h;
        set<int>::iterator it;
        if (nums.size() < 2 || k <= 0) return false;
        for (i = 0; i < nums.size(); ++i)
        {
            if (h.size() > k) h.erase(nums[i - k - 1]);
            it = h.lower_bound(nums[i] - t);
            if (it != h.end() && fabs(*it - nums[i]) <= t) return true;
            h.insert(nums[i]);
        }
        return false;
    }
};

int main()
{
    vector<int> v;
    Solution s;
    v.push_back(4);
    v.push_back(2);
    cout<<s.containsNearbyAlmostDuplicate(v, 2, 1)<<endl;
    v.clear();
    v.push_back(1);
    v.push_back(3);
    v.push_back(1);
    cout<<s.containsNearbyAlmostDuplicate(v, 1, 1)<<endl;
}
