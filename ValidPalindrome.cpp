#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            while(i < j && !isalnum(s[i])) ++i;
            while(i < j && !isalnum(s[j])) --j;
            if (i < j && toupper(s[i++]) != toupper(s[j--])) return false;
        }
        return true;
    }
};

// class Solution {
// public:
//     bool isalphanum(char c)
//     {
//         if (c >= '0' && c <= '9') return true;
//         if (c >= 'a' && c <= 'z') return true;
//         if (c >= 'A' && c <= 'Z') return true;
//         return false;
//     }
    
//     bool isPalindrome(string s) {
//         int i = 0, j = s.size() - 1;
//         while(i < j)
//         {
//             if (!isalphanum(s[i])) {++i; continue;}
//             if (!isalphanum(s[j])) {--j; continue;}
//             if (s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
//             if (s[j] >= 'A' && s[j] <= 'Z') s[j] += 32;
//             if (s[i++] != s[j--]) return false;
//         }
//         return true;
//     }
// };

int main()
{
    cout<<Solution().isPalindrome("ab2a")<<endl;
}
