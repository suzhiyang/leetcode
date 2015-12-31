#include <iostream>
#include <list>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

class Solution {
public:
    list<int> l;
    int f[10];
    string core(int n, int k)
    {
        string r;
        if (n == 1) r = r + char(l.front() + '0');
        else
        {
            int c = (k - 1) / f[n - 1], t;
            list<int>::iterator it = l.begin();
            advance(it, c);
            t = *it;
            l.erase(it);
            r = r + char(t + '0') + core(n - 1, k - c * f[n - 1]);
        }
        return r;
    }
    
    string getPermutation(int n, int k) {
        int i;
        f[0] = 1;
        for (i = 1; i <= n; ++i)
        {
            f[i] = f[i - 1] * i;
            l.push_back(i);
        }
        return core(n, k);
    }
};

// class Solution {
// public:
//     int f[10], s[10];
//     string get(int n, int k)
//     {
//         int i, c, t;
//         string r;
//         if (n == 1)
//         {
//             for (i = 1; i <= 9; ++i)
//                 if (s[i]) {r = r + char(i + '0'); break;}
//         }
//         else
//         {
//             c = (k - 1) / f[n - 1];
//             t = 0;
//             for (i = 1; i <= 9; ++i)
//             {
//                 if (s[i]) ++t;
//                 if (t > c) break;
//             }
//             s[i] = 0;
//             r = r + char(i + '0') + get(n - 1, k - c * f[n - 1]);
//         }
//         return r;
//     }
    
//     string getPermutation(int n, int k) {
//         int i;
//         f[0] = 1;
//         memset(s, 0, sizeof(s));
//         for (i = 1; i <= n; ++i)
//         {
//             s[i] = 1;
//             f[i] = f[i - 1] * i;
//         }
//         return get(n, k);
//     }
// };

int main()
{
    int i;
    for (i = 1; i <= 6; ++i)
        cout<<Solution().getPermutation(3, i)<<endl;
}
