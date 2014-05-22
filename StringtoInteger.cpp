#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int atoi(const char *str) {
        // Trim leading spaces first
        int r, sign = 0;
        char buf[100], *pn = buf;
        const char *p = str;
        while(*p != 0)
        {
            if (*p == '+' && sign == 0) sign = 1;
            else if (*p == '-' && sign == 0) sign = -1;
            else if (*p >= '0' && *p <= '9')
            {
                if (sign == 0) sign = 1;
                *pn++ = *p;
            }
            else if (*p != ' ' || (*p == ' ' &&  sign != 0)) break;
            ++p;
        }
        *pn = 0;
        pn = buf;
        r = 0;
        while(*pn != 0)
        {
            if (r > INT_MAX / 10 || (r == INT_MAX / 10 && *pn > '8'))
            {
                r = -1;
                break;
            }
            r = r * 10 + (*pn - '0');
            ++pn;
        }
        if (r < 0)
        {
            if (sign > 0) return INT_MAX;
            else return INT_MIN;
        }
        r *= sign;
        return r;
    }
};

int main()
{
    Solution s;
    string str;
    str = "   -232 ";
    cout<<s.atoi(str.c_str())<<endl;
    str = "   +  d829-+ ";
    cout<<s.atoi(str.c_str())<<endl;
    str = "   -  3 ";
    cout<<s.atoi(str.c_str())<<endl;
    str = "   -  0012d3 ";
    cout<<s.atoi(str.c_str())<<endl;
    str = "+1";
    cout<<s.atoi(str.c_str())<<endl;
    str = "  +0 123";
    cout<<s.atoi(str.c_str())<<endl;
    str = "2147483648";
    cout<<s.atoi(str.c_str())<<endl;
    str = "      -11919730356x";
    cout<<s.atoi(str.c_str())<<endl;
}
