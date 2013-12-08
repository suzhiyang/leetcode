#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int c, i, t;
        vector<int> r(digits);
        r[r.size() - 1] = digits[r.size() - 1] + 1;
        if (r[r.size() - 1] == 10)
        {
            r[r.size() - 1] = 0;
            c = 1;
            for (i = digits.size() - 2; i >= 0; --i)
            {
                r[i] = (digits[i] + c) % 10;
                c = (digits[i] + c) / 10;
                if (c == 0) break;
            }
            if (c == 1) r.insert(r.begin(), 1);
        }
        return r;
    }
};

int main()
{
    vector<int> digits(5, 9), r;
    Solution s;
    r = s.plusOne(digits);
    for (int i = 0; i < r.size(); ++i)
        cout<<r[i];
    cout<<endl;
}
