#include <iostream>

using namespace std;

class Solution {
public:
    void reverse(int nums[], int s, int e)
    {
        int i = s, j = e, t;
        while(i < j)
        {
            t = nums[i];
            nums[i] = nums[j];
            nums[j] = t;
            ++i, --j;
        }
    }
    
    void rotate(int nums[], int n, int k) {
        k = k % n;
        if (k < 0) k += n;
        else if (k == 0) return;
        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
    }
};

int main()
{
    int nums[] = {1,2,3,4,5,6,7};
    Solution s;
    int i;
    s.rotate(nums, 7, 3);
    for(i = 0; i < 7; ++i)
        cout<<nums[i]<<",";
    cout<<endl;
}
