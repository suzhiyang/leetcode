class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int k, l, t;
        for (k = num.size() - 2; k >= 0; --k)
            if (num[k] < num[k + 1]) break;
        if (k < 0)
        {
            reverse(num.begin(), num.end());
            return;
        }
        for (l = num.size() - 1; l > k; --l)
            if (num[l] > num[k]) break;
        swap(num[l], num[k]);
        reverse(num.begin() + k + 1, num.end());
        return;
    }
};
