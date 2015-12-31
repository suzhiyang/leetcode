class Solution {
public:
    int maxProduct(vector<string>& words) {
        int r = 0, i, j;
        vector<int> fp(words.size(), 0);
        for (i = 0; i < words.size(); ++i)
        {
            for (j = 0; j < words[i].size(); ++j)
                fp[i] |= (1<<(words[i][j] - 'a'));
        }
        for (i = 0; i < words.size(); ++i)
        {
            for (j = i + 1; j < words.size(); ++j)
                if ((fp[i] & fp[j]) == 0)
                    r = max(r, int(words[i].size() * words[j].size()));
        }
        return r;
    }
};
