#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int maxarea = 0, i, j, area;
        i = 0; j = height.size() - 1;
        while(i < j)
        {
            if (height[i] < height[j])
            {
                area = height[i] * (j - i);
                ++i;
            }
            else
            {
                area = height[j] * (j - i);
                --j;
            }
            if (area > maxarea) maxarea = area;
        }
        return maxarea;
    }
};

int main()
{
    int a[] = {2,1,3,1,5,4};
    vector<int> v(a, a + sizeof(a) / sizeof(a[0]));
    Solution s;
    cout<<s.maxArea(v)<<endl;
}
