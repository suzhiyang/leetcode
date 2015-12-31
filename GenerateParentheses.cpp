class Solution {
public:
    void generate(vector<string> &res, string &cur, int l, int r)
    {
        if (l == 0 && r == 0)
        {
            res.push_back(cur);
            return;
        }
        if (l > 0)
        {
            cur += '(';
            generate(res, cur, l - 1, r);
            cur.pop_back();
        }
        if (r > l)
        {
            cur += ')';
            generate(res, cur, l, r - 1);;
            cur.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string cur;
        generate(res, cur, n, n);
        return res;
    }
};
