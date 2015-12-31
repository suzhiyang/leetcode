#include <string>
#include <cstring>
#include <iostream>
using namespace std;

class Solution {
public:
    int d[10000];
    
    int ways(string &s, int i)
    {
        if (d[i] >= 0) return d[i];
        if (i == s.size())
        {
            d[i] = 1;
        }
        else if (i == s.size() - 1)
        {
            if (s[i] == '0') d[i] = 0;
            else d[i] = 1;
        }
        else
        {
            int t = (s[i] - '0') * 10 + s[i + 1] - '0';
            if (t < 10) d[i] = 0;
            else if (t >= 10 && t <= 26)
                d[i] = ways(s, i + 1) + ways(s, i + 2);
            else d[i] = ways(s, i + 1);
        }
        return d[i];
    }
    
    int numDecodings(string s) {
        if (s == "") return 0;
        memset(d, -1, sizeof(d));
        return ways(s, 0);
    }
};

int main()
{
    Solution s;
    string str;
    str = "12";
    cout<<str<<":"<<s.numDecodings(str)<<endl;
    str = "1201";
    cout<<str<<":"<<s.numDecodings(str)<<endl;
    str = "213";
    cout<<str<<":"<<s.numDecodings(str)<<endl;
    str = "1213";
    cout<<str<<":"<<s.numDecodings(str)<<endl;
    str = "1513";
    cout<<str<<":"<<s.numDecodings(str)<<endl;
    str = "9371597631128776948387197132267188677349946742344217846154932859125134924241649584251978418763151253";
    cout<<str<<":"<<s.numDecodings(str)<<endl;
}
