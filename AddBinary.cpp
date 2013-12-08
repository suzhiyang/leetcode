#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int i;
        string r;
        if (a.size() < b.size())
        {
            for (i = 0; i < b.size() - a.size(); ++i)
                r += "0";
            a = r + a;
        }
        else
        {
            for (i = 0; i < a.size() - b.size(); ++i)
                r += "0";
            b = r + b;
        }
        r = "";
        int t, c = 0;
        for (i = a.size() - 1; i >= 0; --i)
        {
            t = a[i] - '0' + b[i] - '0' + c;
            if (t == 0) {r = "0" + r; c = 0;}
            else if (t == 1) {r = "1" + r; c = 0;}
            else if (t == 2) {r = "0" + r; c = 1;}
            else {r = "1" + r; c = 1;}
        }
        if (c == 1) r = "1" + r;
        return r;
    }
};

int main()
{
    string a = "110", b = "10110";
    Solution s;
    cout<<s.addBinary(a,b)<<endl;
    cout<<s.addBinary("11","1")<<endl;
}
