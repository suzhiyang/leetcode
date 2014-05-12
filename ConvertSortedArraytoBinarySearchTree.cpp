#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if (num.size() == 0) return NULL;
        return convert(num, 0, num.size() - 1);
    }

    TreeNode *convert(vector<int> &v, int st, int ed)
    {
        TreeNode *node;
        int mid = (st + ed) / 2;
        node = new TreeNode(v[mid]);
        if (mid > st) node->left = convert(v, st, mid - 1);
        if (mid < ed) node->right = convert(v, mid + 1, ed);
        return node;
    }
};

int main()
{
}
