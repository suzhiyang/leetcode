#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


void dfs(vector<string> &r, string &cur, int index, int n)
{
    if (index == n)
    {
        r.push_back(cur);
        return;
    }
    int i, j;
    for (i = 1; i <= n; ++i)
    {
        bool exist = false;
        for (j = 0; j < cur.size(); ++j)
            if (cur[j] - '0' == i) {exist = true; break;}
        if (exist == false)
        {
            string next = cur + (char)(i + '0');
            dfs(r, next, index + 1, n);
        }
    }
}

void permutation(int n)
{
    vector<string> r;
    string cur;
    dfs(r, cur, 0, n);
    int i;
    cout<<r.size()<<endl;
    for (i = 0; i < r.size(); ++i)
    {
        cout<<i+1<<" "<<r[i]<<endl;
    }
}

class Solution {
public:
    int getn(int *a, int n)
    {
        int i, c = 0;
        for (i = 0; i < 10; ++i)
        {
            c += a[i];
            if (c > n) {a[i] = 0;return i + 1;}
        }
    }
    
    string getPermutation(int n, int k) {
        if (n == 1) return "1";
        int f[10], i, c, b;
        f[0] = 1;
        for (i = 1; i < 10; ++i)
            f[i] = f[i - 1] * i;
        string str;
        int a[10];
        for (i = 0; i < 10; ++i) a[i] = 1;
        --k;
        for (i = 1; i <= n; ++i)
        {
            c = k / f[n - i];
            k = k % f[n - i];
            b = getn(a, c);
//             cout<<c<<" "<<k<<" "<<b<<endl;
//             for (int j = 0; j < n; ++j) cout<<a[j]<<" ";
//             cout<<endl;
            str += (char)(b + '0');
        }
        return str;
    }
};

int main()
{
    Solution s;
//     cout<<s.getPermutation(2, 1)<<endl;
//     cout<<s.getPermutation(3, 1)<<endl;
//     cout<<s.getPermutation(3, 2)<<endl;
//     cout<<s.getPermutation(3, 3)<<endl;
//     cout<<s.getPermutation(3, 4)<<endl;
//     cout<<s.getPermutation(3, 5)<<endl;
//     cout<<s.getPermutation(3, 6)<<endl;
//     cout<<endl;
    cout<<s.getPermutation(4, 10)<<endl;
    cout<<s.getPermutation(4, 1)<<endl;
    cout<<s.getPermutation(4, 2)<<endl;
    cout<<s.getPermutation(4, 3)<<endl;
    cout<<s.getPermutation(4, 4)<<endl;
    cout<<s.getPermutation(4, 5)<<endl;
    cout<<s.getPermutation(4, 6)<<endl;
    cout<<s.getPermutation(4, 7)<<endl;
    cout<<s.getPermutation(9, 306490)<<endl;
//     cout<<s.getPermutation(9, 353955)<<endl;
//    permutation(3);
//    permutation(4);
}
