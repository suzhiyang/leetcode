class Solution {
public:
    string convertToTitle(int n) {
        string r;
        int i, t;
        while(n != 0)
        {
            t = n % 26;
            if (t == 0) {t = 26; n = n / 26 - 1;}
            else n = n / 26;
            r = char('A' + t - 1) + r;
        }
        return r;
    }
};
