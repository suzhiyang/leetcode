#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    void add(string &num1, string &num2) // result is returned by num1
    {
        int cy = 0, t, i;
        for(i = num1.size() - 1; i >= 0; --i)
        {
            t = (num1[i] - '0') + (num2[i] - '0') + cy;
            num1[i] = t % 10 + '0';
            cy = t / 10;
        }
    }
    
    void lshiftn(string &str, int n) // left shift str by n-bit
    {
        int i;
        for(i = 0; i < str.size() - n; ++i)
            str[i] = str[i + n];
        for(; i < str.size(); ++i)
            str[i] = '0';
    }
    
    string multiply(string num1, string num2) {
        // padding 0 by max(size)
        int l1 = num1.size(), l2 = num2.size(), l, i, j;
        if (l1 > l2) l = l1;
        else l = l2;
//////// The comment code below is wrong as num.size() changing in the loop body
//         for(i = 0; i < l - num1.size(); ++i)
//             num1 = '0' + num1;
//         for(i = 0; i < l - num2.size(); ++i)
//             num2 = '0' + num2;
        for(i = 0; i < l - l1; ++i)
            num1 = '0' + num1;
        for(i = 0; i < l - l2; ++i)
            num2 = '0' + num2;
        // padding the results by 2 * max(size)
        string result(l * 2, '0'), c(l * 2, '0');
        for(i = l - 1; i >= 0; --i)
        {
            c.assign(l * 2, '0');
            int cy = 0, t, p = c.size() - 1;
            for(j = l - 1; j >= 0; --j)
            {
                t = (num1[j] - '0') * (num2[i] - '0') + cy;
                c[p--] = t % 10 + '0';
                cy = t / 10;
            }
            c[p] = cy + '0';
            lshiftn(c, l - 1 - i);
            add(result, c);
        }
        // trim 0s
        for(i = 0; i < result.size(); ++i)
            if (result[i] != '0') break;
        result = result.substr(i);
        if (result == "") result = '0';
        return result;
    }
};

int main()
{
    Solution s;
    string num1, num2;
    num1 = "1231";
    num2 = "459";
    cout<<num1<<" * "<<num2<<" = "<<s.multiply(num1, num2)<<endl;
    cout<<"================================"<<endl;
    num1 = "93133";
    num2 = "0";
    cout<<num1<<" * "<<num2<<" = "<<s.multiply(num1, num2)<<endl;
    cout<<"================================"<<endl;
    num1 = "0";
    num2 = "232";
    cout<<num1<<" * "<<num2<<" = "<<s.multiply(num1, num2)<<endl;
    cout<<"================================"<<endl;
    num1 = "931";
    num2 = "12312333";
    cout<<num1<<" * "<<num2<<" = "<<s.multiply(num1, num2)<<endl;
}
