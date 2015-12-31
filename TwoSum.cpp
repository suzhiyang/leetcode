#include <iostream>
#include <vector>

using namespace std;

bool comp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.first < b.first;
}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res(2, 0);
        vector<pair<int, int> > n;
        for (int i = 0; i < nums.size(); ++i)
            n.push_back(make_pair(nums[i], i + 1));
        sort(n.begin(), n.end(), comp);
        int t, l = 0, r = nums.size() - 1;
        while(true)
        {
            t = n[l].first + n[r].first;
            if (t == target) break;
            else if (t > target) --r;
            else ++l;
        }
        res[0] = n[l].second; res[1] = n[r].second;
        if (res[0] > res[1]) swap(res[0], res[1]);
        return res;
    }
};

int main()
{
}
