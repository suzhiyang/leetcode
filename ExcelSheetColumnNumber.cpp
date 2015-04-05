#include <iostream>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int c = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            c = c * 26 + s[i] - 'A' + 1;
        }
        return c;
    }
};

int main()
{
    Solution s;
    cout<<s.titleToNumber("AA")<<endl;
    cout<<s.titleToNumber("BA")<<endl;
    cout<<s.titleToNumber("AAB")<<endl;
}
