#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int> &num) {
        int left = 0, right = num.size() - 1, mid;
        while(left <= right)
        {
            mid = (left + right) / 2;
            if (num[mid] < num[right]) right = mid;
            else if (num[mid] > num[right]) left = mid + 1;
            else right -= 1;
        }
        return num[mid];
    }
};

int main()
{
    Solution s;
    int a[] = {2, 1, 1, 2, 2, 2, 2};
//    int a[] = {4, 5, 6, 7, 0, 1, 2};
    vector<int> v(a, a + 7);
    cout<<s.findMin(v)<<endl;
}
