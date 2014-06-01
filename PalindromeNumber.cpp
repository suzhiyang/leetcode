#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        int len, i, j, a[20];
        if (x < 0) return false;
        len = int(log10(x));
        a[0] = 1;
        for(i = 1; i <= len; ++i)
            a[i] = a[i - 1] * 10;
        i = 0; j = len;
        while(i < j)
        {
            int m, n;
            m = x / a[i++] % 10;
            n = x / a[j--] % 10;
            if (m != n) return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    int a = 12345;
    cout<<a<<" "<<s.isPalindrome(a)<<endl;
    a = 5;
    cout<<a<<" "<<s.isPalindrome(a)<<endl;
    a = 12321;
    cout<<a<<" "<<s.isPalindrome(a)<<endl;
    a = 123321;
    cout<<a<<" "<<s.isPalindrome(a)<<endl;
    a = -2147483648;
    cout<<a<<" "<<s.isPalindrome(a)<<endl;
    a = -2147447412;
    cout<<a<<" "<<s.isPalindrome(a)<<endl;
}
