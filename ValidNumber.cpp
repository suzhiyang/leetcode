class Solution {
public:
    int numpos(string &s, int p)
    {
        int i;
        for (i = p; i < s.size(); ++i)
            if (s[i] < '0' || s[i] > '9') break;
        return i;
    }

    bool trailingspace(string &s, int p)
    {
        int i = p;
        while(i < s.size() && s[i] == ' ') ++i;
        if (i == s.size()) return true;
        return false;
    }
    
    bool isNumber(string s) {
        int i = 0, e;
        bool leastonenum = false;
        while(i < s.size() && s[i] == ' ') ++i;
        if (i == s.size()) return false;
        if (s[i] == '+' || s[i] == '-') ++i;
        if (i == s.size()) return false;
        if ((s[i] >= '0' && s[i] <= '9') || s[i] == '.')
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                leastonenum = true;
                i = numpos(s, i);
                if (i == s.size()) return true;
            }
            if (s[i] == '.' || s[i] == 'e' || s[i] == 'E')
            {
                if (s[i] == '.')
                {
                    ++i;
                    if (i == s.size()) return leastonenum;
                    else if (s[i] == ' ') return trailingspace(s, i) && leastonenum;
                    if (s[i] != 'e' && s[i] != 'E')
                    {
                        if (s[i] < '0' || s[i] > '9') return false;
                        leastonenum = true;
                        i = numpos(s, i);
                        if (i == s.size()) return true;
                    }
                }
                if (s[i] == 'e' || s[i] == 'E')
                {
                    ++i;
                    if (i == s.size()) return false;
                    if (s[i] == '+' || s[i] == '-')
                    {
                        ++i;
                        if (i == s.size()) return false;
                    }
                    if (s[i] < '0' || s[i] > '9') return false;
                    i = numpos(s, i);
                    if (i == s.size()) return leastonenum;
                    if (s[i] == ' ') return trailingspace(s, i) & leastonenum;
                    return false;
                }
                else if (s[i] == ' ') return trailingspace(s, i);
            }
            else if (s[i] == ' ') return trailingspace(s, i);
            return false;
        }
        else return false;
    }
};
