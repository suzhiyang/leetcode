class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int l) {
        vector<string> r;
        int i = 0, j, k;
        while(i < words.size())
        {
            vector<string> cur;
            int len = 0;
            while(i < words.size())
            {
                if (len + words[i].size() + cur.size() <= l)
                {
                    len += words[i].size();
                    cur.push_back(words[i]);
                    ++i;
                }
                else break;
            }
            string str(l, ' ');
            int spc = 1, rem = 0, pos = cur[0].size();
            for (k = 0; k < cur[0].size(); ++k)
                str[k] = cur[0][k];
            if (i < words.size() && cur.size() > 1)
                spc = (l - len) / (cur.size() - 1), rem = (l - len) % (cur.size() - 1);
            for (j = 1; j < cur.size(); ++j)
            {
                pos += spc;
                if (rem > 0) {++pos; --rem;}
                for (k = 0; k < cur[j].size(); ++k)
                    str[pos++] = cur[j][k];
            }
            r.push_back(str);
        }
        return r;
    }
};
