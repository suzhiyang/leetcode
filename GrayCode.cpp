#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 0) return vector<int>(1, 0);
        vector<int> r;
        r.push_back(0);
        r.push_back(1);
        int i = 0, j;
        for (i = 1; i < n; ++i)
        {
            int n = r.size();
            for (j = n - 1; j >= 0; --j)
                r.push_back(r[j]);
            int mask = 1<<i;
            for (j = n; j < 2 * n; ++j)
                r[j] |= mask;
        }
        return r;
    }
};

int main()
{
    Solution s;
    vector<int> r;
    r = s.grayCode(4);
    for (vector<int>::iterator it = r.begin(); it != r.end(); ++it)
        cout<<*it<<" ";
    cout<<endl;
}
