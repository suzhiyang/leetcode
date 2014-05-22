#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if (*needle == NULL) return haystack;
        char *p = haystack, *pn, *ph;
        int hlen = strlen(haystack), nlen = strlen(needle);
        int left = hlen;
        while(*p != NULL)
        {
            if (left < nlen) break;
            ph = p;
            pn = needle;
            while(*ph != NULL && *pn != NULL)
            {
                if (*ph != *pn) break;
                ++ph; ++pn;
            }
            if (*pn == NULL) return p;
            ++p;
            --left;
        }
        return NULL;
    }
};

int main()
{
    Solution s;
//    char a[] = "what", b[] = "at";
//    char a[] = "aaa", b[] = "a";
//    char a[] = "", b[] = "";
    char a[] = "kjdfkjd", b[] = "a";
    char *p = s.strStr(a, b);
    if (p != NULL) cout<<p<<endl;
    else cout<<"NULL"<<endl;
}
