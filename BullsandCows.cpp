class Solution {
public:
    string getHint(string secret, string guess) {
        int h[10] = {0}, g[10] = {0}, i, a = 0, b = 0;
        for (i = 0; i < secret.size(); ++i)
        {
            if (secret[i] == guess[i]) ++a;
            else ++h[secret[i] - '0'], ++g[guess[i] - '0'];
        }
        for (i = 0; i < 10; ++i)
            b += min(h[i], g[i]);
        stringstream ss;
        ss<<a<<"A"<<b<<"B";
        return ss.str();
    }
};
