#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Mergesort is not work, 2-dimention DP
        if (s1.size() + s2.size() != s3.size()) return false;
        vector<vector<int> > m;
        int i, j;
        for (i = 0; i < s1.size() + 1; ++i)
        {
            m.push_back(vector<int>(s2.size() + 1));
        }
        m[0][0] = 1;
        for (i = 1; i < s1.size() + 1; ++i)
        {
            if (s3[i - 1] == s1[i - 1]) m[i][0] = m[i - 1][0];
            else m[i][0] = 0;
        }
        for (j = 1; j < s2.size() + 1; ++j)
        {
            if (s3[j - 1] == s2[j - 1]) m[0][j] = m[0][j - 1];
            else m[0][j] = 0;
        }
        for (i = 1; i < s1.size() + 1; ++i)
        {
            for (j = 1; j < s2.size() + 1; ++j)
            {
                if (s3[i + j - 1] == s1[i - 1]) m[i][j] |= m[i - 1][j];
                if (s3[i + j - 1] == s2[j - 1]) m[i][j] |= m[i][j - 1];
            }
        }
        return m[s1.size()][s2.size()];
    }
};

int main()
{
    Solution s;
    string s1 = "aabcc", s2 = "dbbca", s3;
    s3 = "aadbbcbcac";
    cout<<s.isInterleave(s1, s2, s3)<<endl;
    s3 = "aadbbbaccc";
    cout<<s.isInterleave(s1, s2, s3)<<endl;
    s1 = "a";
    s2 = "bd";
    s3 = "bad";
    cout<<s.isInterleave(s1, s2, s3)<<endl;
}
