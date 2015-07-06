#include <vector>
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

class Solution {
public:
    string convert(int a, int b)
    {
        string r;
        char buf[200];
        sprintf(buf, "%d", a);
        r = r + string(buf);
        if (a != b)
        {
            sprintf(buf, "%d", b);
            r += "->" + string(buf);
        }
        return r;
    }

    vector<string> summaryRanges(vector<int>& nums) {
        int i, si = 0;
        vector<string> r;
        if (nums.size() == 0) return r;
        string s;
        for (i = 1; i < nums.size(); ++i)
        {
            if (nums[i] != nums[i - 1] + 1)
            {
                r.push_back(convert(nums[si], nums[i - 1]));
                si = i;
            }
        }
        r.push_back(convert(nums[si], nums[i - 1]));
        return r;
    }
};

int main()
{
    Solution sol;
    vector<int> v;
    vector<string> s;
    v.push_back(0);
    v.push_back(1);
    s = sol.summaryRanges(v);
    int i;
    for (i = 0; i < s.size(); ++i)
        cout<<s[i]<<endl;
}
