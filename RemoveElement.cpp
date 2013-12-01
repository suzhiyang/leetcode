#include <iostream>

using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int currentpos = 0, i;
        for(i = 0; i < n; ++i)
        {
            if (A[i] != elem) A[currentpos++] = A[i];
        }
        return currentpos;
    }
};

int main()
{
    int a[] = {2,1,5,2,3}, len;
    Solution s;
    len = s.removeElement(a, 5, 2);
    for(int i = 0; i < len; ++i)
        cout<<a[i]<<",";
    cout<<endl;
}
