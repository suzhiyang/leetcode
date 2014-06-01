#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    vector<string> m_d;
public:
    Solution()
    {
        m_d.assign(12, "");
        m_d[2] = "abc";
        m_d[3] = "def";
        m_d[4] = "ghi";
        m_d[5] = "jkl";
        m_d[6] = "mno";
        m_d[7] = "pqrs";
        m_d[8] = "tuv";
        m_d[9] = "wxyz";
    }
    vector<string> letterCombinations(string digits) {
        int i, l;
        vector<string> r, t;
        if (digits == "")
        {
            r.push_back("");
            return r;
        }
        if (digits.size() == 1)
        {
            for(i = 0; i < m_d[digits[0] - '0'].size(); ++i)
                r.push_back(m_d[digits[0] - '0'].substr(i, 1));
            return r;
        }
        t = letterCombinations(digits.substr(1));
        l =  m_d[digits[0] - '0'].size();
        for(i = 0; i < l; ++i)
        {
            for(vector<string>::iterator it = t.begin(); it != t.end(); ++it)
            {
                r.push_back(m_d[digits[0] - '0'][i] + *it);
            }
        }
        return r;
    }
};

int main()
{
    Solution s;
    string digits;
    int i;
    vector<string> r;
    digits = "23";
    cout<<digits<<endl;
    r = s.letterCombinations(digits);
    for(i = 0;i < r.size(); ++i)
        cout<<r[i]<<endl;
    cout<<endl;
    cout<<"==================================="<<endl;
    digits = "235";
    cout<<digits<<endl;
    r = s.letterCombinations(digits);
    for(i = 0;i < r.size(); ++i)
        cout<<r[i]<<endl;
    cout<<endl;
    cout<<"==================================="<<endl;
}
