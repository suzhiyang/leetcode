class Solution {
public:
    int jump(int A[], int n) {
        int maxcover = 0, i, last = 0, step = 0;
        for (i = 0; i < n; ++i)
        {
             if (i > last)
             {
                 ++step;
                 last = maxcover;
             }
             maxcover = max(maxcover, A[i] + i);
        }
        return step;
    }
};
