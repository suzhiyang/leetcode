#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        int i = 0, st = 0, ed = 0, wordlen = 0, j;
        vector<string> r;
        string line;
        while(i < words.size())
        {
            wordlen = words[i].size();
            st = i++;
            for(; i < words.size(); ++i)
            {
                if (wordlen + i - st + words[i].size() <= L)
                    wordlen += words[i].size();
                else break;
            }
            line = words[st];
            if (i < words.size())
            {
                int wordnum = i - st, spaces = L - wordlen;
                if (wordnum == 1)
                {
                    for(j = line.size(); j < L; ++j)
                        line += " ";
                }
                else
                {
                    int gap, remain;
                    gap = spaces / (wordnum - 1);
                    remain = spaces % (wordnum - 1);
                    string sp;
                    for(j = 0; j < gap; ++j) sp += " ";
                    for(j = st + 1; j < i; ++j)
                    {
                        line = line + sp;
                        if (remain > 0)
                        {
                            line += " ";
                            --remain;
                        }
                        line += words[j];
                    }
                }
            }
            else
            {
                for(j = st + 1; j < words.size(); ++j)
                    line += " " + words[j];
                for(j = line.size(); j < L; ++j)
                    line += " ";
            }
            r.push_back(line);
        }
        return r;
    }
};

int main()
{
    char *a[] = {"This", "is", "an", "example", "of", "1234567812345678", "text", "justification."};
    Solution s;
    vector<string> words(a, a + sizeof(a) / sizeof(a[0]));
    s.fullJustify(words, 16);
}
