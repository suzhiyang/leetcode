#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int i, r = 0, mh, h;
        if (height.size() < 2) return 0;
        vector<int> lmax(height.size(), 0);
        mh = height[0]; lmax[0] = height[0];
        for (i = 1; i < height.size(); ++i)
        {
            lmax[i] = mh;
            mh = max(mh, height[i]);
        }
        mh = height.back();
        for (i = height.size() - 2; i >= 0; --i)
        {
            h = min(lmax[i], mh);
            if (h > height[i]) r += h - height[i];
            mh = max(mh, height[i]);
        }
        return r;
    }
};

int main()
{
    Solution s;
//    int a[] = {5,4,1,2};
    int a[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> v(a, a + sizeof(a) / sizeof(int));
    cout<<s.trap(v)<<endl;
}
