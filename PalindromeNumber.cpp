#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x < 10) return true;
        int l = 1, m = 1, t = x;
        while(t >= 10)
        {
            t /= 10;
            m *= 10;
        }
        while(l < m)
        {
            if (x / l % 10 != x / m % 10) return false;
            l *= 10; m /= 10;
        }
        return true;
    }
};

int main()
{
    Solution s;
    cout<<s.isPalindrome(10021)<<endl;
    cout<<s.isPalindrome(121)<<endl;
    cout<<s.isPalindrome(1000000001)<<endl;
}
