class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        vector<vector<string> > r;
        map<string, int> sig;
        int i;
        for (i = 0; i < strs.size(); ++i)
        {
            string t = strs[i];
            sort(t.begin(), t.end());
            if (sig.find(t) == sig.end())
            {
                sig[t] = r.size();
                r.push_back(vector<string>());
            }
            r[sig[t]].push_back(strs[i]);
        }
        for (i = 0; i < r.size(); ++i)
            sort(r[i].begin(), r[i].end());
        return r;
    }
};
