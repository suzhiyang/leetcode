#include <iostream>
#include <string>
#include <vector>

using namespace std;

// class Solution {
// public:
//     vector<string> letterCombinations(string digits) {
//         string n[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
//         vector<string> r, sub;
//         int i, j;
//         if (digits.size() == 0) return r;
//         else if (digits.size() == 1)
//         {
//             for (i = 0; i < n[digits[0] - '0'].size(); ++i)
//             {
//                 string str(1, char(n[digits[0] - '0'][i]));
//                 r.push_back(str);
//             }
//             return r;
//         }
//         sub = letterCombinations(digits.substr(1));
//         for (i = 0; i < n[digits[0] - '0'].size(); ++i)
//             for (j = 0; j < sub.size(); ++j)
//                 r.push_back(char(n[digits[0] - '0'][i]) + sub[j]);
//         return r;
//     }
// };

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string n[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> r, t;
        if (digits.size() == 0) return r;
        r.push_back("");
        int i, j, k;
        for (i = 0; i < digits.size(); ++i)
        {
            vector<string> t;
            for (j = 0; j < n[digits[i] - '0'].size(); ++j)
                for (k = 0; k < r.size(); ++k)
                    t.push_back(r[k] + n[digits[i] - '0'][j]);
            r = t;
        }
        return r;
    }
};


int main()
{
    Solution s;
    vector<string> r = s.letterCombinations("23");
    for (int i = 0; i < r.size(); ++i)
        cout<<r[i]<<" ";
    cout<<endl;
}
