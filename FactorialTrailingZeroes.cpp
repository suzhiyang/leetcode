#include <iostream>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int i = n, n5 = 0;
        while(i != 0)
        {
            i /= 5;
            n5 += i;
        }
        return n5;
    }
};

int main()
{
    Solution s;
    cout<<s.trailingZeroes(3)<<endl;
    cout<<s.trailingZeroes(5)<<endl;
    cout<<s.trailingZeroes(15)<<endl;
    cout<<s.trailingZeroes(25)<<endl;
    cout<<s.trailingZeroes(50)<<endl;
}
