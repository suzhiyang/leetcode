#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        const char *p = s;
        int count = 0, prespace = 0;
        while (*p != 0)
        {
            if (*p == ' ') prespace = 1;
            else
            {
                if (prespace == 1) count = 1;
                else ++count;
                prespace = 0;
            }
            ++p;
        }
        return count;
    }
};

int main()
{
    char str[] = "hello world";
    Solution s;
    cout<<s.lengthOfLastWord(str)<<endl;
    strcpy(str, "k ");
    cout<<s.lengthOfLastWord(str)<<endl;
}
