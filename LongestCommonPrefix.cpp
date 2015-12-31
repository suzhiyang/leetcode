class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i, j, l = 0;
        if (strs.size() == 0) return "";
        for (i = 0; i < strs.size(); ++i)
            if (strs[i].size() < strs[l].size()) l = i;
        for (i = 0; i < strs[l].size(); ++i)
        {
            for (j = 0; j < strs.size(); ++j)
                if (strs[j][i] != strs[l][i]) break;
            if (j < strs.size()) break;
        }
        return strs[l].substr(0, i);
    }
};
