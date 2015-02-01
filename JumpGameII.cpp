#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(int A[], int n) {
        vector<int> v(n, 0);
        v[0] = 0;
        int i, j;
        for(i = 1; i < n; ++i)
        {
            v[i] = max(v[i - 1], A[i - 1]) - 1;
            cout<<v[i]<<" ";
//            if (v[i] < 0) return false;
        }
        cout<<endl;
        return v[n - 1];
    }
};

int main()
{
    int a[] = {2,3,1,1,4};
    int b[] = {3,2,1,0,4};
    Solution s;
    cout<<s.jump(a, 5)<<endl;
    cout<<s.jump(b, 5)<<endl;
}
