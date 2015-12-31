#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        string r(num1.size() + num2.size(), '0');
        int i, j, cy, t;
        for (i = num1.size() - 1; i >= 0; --i)
        {
            cy = 0;
            for (j = num2.size() - 1; j >= 0; --j)
            {
                t = r[i + j + 1] - '0' + (num1[i] - '0') * (num2[j] - '0') + cy;
                r[i + j + 1] = t % 10 + '0';
                cy = t / 10;
            }
            r[i] += cy;
        }
        size_t pos = r.find_first_not_of("0");
        if (pos == string::npos) return "0";
        return r.substr(pos);
    }
};

int main()
{
    string a, b;
    Solution s;
    a = "123"; b = "12";
    cout<<s.multiply(a, b)<<endl;
}
