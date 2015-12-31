#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > generate(vector<int> &nums, int index)
    {
        vector<vector<int> > r, sub;
        if (index == nums.size())
        {
            r.push_back(vector<int>());
        }
        else
        {
            sub = generate(nums, index + 1);
            r.insert(r.begin(), sub.begin(), sub.end());
            for (int i = 0 ; i < sub.size(); ++i)
                sub[i].insert(sub[i].begin(), nums[index]);
            r.insert(r.end(), sub.begin(), sub.end());
        }
        return r;
    }
    
    vector<vector<int> > subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return generate(nums, 0);
    }
};
