#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

struct mycomp
{
    bool operator() (const string &str1, const string &str2)
    {
        return (str1 + str2) > (str2 + str1);
//         int i = 0;
//         while(i < str1.size() && i < str2.size() && str1[i] == str2[i])
//             ++i;
//         if (str1.size() == str2.size())
//         {
//             return str1[i] > str2[i];
//         }
//         else if (str1.size() < str2.size())
//         {
//             if (i == str1.size())
//             {
//                 if (str2[0] < str2[i]) return str1[i - 1] > str2[i];
//                 else return str1[i - 1] < str2[i];
//             }
//             else return str1[i] > str2[i];
//         }
//         else
//         {
//             if (i == str2.size())
//             {
//                 if (str1[0] < str1[i]) return str1[i] > str2[i - 1];
//                 else return str1[i] < str2[i - 1];
//             }
//             else return str1[i] > str2[i];
//         }
    }
};

class Solution {
public:
    string largestNumber(vector<int> &num) {
        vector<string> vstr;
        int i;
        for (i = 0; i < num.size(); ++i)
        {
            stringstream ss;
            string str;
            ss<<num[i];
            ss>>str;
            vstr.push_back(str);
        }
        sort(vstr.begin(), vstr.end(), mycomp());
        string r;
        for (i = 0; i < vstr.size(); ++i)
        {
            cout<<vstr[i]<<endl;
            r += vstr[i];
        }
        // Trailing zeros
        for (i = 0 ; i < r.size(); ++i)
            if (r[i] > '0') break;
        if (i == r.size()) r = "0";
        else r = r.substr(i);
        return r;
    }
};

int main()
{
    int a[] = {3, 30, 34, 5, 9};
//    int a[] = {33, 35, 32, 5, 9};
//    int a[] = {0, 0, 0, 0, 1};
//    int a[] = {84, 847};
//    int a[] = {8347, 834};
    vector<int> v(a, a + sizeof(a) / sizeof(a[0]));
    Solution s;
    cout<<s.largestNumber(v)<<endl;
}
