#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        vector<int> v(s.size(), 0);
        int i, r;
        v[s.size() - 1] = 1;
        for (i = s.size() - 2; i >= 0; --i)
        {
            if (s[i] == '0') v[i] = v[i + 1];
            else
            {
                if (s[i] == '1' || s[i] == '2')
                {
                    int n = (s[i] - '0') * 10 + (s[i + 1] - '0');
                    if (s[i + 1] == '0') v[i] = v[i + 1];
                    else if (n > 0 && n <= 26) v[i] = v[i + 1] + v[i + 2];
                }
                else v[i] = v[i + 1];
            }
        }
        return v[0];
    }
};

int numDecodings(string s);

int main()
{
    Solution s;
    string str = "1022";
    cout<<str<<":"<<s.numDecodings(str)<<":"<<numDecodings(str)<<endl;
    str = "12";
    cout<<str<<":"<<s.numDecodings(str)<<":"<<numDecodings(str)<<endl;
    str = "122";
    cout<<str<<":"<<s.numDecodings(str)<<":"<<numDecodings(str)<<endl;
    str = "12022";
    cout<<str<<":"<<s.numDecodings(str)<<":"<<numDecodings(str)<<endl;
    str = "120222";
    cout<<str<<":"<<s.numDecodings(str)<<":"<<numDecodings(str)<<endl;
    str = "4757562545844617494555774581341211511296816786586787755257741178599337186486723247528324612117156948";
    cout<<str<<":"<<s.numDecodings(str)<<":"<<numDecodings(str)<<endl;
    return 0;
}



//////////////////////////////////////////////
int numDecodings(string s) {
    int r = 0, r1 = 0, r2 = 0;
    string prestr;
    if (s == "" || s[0] == '0') return 0;
    if (s.size() == 1) return 1;
    else if (s.size() == 2)
    {
        int n = atoi(s.c_str());
        if (n >= 11 && n <= 19) return 2;
        else if (n >= 21 && n <= 26) return 2;
        else return 1;
    }
    r1 = numDecodings(s.substr(1));
    if (s[0] == '1' || s[0] == '2')
    {
        prestr = s.substr(0, 2);
        int n = atoi(prestr.c_str());
        if (n > 0 && n < 26) r2 = numDecodings(s.substr(2));
    }
    r = r1 + r2;
    return r;
}
