#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> v(nums.size(), 1);
        int i, r = 1;
        for (i = 1; i < nums.size(); ++i)
            v[i] = v[i - 1] * nums[i - 1];
        for (i = nums.size() - 2; i >= 0; --i)
        {
            r *= nums[i + 1];
            v[i] *= r;
        }
        return v;
    }
};

int main()
{
    int a[] = {1,2,3,4,5}, i;
    vector<int> v(a, a + 1);
    Solution s;
    vector<int> p = s.productExceptSelf(v);
    for (i = 0; i < p.size(); ++i)
        cout<<p[i]<<",";
    cout<<endl;
}
