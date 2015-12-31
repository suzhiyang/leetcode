#include <iostream>
#include <string>
using namespace std;

typedef long long ll;
class Solution {
public:
    ll tonum(string &s)
    {
        ll r = 0, i;
        for (i = 0; i < s.size(); ++i)
            r = r * 10 + s[i] - '0';
        return r;
    }

    bool check(string &a, string &b, string &c)
    {
//        cout<<a<<" + "<<b<<" "<<c<<endl;
        if (a.size() > 1 && a[0] == '0') return false;
        if (b.size() > 1 && b[0] == '0') return false;
        if (c.size() > 1 && c[0] == '0') return false;
        if (tonum(a) + tonum(b) != tonum(c)) return false;
//        cout<<"True "<<a<<" + "<<b<<" "<<c<<endl;;
        return true;
    }

    bool dfs(string a, string b, string &num, int pos)
    {
        int i;
        if (pos >= num.size()) return true;
        for (i = pos; i < num.size(); ++i)
        {
            string t = num.substr(pos, i - pos + 1);
            if (check(a, b, t))
            {
                if (dfs(b, t, num, i + 1)) return true;
            }
            if (num[pos] == '0') return false;
        }
        return false;
    }

    bool isAdditiveNumber(string num) {
        int i, j;
        for (i = 0; i < int(num.size()) - 2; ++i)
        {
            for (j = i + 1; j < num.size() - 1; ++j)
            {
                if (dfs(num.substr(0, i + 1), num.substr(i + 1, j - i), num, j + 1)) return true;
            }
        }
        return false;
    }
};

int main()
{
    cout<<Solution().isAdditiveNumber("0")<<endl;
    cout<<Solution().isAdditiveNumber("111")<<endl;
    cout<<Solution().isAdditiveNumber("1203")<<endl;
    cout<<Solution().isAdditiveNumber("1023")<<endl;
    cout<<Solution().isAdditiveNumber("0235813")<<endl;
    cout<<Solution().isAdditiveNumber("123")<<endl;
    cout<<Solution().isAdditiveNumber("01123")<<endl;
    cout<<Solution().isAdditiveNumber("10919")<<endl;
}
