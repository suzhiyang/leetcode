#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int> &num) {
        int left = 0, right = num.size() - 1, mid;
        while(left <= right)
        {
            if (num[left] <= num[right]) return num[left];
            mid = (left + right) / 2;
            if (num[mid] < num[right]) right = mid;
            else left = mid + 1;
        }
        return num[left];
    }
};

int main()
{
    Solution s;
    int a[] = {2, 4, 5, 6, 7, 0, 1};
//    int a[] = {4, 5, 6, 7, 0, 1, 2};
    vector<int> v(a, a + 7);
    cout<<s.findMin(v)<<endl;
}
