#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows < 2) return s;
        int z = 2 * nRows - 2;
        int col = s.size() / z + 1;
        string r;
        int i, j;
        for (i = 0; i < nRows; ++i)
        {
            for (j = 0; j < col; ++j)
            {
                if (j * z + i < s.size()) r += s[j * z + i];
                if (i > 0 && i < nRows - 1)
                    if ((j + 1) * z - i < s.size()) r += s[(j + 1) * z - i];
            }
        }
        return r;
    }
};

int main()
{
    Solution s;
    string str;
    str = "PAYPALISHIRING";
    cout<<str<<endl<<s.convert(str, 1)<<endl<<"----------------"<<endl;
    cout<<str<<endl<<s.convert(str, 2)<<endl<<"----------------"<<endl;
    cout<<str<<endl<<s.convert(str, 3)<<endl<<"----------------"<<endl;
    cout<<str<<endl<<s.convert(str, 4)<<endl<<"----------------"<<endl;
}
