#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        int d[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        char *r[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string roman;
        int t = num, i, n, j;
        for(i = 0; i < 13; ++i)
        {
            n = num / d[i];
            for(j = 0; j < n; ++j)
                roman += r[i];
            num -= n * d[i];
        }
        return roman;
    }
};

int main()
{
    Solution s;
    int a[] = {1, 3, 4, 100, 1904, 1954, 1990, 2014};
    for(int i = 0; i < sizeof(a) / 4; ++i)
//        cout<<a[i]<<" : "<<s.intToRoman(a[i])<<endl;
        cout<<"\""<<s.intToRoman(a[i])<<"\",";
}
