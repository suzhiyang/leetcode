class Solution {
public:
    int lengthOfLastWord(string s) {
        int r = 0, i;
        for (i = 0; i < s.size(); ++i)
            if (s[i] != ' ')
            {
                if (i > 0 && s[i - 1] == ' ') r = 1;
                else ++r;
            }
        return r;
    }
};
// class Solution {
// public:
//     int lengthOfLastWord(string s) {
//         int r = 0, i;
//         for (i = s.size() - 1; i >= 0; --i)
//             if (s[i] != ' ') break;
//         for (;i >= 0; --i)
//             if (s[i] == ' ') break;
//             else ++r;
//         return r;
//     }
// };
