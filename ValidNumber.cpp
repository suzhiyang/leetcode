#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    bool isNumber(const char *s) {
        char str[1000];
        int len, i;
        // counter for special characters
        int ce = 0, cdot = 0, cnum = 0;
        // trim the leading spaces and tail spaces
        const char *p = s;
        while(*p != 0)
            if (*p == ' ') ++p;
            else break;
        len = 0;
        while(*p != 0)
        {
            // legal character set
            if (!((*p >= '0' && *p <= '9') || *p == ' ' || *p == '.' ||
                  *p == 'e' || *p == 'E' || *p == '+' || *p == '-'))
                return false;
            if (*p == 'e' || *p == 'E') ++ce;
            if (*p == '.') ++cdot;
            if (*p >= '0' && *p <= '9') ++cnum;
            if (*p == '+' || *p == '-')
            {
                if (!(len == 0 || ((*(p - 1) == 'e' || *(p - 1) == 'E')))) return false;
            }
            str[len++] = *p++;
        }
        if (cdot > 1 || ce > 1 || cnum == 0 || len == 0) return false;
        for(i = len - 1; i >=0; --i)
            if (str[i] != ' ') break;
        len = i + 1;
        str[i + 1] = 0;

        // legal: +/- xxx.xxx e/E +/- xxx
        // phase: 0    1 2 3   4   5   6
        int phase = 0;
        if (len == 1 && !(str[0] >= '0' && str[0] <= '9')) return false;
        if (str[len - 1] == 'e' || str[len - 1] == 'E') return false;
        for(i = 0; i < len; ++i)
        {
            char t = str[i];
            switch(phase)
            {
                case 0:
                    if ((t != '+' && t != '-' && t != '.' ) && !(t >= '0' && t <= '9')) return false;
                    if (t >= '0' && t <= '9') phase = 1;
                    if (t == '.') phase = 3;
                    break;
                case 1:
                    if (!(t >= '0' && t <= '9') && t != '.' && t != 'e' && t != 'E') return false;
                    if (t == '.') phase = 3;
                    if (t == 'e' || t == 'E') phase = 5;
                    break;
                case 3:
                    if (!(t >= '0' && t <= '9') && t != 'e' && t != 'E')
                        return false;
                    if (t == 'e' || t == 'E') phase = 5;
                    break;
                case 5:
                    if (t != '+' && t != '-' && !(t >= '0' && t <= '9')) return false;
                    if ((t == '+' || t == '-') && i == len - 1) return false;
                    if (t >= '0' && t <= '9') phase = 6;
                    break;
                case 6:
                    if (!(t >= '0' && t <= '9')) return false;
            }
        }
        // Check two char cannot appear continuously
        for (i = 0; i < len - 1; ++i)
        {
            if (str[i] != 'e' && str[i] != 'E' &&
                !(str[i] >= '0' && str[i] <= '9') &&
                !(str[i + 1] >= '0' && str[i + 1] <= '9'))
            {
                if (!(str[i] == '+' && str[i + 1] == '.') &&
                    !(str[i] == '-' && str[i + 1] == '.') &&
                    !(str[i] == '.' && str[i + 1] == 'e') &&
                    !(str[i] == '.' && str[i + 1] == 'E'))
                return false;
            }

            if (str[i] == '.')
            {
                if (i > 0 && !(str[i - 1] >= '0' && str[i - 1] <= '9') &&
                    !(str[i + 1] >= '0' && str[i + 1] <= '9'))
                    return false;
                if (i == 0 && !(str[i + 1] >= '0' && str[i + 1] <= '9'))
                    return false;
            }
        }
        
        return true;
    }
};

int main()
{
    map<string, bool> test;
    test.insert(make_pair("0", true));
    test.insert(make_pair("2e10", true));
    test.insert(make_pair(" 0.1", true));
    test.insert(make_pair("  -30.33E10", true));
    test.insert(make_pair("  -30.33e-10", true));
    test.insert(make_pair("abc", false));
    test.insert(make_pair("1 a", false));
    test.insert(make_pair(" +3sea", false));
    test.insert(make_pair(" +30.36e10.2", false));
    test.insert(make_pair(" -30.36 e10.2", false));
    test.insert(make_pair(" -30.36e10. ", false));
    test.insert(make_pair(" -3036e.10 ", false));
    test.insert(make_pair(" e ", false));
    test.insert(make_pair(" +", false));
    //////////////////////////////////////////
    test.insert(make_pair("   ", false));
    test.insert(make_pair("1  ", true));
    test.insert(make_pair(" .1  ", true));  // ambiguous
    test.insert(make_pair(" .  ", false));
    test.insert(make_pair(" 0e  ", false));
    test.insert(make_pair(" 3.  ", true));  // ?????????????????????
    test.insert(make_pair("46.e3", true));  // ?????????????????????
    test.insert(make_pair(" -.", false));
    test.insert(make_pair(" +.8", true));
    test.insert(make_pair("+0e-", false));
    test.insert(make_pair(".e1", false));
    test.insert(make_pair("005047e+6", true));
    
    Solution s;
    map<string, bool>::iterator it;
    s.isNumber("005047e+6");
    for (it = test.begin(); it != test.end(); ++it)
    {
        bool result = s.isNumber(it->first.c_str());
        cout<<it->first<<"   "<<it->second<<"  ";
        if (result == it->second)
            cout<<"Passed";
        cout<<endl;
    }
}
