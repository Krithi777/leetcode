/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool issym(TreeNode* s,TreeNode* t)
    {
        if(t==NULL || s==NULL)
          return s==t;
        if(t==NULL && s==NULL)
          return true;
        return (s->val==t->val) && issym(s->left,t->right) && issym(s->right,t->left);
    }
    bool isSymmetric(TreeNode* root) {
        return issym(root->left,root->right);
    }
};