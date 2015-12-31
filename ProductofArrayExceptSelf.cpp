#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> r(nums.size(), 1);
        int t = 1, i;
        for (i = 1; i < nums.size(); ++i)
        {
            t *= nums[i - 1];
            r[i] = t;
        }
        t = 1;
        for (i = nums.size() - 2; i >= 0; --i)
        {
            t *= nums[i + 1];
            r[i] *= t;
        }
        return r;
    }
};

int main()
{
    Solution s;
    vector<int> v(2, 0);
    vector<int> r = s.productExceptSelf(v);
    cout<<r[0]<<":"<<r[1]<<endl;
}
