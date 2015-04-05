#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > result;
        if (num.size() < 3) return result;
        sort(num.begin(), num.end());
        int i, l, r, target;
        for(i = 0; i < num.size() - 2; ++i)
        {
            target = - num[i];
            l = i + 1; r = num.size() - 1;
            while(l < r)
            {
                if (num[l] + num[r] == target)
                {
                    vector<int> v;
                    v.push_back(num[i]); v.push_back(num[l]); v.push_back(num[r]);
                    result.push_back(v);
                    while(l < num.size() - 1 && num[l] == num[l + 1]) ++l;
                    while(r > l && num[r] == num[r - 1]) --r;
                    ++l; --r;
                }
                else if (num[l] + num[r] < target) ++l;
                else --r;
            }
            while(num[i] == num[i + 1]) ++i;
        }
        return result;
    }
};

int main()
{
    Solution s;
    int a[] = {-1, 0, 1, 2, -1, -4};
    vector<int> num(a, a + sizeof(a) / sizeof(int));
    vector<vector<int> > r = s.threeSum(num);
    int i, j;
    for(i = 0; i < r.size(); ++i)
    {
        for(j = 0; j < r[i].size(); ++j)
            cout<<r[i][j]<<",";
        cout<<endl;
    }
}
