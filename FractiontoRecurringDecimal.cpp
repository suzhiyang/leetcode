#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    string itos(long long a)
    {
        string r;
        long long t;
        if (a == 0) return string("0");
        while(a != 0)
        {
            t = a % 10;
            r = char(t + '0') + r;
            a /= 10;
        }
        return r;
    }
    
    string fractionToDecimal(int numerator, int denominator) {
        string str;
        int s1 = 1, s2 = 1, s;
        long long n = numerator, d = denominator, r, i;
        if (n < 0) {s1 = -1; n = -n;}
        if (d < 0) {s2 = -1; d = -d;}
        s = s1 * s2;
        vector<int> v;
        long long ipart = n / d;
        n = n % d;
        str = itos(ipart);
        if (n == 0) {if (ipart == 0) return "0"; if (s > 0) return str; return "-" + str;}// else n < d
        map<int, int> rm; // remainder map
        map<int, int>::iterator it;
        while(n != 0)
        {
            i = n / d;
            r = n % d;
            n = r * 10;
            it = rm.find(r);
            v.push_back(i);
            if (it == rm.end())
                rm[r] = v.size() - 1;
            else break;
        }
        str += ".";
        if (it != rm.end())
        {
            for(i = 1; i <= it->second; ++i)
                str += char(v[i] + '0');
            str += "(";
            for(; i < v.size(); ++i)
                str += char(v[i] + '0');
            str += ")";
        }
        else
        {
            for(i = 1; i < v.size(); ++i)
                str += char(v[i] + '0');
        }
        if (s == -1) str = "-" + str;
        return str;
    }
};

int main()
{
    Solution s;
    cout<<s.fractionToDecimal(14, 7)<<endl;
    cout<<s.fractionToDecimal(14, 21)<<endl;
    cout<<s.fractionToDecimal(1, 2)<<endl;
    cout<<s.fractionToDecimal(7, 3)<<endl;
    cout<<s.fractionToDecimal(1, 7)<<endl;
    cout<<s.fractionToDecimal(53, 21)<<endl;
    cout<<s.fractionToDecimal(53, -21)<<endl;
    cout<<s.fractionToDecimal(1, 2147483648)<<endl;
    cout<<s.fractionToDecimal(-1, -2147483648)<<endl;
    cout<<s.fractionToDecimal(-2147483648, 1)<<endl;
    cout<<s.fractionToDecimal(1, 6)<<endl;
}
