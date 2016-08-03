#ifndef DS_H
#define DS_H
#include <iostream>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printlist(ListNode *head)
{
    ListNode *p = head;
    while(p != NULL)
    {
        cout<<p->val<<"->";
        p = p->next;
    }
    cout<<endl;
}

void printinorder(TreeNode *root)
{
    if (root == NULL) return;
    printinorder(root->left);
    cout<<root->val<<",";
    printinorder(root->right);
}

string to_string(int n)
{
    stringstream ss;
    ss<<n;
    return ss.str();
}

#endif
