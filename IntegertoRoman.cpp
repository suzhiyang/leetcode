#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        int a[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string r;
        int t, i, j;
        for (i = 0; i < 13; ++i)
        {
            while(num >= a[i])
            {
                r += roman[i];
                num -= a[i];
            }
        }
        return r;
    }
};

int main()
{
    Solution sol;
    cout<<sol.intToRoman(1904)<<endl;
}
