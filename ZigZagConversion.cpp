#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        int i, j, k = 2 * (numRows - 1);
        string r;
        for (i = 0; i < numRows; ++i)
        {
            for (j = 0; j < s.size() + k; j += k)
            {
                if (i == 0 || i == numRows - 1)
                {
                    if (j + i < s.size()) r += s[j + i];
                }
                else
                {
                    if (j - i >= 0 && j - i < s.size()) r += s[j - i];
                    if (j + i >= 0 && j + i < s.size()) r += s[j + i];
                }
            }
        }
        return r;
    }
};

int main()
{
    Solution s;
    string str = "AB";
    cout<<s.convert(str, 2)<<endl;
}
