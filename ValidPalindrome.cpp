#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if (s == "") return true;
        int head = 0, tail = s.size() - 1;
        while(head < tail)
        {
            while(!(s[head] >= 'a' && s[head] <= 'z')
                  && !(s[head] >= 'A' && s[head] <= 'Z')
                  && !(s[head] >= '0' && s[head] <= '9') && head < tail)
                ++head;
            while(!(s[tail] >= 'a' && s[tail] <= 'z')
                  && !(s[tail] >= 'A' && s[tail] <= 'Z')
                  && !(s[tail] >= '0' && s[tail] <= '9') && head < tail)
                --tail;
            if (head >= tail) break;
            if (s[head] >= 'A' && s[head] <= 'Z') s[head] += 32;
            if (s[tail] >= 'A' && s[tail] <= 'Z') s[tail] += 32;
            if (s[head] != s[tail]) return false;
            ++head; --tail;
        }
        return true;
    }
};

int main()
{
    Solution s;
    string a = "abcba";
    cout<<a<<":"<<s.isPalindrome(a)<<endl;
    a = "A man, a plan, a canal: Panama";
    cout<<a<<":"<<s.isPalindrome(a)<<endl;
    a = "race a car";
    cout<<a<<":"<<s.isPalindrome(a)<<endl;
    a = "1a2";
    cout<<a<<":"<<s.isPalindrome(a)<<endl;
    a = "ab2a";
    cout<<a<<":"<<s.isPalindrome(a)<<endl;
}
