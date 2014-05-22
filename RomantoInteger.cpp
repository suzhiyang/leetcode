#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int d[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        char *r[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int num = 0, pos = 0, i;
        for(i = 0; i < 13; ++i)
        {
            int l = i % 2 + 1;
            while(pos + l <= s.size() && s.substr(pos, l) == string(r[i]))
            {
                pos += l;
                num += d[i];
            }
        }
        return num;
    }
};

int main()
{
    Solution s;
    char *r[] = {"I","III","IV","C","MCMIV","MCMLIV","MCMXC","MMXIV"};
    for(int i = 0; i < sizeof(r) / 8; ++i)
        cout<<r[i]<<" : "<<s.romanToInt(string(r[i]))<<endl;
}
