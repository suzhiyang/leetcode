#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int i, l, r, mingap = INT_MAX, t, result = target;
        for(i = 0; i < num.size() - 2; ++i)
        {
            l = i + 1; r = num.size() - 1;
            while(l < r)
            {
                t = num[i] + num[l] + num[r];
                if (fabs(t - target) < mingap) {mingap = fabs(t - target), result = t;}
                if (t == target) return target;
                else if (t < target) ++l;
                else --r;
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
//    int a[] = {-1, 0, 1, 2, -1, -4};
    int a[] = {-1, 2, 1, -4};
    vector<int> num(a, a + sizeof(a) / sizeof(int));
    int r = s.threeSumClosest(num, 1);
    cout<<r<<endl;
}
