#include <vector>
#include <climits>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        int maxe = nums[0], mine = nums[0], i;
        for (i = 1; i < nums.size(); ++i)
        {
            maxe = max(maxe, nums[i]);
            mine = min(mine, nums[i]);
        }
        if (maxe == mine) return 0;
        int l = int(ceil(double((maxe - mine)) / (nums.size() - 1)));
        int s = (maxe - mine) / l + 1;
        vector<pair<int, int> > bucket(s, make_pair(INT_MAX, INT_MIN));
        for (i = 0; i < nums.size(); ++i)
        {
            int k = (nums[i] - mine) / l;
            bucket[k].first = min(bucket[k].first, nums[i]);
            bucket[k].second = max(bucket[k].second, nums[i]);
        }
        int r = 0, prev;
        for (prev = 0; prev < s; ++prev)
            if (bucket[prev].first != INT_MAX) break;
        for (i = prev + 1; i < s; ++i)
        {
            if (bucket[i].first != INT_MAX)
            {
                r = max(r, bucket[i].first - bucket[prev].second);
                prev = i;
            }
        }
        return r;
    }
};

int main()
{
    int a[] = {3, 30, 31, 45};
    int b[] = {1,1,1,1,1,5,5,5,5,5};
    vector<int> v(a + 2, a + 4);
    v.assign(b, b + 10);
    cout<<Solution().maximumGap(v)<<endl;
}
