#include <iostream>

using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int num = 0;
        for (int i = 0; i < n; ++i)
            num = num ^ A[i];
        return num;
    }
};

int main()
{
    int a[10] = {5,5,7,6,7};
    Solution s;
    cout<<s.singleNumber(a, 5)<<endl;
}
