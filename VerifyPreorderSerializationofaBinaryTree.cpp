class Solution {
public:
    bool isValidSerialization(string preorder) {
        if (preorder.size() == 0) return false;
        stack<int> stk;
        int i, num = 0;
        for (i = 0; i < preorder.size(); ++i)
        {
            if (preorder[i] == '#')
            {
                if (stk.empty())
                {
                    if (i == preorder.size() - 1) return true;
                    else return false;
                }
                stk.pop();
            }
            else if (preorder[i] == ',')
            {
                if (preorder[i - 1] != '#')
                    stk.push(num);
                num = 0;
            }
            else
            {
                num = num * 10 + preorder[i] - '0';
            }
        }
        return false;
    }
};
