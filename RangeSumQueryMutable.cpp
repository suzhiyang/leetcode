#include <iostream>
#include <vector>
using namespace std;

struct SegNode
{
    SegNode *left, *right;
    int start, end, sum;
    SegNode(int s, int e): left(NULL), right(NULL),
                           start(s), end(e), sum(0) {}
};

class NumArray {
private:
    SegNode *m_root;
public:
    SegNode *build(int start, int end)
    {
        if (start > end) return NULL;
        int m = start + (end - start) / 2;
        SegNode *root = new SegNode(start, end);
        if (start == end) return root;
        root->left = build(start, m);
        root->right = build(m + 1, end);
        return root;
    }
    
    NumArray(vector<int> &nums) {
        m_root = build(0, nums.size() - 1);
        for (int i = 0; i < nums.size(); ++i)
            update(i, nums[i]);
    }

    void updatecore(SegNode *root, int i, int val)
    {
        if (root->start == i && root->end == i)
        {
            root->sum = val;
            return;
        }
        int m = root->start + (root->end - root->start) / 2;
        if (i <= m) updatecore(root->left, i, val);
        else updatecore(root->right, i, val);
        root->sum = root->left->sum + root->right->sum;
    }

    void update(int i, int val) {
        updatecore(m_root, i, val);
    }

    int sumcore(SegNode *root, int i, int j)
    {
        if (root->start == i && root->end == j) return root->sum;
        int m = root->start + (root->end - root->start) / 2;
        if (j <= m) return sumcore(root->left, i, j);
        else if (i > m) return sumcore(root->right, i, j);
        else return sumcore(root->left, i, m) + sumcore(root->right, m + 1, j);
    }

    int sumRange(int i, int j) {
        return sumcore(m_root, i, j);
    }
};

int main()
{
    int a[] = {1,3,5};
    vector<int> v(a, a + sizeof(a) / sizeof(int));
    NumArray na(v);
    cout<<na.sumRange(0, 2)<<endl;
    na.update(1,2);
    cout<<na.sumRange(0, 2)<<endl;
}
